#include <Analysis.h>
using namespace std;
std::any Analysis::visitProgram(CactParser::ProgramContext *context) {
    visitCompUnit(context->compUnit());
    return llvmmodule.toString();
}
std::any Analysis::visitCompUnit(CactParser::CompUnitContext *context) {
    currentSymbolTable = new SymbolTable(nullptr);
    isGlobal = true;
    addBuiltinFunc();
    visitChildren(context);
    // check if the main function is defined
    if (!currentSymbolTable->lookup("main", true /*is function*/).first) {
        std::cerr << "Error: main function not defined!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}
std::any Analysis::visitDecl(CactParser::DeclContext *context) {
    if (context->constDecl()) {
        visitConstDecl(context->constDecl());
    } else if (context->varDecl()) {
        visitVarDecl(context->varDecl());
    } else {
        std::cerr << "Error: Unknown declaration type!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}
std::any Analysis::visitConstDecl(CactParser::ConstDeclContext *context) {
    currentBType = std::any_cast<BaseType>(visitBType(context->bType()));
    for (const auto &it : context->constDef()) {
        visitConstDef(it);
    }
    return 0;
}
std::any Analysis::visitBType(CactParser::BTypeContext *context) {
    if (context->INT_KW()) return BaseType::I32;
    if (context->DOUBLE_KW()) return BaseType::DOUBLE;
    if (context->CHAR_KW()) return BaseType::I8;
    if (context->FLOAT_KW()) return BaseType::FLOAT;
    if (context->BOOL_KW()) return BaseType::I1;
    std::cerr << "Error (visitBType): Unknown type!" << std::endl;
    exit(EXIT_FAILURE);
}
std::any Analysis::visitConstDef(CactParser::ConstDefContext *context) {
    std::string ident = context->IDENT()->getText();
    bool defined = currentSymbolTable->lookupInCurrentScope(ident);
    if (defined) { // check if the identifier is already defined
        std::cerr << "Error: Identifier " << ident << " already defined!" << std::endl;
        exit(EXIT_FAILURE);
    }
    // add symbol to symbol table
    std::vector<int> dimSize;
    for (const auto &it : context->intConst()) {
        dimSize.push_back(std::stoi(std::any_cast<std::string> (visitIntConst(it))));
    }
    if (!dimSize.empty() && currentBType != BaseType::I32 && currentBType != BaseType::FLOAT && currentBType != BaseType::I8) {
        std::cerr << "Error: array must be of type INT, FLOAT or CHAR!" << std::endl;
        exit(EXIT_FAILURE);
    }
    VarType currentT = VarType(currentBType, true /*is Const*/, false /*not function*/, dimSize);
    std::string ssa = newSSA(ident);
    currentSymbolTable->define(Symbol(ident, currentT, ssa));
    // generate LLVM code
    if (isGlobal) {
        auto initval = std::any_cast<LLVMValue>(visitConstInitVal(context->constInitVal()));
        if (initval.type.baseType != currentBType) {
            std::cerr << "Error: Type mismatch in constant declaration! Expected " << TypeToLLVM(currentT) << ", got " << TypeToLLVM(initval.type) << std::endl;
            exit(EXIT_FAILURE);
        }
        LLVMGlobalVar globalVar(ssa, currentT, initval.name, true /* is Const*/);
        llvmmodule.addGlobalVar(globalVar);
    } else {
        std::stringstream ss;
        ss << "%" << ssa << " = alloca " << TypeToLLVM(currentT);
        currentBlock->addInstruction(ss.str());
        ss.str("");
        auto initval = std::any_cast<LLVMValue> (visitConstInitVal(context->constInitVal()));
        if (initval.type.baseType != currentBType) {
            std::cerr << "Error: Type mismatch in constant declaration! Expected " << TypeToLLVM(currentT) << ", got " << TypeToLLVM(initval.type) << std::endl;
            exit(EXIT_FAILURE);
        }
        if (!dimSize.empty()) {
            std::string globalid = newSSA("__const." + ident);
            LLVMGlobalVar globalVar(globalid, currentT, initval.name, true /* is Const*/);
            llvmmodule.addGlobalVar(globalVar);
            std::string identcast = newSSA("cast." + ident);
            ss << "%" << identcast << " = bitcast " << TypeToLLVM(currentT) << "* " << "%" << ssa << " to i8*";
            currentBlock->addInstruction(ss.str());
            ss << "";
            std::string globalcast = newSSA("cast." + globalid);
            ss << "%" << globalcast << " = bitcast " << TypeToLLVM(currentT) << "* @" << globalid << " to i8*";
            currentBlock->addInstruction(ss.str());
            ss << "";
            ss << "call void @llvm.memcpy.p0i8.p0i8.i32(i8* " << "%" << identcast << ", i8* " << "%" << globalcast << ", i32 " << currentT.getArraySize() << ", i1 false)";
            currentBlock->addInstruction(ss.str());
        } else {
            ss << "store " << TypeToLLVM(initval.type) << " " << initval.name << ", " << TypeToLLVM(currentBType) << "* %" << ssa;
            currentBlock->addInstruction(ss.str());
        }
    }
    return 0;;
}
std::any Analysis::visitConstInitVal(CactParser::ConstInitValContext *context) {
    if (context->signedNumber()) {
        auto num = std::any_cast<LLVMValue>(visitSignedNumber(context->signedNumber()));
        if (currentBType != num.type.baseType) {
            std::cerr << "Error: Type mismatch in constant initialization! Expected " << BTypeToLLVM(currentBType) << ", got " << TypeToLLVM(num.type) << std::endl;
            exit(EXIT_FAILURE);
        }
        return num;
    } else if (!context->constInitVal().empty()) { // {{{4,5},{6,7}}, {{1, 2}, {2, 3}}} -> [2 x [2 x [2 x i32]]] [[2 x [2 x i32]] [[2 x i32] [i32 4, i32 5], [2 x i32] [i32 6, i32 7]], [2 x [2 x i32]] [[2 x i32] [i32 1, i32 2], [2 x i32] [i32 2, i32 3]]
        std::vector<LLVMValue> initVals;
        for (int i = 0; i < context->constInitVal().size(); ++i) {
            auto initVal = std::any_cast<LLVMValue>(visitConstInitVal(context->constInitVal(i)));
            if (initVal.type.baseType != currentBType) {
                std::cerr << "Error: Type mismatch in constant initialization! Expected " << BTypeToLLVM(currentBType) << ", got " << TypeToLLVM(initVal.type) << std::endl;
                exit(EXIT_FAILURE);
            } else {
                initVals.push_back(initVal);
            }
        }
        std::vector<int> childDimSize = initVals[0].type.dimSizes;
        std::vector<int> dimSize = { (int) initVals.size() };
        for (const auto &size : childDimSize) {
            dimSize.push_back(size);
        }
        VarType arrayT = VarType(currentBType, true /*is Const*/, false /*not function*/, dimSize);
        std::stringstream ss;
        ss << "[";
        for (size_t i = 0; i < initVals.size(); ++i) {
            ss << TypeToLLVM(initVals[i].type) << " " << initVals[i].name;
            if (i < initVals.size() - 1) {
                ss << ", ";
            }
        }
        ss << "]";
        return LLVMValue(ss.str(), arrayT);
    } else if (context->boolConst()) {
        auto boolConst = std::any_cast<LLVMValue>(visitBoolConst(context->boolConst()));
        if (currentBType != BaseType::I1) {
            std::cerr << "Error: Type mismatch in constant initialization! Expected i1, got " << TypeToLLVM(boolConst.type) << std::endl;
            exit(EXIT_FAILURE);
        }
        return boolConst;
    } else if (context->L_BRACE() && context->constInitVal().empty()) {
        std::vector<int> dimSize = { 0 };
        return LLVMValue("zeroinitializer", VarType(currentBType, false /*is Const*/, false /*not function*/, dimSize));
    }
}
std::any Analysis::visitVarDecl(CactParser::VarDeclContext *context) {
    currentBType = std::any_cast<BaseType>(visitBType(context->bType()));
    for (auto it : context->varDef()) {
        visitVarDef(it);
    }
    return 0;
}
std::any Analysis::visitVarDef(CactParser::VarDefContext *context) {
    std::string ident = context->IDENT()->getText();
    // check if the identifier is already defined
    bool defined = currentSymbolTable->lookupInCurrentScope(ident);
    if (defined) {
        std::cerr << "Error: Identifier " << ident << " already defined!" << std::endl;
        exit(EXIT_FAILURE);
    }
    // add symbol to symbol table
    std::vector<int> dimSize;
    for (auto it : context->intConst()) {
        dimSize.push_back(std::stoi(std::any_cast<std::string>(visitIntConst(it))));
    }
    VarType currentT = VarType(currentBType, false /*not Const*/, false /*not function*/, dimSize);
    std::string ssa = newSSA(ident);
    currentSymbolTable->define(Symbol(ident, currentT, ssa));
    // generate LLVM code
    if (isGlobal) {
        if (context->constInitVal()) {
            auto initval = std::any_cast<LLVMValue>(visitConstInitVal(context->constInitVal()));
            if (initval.type.baseType != currentBType) {
                std::cerr << "Error: Type mismatch in variable declaration! Expected " << TypeToLLVM(currentT) << ", got " << TypeToLLVM(initval.type) << std::endl;
                exit(EXIT_FAILURE);
            }
            LLVMGlobalVar globalVar(ssa, currentT, initval.name, false /* not Const*/);
            llvmmodule.addGlobalVar(globalVar);
        } else {
            LLVMGlobalVar globalVar(ssa, currentT, "", false /* not Const*/);
            llvmmodule.addGlobalVar(globalVar);
        }
    } else {
        std::stringstream ss;
        ss << "%" << ssa << " = alloca " << TypeToLLVM(currentT);
        currentBlock->addInstruction(ss.str());
        ss.str("");
        if (context->constInitVal()) {
            auto initval = std::any_cast<LLVMValue>(visitConstInitVal(context->constInitVal()));
            if (initval.type.baseType != currentBType) {
                std::cerr << "Error: Type mismatch in variable declaration! Expected " << TypeToLLVM(currentT) << ", got " << TypeToLLVM(initval.type) << std::endl;
                exit(EXIT_FAILURE);
            }
            if (!dimSize.empty()) {
                std::string globalid = newSSA("__const." + ident);
                LLVMGlobalVar globalVar(globalid, currentT, initval.name, false /* not Const*/);
                llvmmodule.addGlobalVar(globalVar);
                std::string identcast = newSSA("cast." + ident);
                ss << "%" << identcast << " = bitcast " << TypeToLLVM(currentT) << "* " << "%" << ssa << " to i8*";
                currentBlock->addInstruction(ss.str());
                ss.str("");
                std::string globalcast = newSSA("cast." + globalid);
                ss << "%" << globalcast << " = bitcast " << TypeToLLVM(currentT) << "* @" << globalid << " to i8*";
                currentBlock->addInstruction(ss.str());
                ss.str("");
                ss << "call void @llvm.memcpy.p0i8.p0i8.i32(i8* " << "%" << identcast << ", i8* " << "%" << globalcast << ", i32 " << currentT.getArraySize() << ", i1 false)";
                currentBlock->addInstruction(ss.str());
            } else {
                ss << "store " << TypeToLLVM(initval.type) << " " << initval.name << ", " << TypeToLLVM(currentBType) << "* %" << ssa;
                currentBlock->addInstruction(ss.str());
            }
        }
    }
    return 0;
}
std::any Analysis::visitFuncDef(CactParser::FuncDefContext *context) {
    BaseType retBT = std::any_cast<BaseType>(visitFuncType(context->funcType()));
    std::string ident = context->IDENT()->getText();
    // check if the main return int 
    if (ident == "main" && retBT != BaseType::I32) {
        std::cerr << "Error: main function must return int!" << std::endl;
        exit(EXIT_FAILURE);
    }
    // check if the identifier is already defined
    bool defined = currentSymbolTable->lookupInCurrentScope(ident, true /*is function*/);
    if (defined) {
        std::cerr << "Error: Identifier " << ident << " already defined!" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::vector<LLVMValue> parameters;
    std::vector<string> paramsT;
    if (context->funcFParams()) {
        // check if the main function has parameters
        if (ident == "main") {
            std::cerr << "Error: main function must not have parameters!" << std::endl;
            exit(EXIT_FAILURE);
        }
        parameters = std::move(std::any_cast<std::vector<LLVMValue>>(visitFuncFParams(context->funcFParams())));
        for (const auto &param : parameters) {
            paramsT.push_back(TypeToLLVM(param.type));
        }
    }
    LLVMFunction *function = new LLVMFunction(ident, BTypeToLLVM(retBT), parameters);
    currentFunction = function;
    // add symbol to symbol table
    VarType retT = VarType(retBT, false /*not Const*/, true /*is Function*/);
    currentSymbolTable->define(Symbol(ident, retT, newSSA(ident), paramsT));
    // generate LLVM code
    // visit the function body
    LLVMBasicBlock *block = new LLVMBasicBlock("entry");
    function->addBasicBlock(block);
    currentBlock = block;
    isGlobal = false;
    currentSymbolTable = new SymbolTable(currentSymbolTable);
    /* load params */
    for (size_t i = 0; i < parameters.size(); ++i) {
        std::stringstream ss;
        ss << "%" << parameters[i].name << " = alloca " << TypeToLLVM(parameters[i].type);
        currentBlock->addInstruction(ss.str());
        ss.str("");
        ss << "store " << TypeToLLVM(parameters[i].type) << " %" << parameters[i].name << "_params" << ", " << TypeToLLVM(parameters[i].type) << "* %" << parameters[i].name;
        currentBlock->addInstruction(ss.str());
        currentSymbolTable->define(Symbol(parameters[i].name, parameters[i].type, parameters[i].name));
    }
    visitBlock(context->block());
    // visit the body end
    isGlobal = true;
    currentSymbolTable = currentSymbolTable->getParent();
    llvmmodule.addFunction(*function);
    return 0;
}
std::any Analysis::visitFuncType(CactParser::FuncTypeContext *context) {
    if (context->VOID_KW()) return BaseType::VOID;
    if (context->bType()) {
        return std::any_cast<BaseType>(visitBType(context->bType()));
    }
}
std::any Analysis::visitFuncFParams(CactParser::FuncFParamsContext *context) {
    std::vector<LLVMValue> params;
    for (const auto &it : context->funcFParam()) {
        params.push_back(std::any_cast<LLVMValue>(visitFuncFParam(it)));
    }
    return params;
}
std::any Analysis::visitFuncFParam(CactParser::FuncFParamContext *context) {
    std::string ident = context->IDENT()->getText();
    BaseType baseT = std::any_cast<BaseType>(visitBType(context->bType()));
    std::vector<int> dimSize;
    if (context->intConst().size() < context->L_BRACKET().size()) {
        dimSize.push_back(-1);
    }
    for (int i = 0; i < context->intConst().size(); i++) {
        dimSize.push_back(std::stoi(std::any_cast<std::string>(visitIntConst(context->intConst(i)))));
    }
    VarType varT = VarType(baseT, false /*not Const*/, false /*not function*/, dimSize);
    return LLVMValue(ident, varT);
}
std::any Analysis::visitBlock(CactParser::BlockContext *context) {
    for (const auto &it : context->blockItem()) {
        visitBlockItem(it);
    }
    return 0;
}
std::any Analysis::visitBlockItem(CactParser::BlockItemContext *context) {
    if (context->decl()) { // decl
        visitDecl(context->decl());
    } else if (context->stmt()) { // stmt
        visitStmt(context->stmt());
    } else {
        std::cerr << "Error: Unknown block item!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}
std::any Analysis::visitElseIFStmt(CactParser::ElseIFStmtContext *context) {
    return 0;
}
std::any Analysis::visitElseStmt(CactParser::ElseStmtContext *context) {
    return 0;
}
std::any Analysis::visitStmt(CactParser::StmtContext *context) {
    if (context->lVal()) {  // lva = exp;
        auto left_ptr = std::any_cast<LLVMValue>(visitLVal(context->lVal()));
        auto right = std::any_cast<LLVMValue> (visitExp(context->exp()));
        if (left_ptr.type.baseType != right.type.baseType || left_ptr.type.dimSizes != right.type.dimSizes) {
            std::cerr << "Error: Type mismatch in assignment! Expected " << TypeToLLVM(left_ptr.type) << ", got " << TypeToLLVM(right.type) << std::endl;
            exit(EXIT_FAILURE);
        }
        std::stringstream ss;
        ss << "store " << TypeToLLVM(left_ptr.type) << " " << right.name << ", " << TypeToLLVM(left_ptr.type) << "* " << left_ptr.name;
        currentBlock->addInstruction(ss.str());
    } else if (context->block()) { // block
        currentSymbolTable = new SymbolTable(currentSymbolTable);
        visitBlock(context->block());
        currentSymbolTable = currentSymbolTable->getParent();
    } else if (context->IF_KW()) { // if (cond) stmt else stmt
        std::string thenLabel = newLabel("then");
        std::string elseifLabel = context->elseIFStmt().empty() ? "" : newLabel("elseif");
        std::string elseLabel = context->elseStmt() ? newLabel("else") : "";
        std::string endLabel = newLabel("ifend");
        std::string cond = std::any_cast<std::string>(visitCond(context->cond()));

        std::stringstream ss;
        if (!elseifLabel.empty()) {
            ss << "br i1 " << cond << ", label %" << thenLabel << ", label %" << elseifLabel;
        } else if (!elseLabel.empty()) {
            ss << "br i1 " << cond << ", label %" << thenLabel << ", label %" << elseLabel;
        } else {
            ss << "br i1 " << cond << ", label %" << thenLabel << ", label %" << endLabel;
        }
        currentBlock->addInstruction(ss.str());
        // then
        LLVMBasicBlock *thenBlock = new LLVMBasicBlock(thenLabel);
        currentBlock = thenBlock;
        visitStmt(context->stmt());
        currentBlock->addInstruction("br label %" + endLabel);
        currentFunction->addBasicBlock(thenBlock);

        // else if
        for (int i = 0; i < context->elseIFStmt().size(); i++) {
            std::string nextLabel;
            if (i < context->elseIFStmt().size() - 1) {
                nextLabel = newLabel("elseif_next");
            } else if (context->elseStmt()) {
                nextLabel = elseLabel;
            } else {
                nextLabel = endLabel;
            }

            LLVMBasicBlock *elseifBlock = new LLVMBasicBlock(elseifLabel);
            currentBlock = elseifBlock;
            currentFunction->addBasicBlock(elseifBlock);
            std::string elseifCond = std::any_cast<std::string>(visitCond(context->elseIFStmt(i)->cond()));
            std::stringstream elseifSS;
            std::string elsethenLabel = newLabel("elseif_then");
            elseifSS << "br i1 " << elseifCond << ", label %" << elsethenLabel << ", label %" << nextLabel;
            currentBlock->addInstruction(elseifSS.str());
            // elseif then
            LLVMBasicBlock *elseifThenBlock = new LLVMBasicBlock(elsethenLabel);
            currentBlock = elseifThenBlock;
            visitStmt(context->elseIFStmt(i)->stmt());
            currentBlock->addInstruction("br label %" + endLabel);
            currentFunction->addBasicBlock(elseifThenBlock);
            // update elseifLabel for next iteration
            if (i < context->elseIFStmt().size() - 1) {
                elseifLabel = newLabel("elseif");
            }
        }

        // else
        if (context->elseStmt()) {
            LLVMBasicBlock *elseBlock = new LLVMBasicBlock(elseLabel);
            currentBlock = elseBlock;
            currentFunction->addBasicBlock(elseBlock);
            visitStmt(context->elseStmt()->stmt());
            currentBlock->addInstruction("br label %" + endLabel);
        }

        // end
        LLVMBasicBlock *endBlock = new LLVMBasicBlock(endLabel);
        currentBlock = endBlock;
        currentFunction->addBasicBlock(endBlock);
    } else if (context->WHILE_KW()) { // while (cond) stmt
        std::string condLabel = newLabel("while_cond");
        std::string bodyLabel = newLabel("while_body");
        std::string endLabel = newLabel("while_end");

        curCondLabel = condLabel;
        curEndLabel = endLabel;
        // cond
        LLVMBasicBlock *condBlock = new LLVMBasicBlock(condLabel);
        currentFunction->addBasicBlock(condBlock);
        currentBlock->addInstruction("br label %" + condLabel);
        currentBlock = condBlock;
        std::string cond = std::any_cast<std::string>(visitCond(context->cond()));
        std::stringstream ss;
        ss << "br i1 " << cond << ", label %" << bodyLabel << ", label %" << endLabel;
        currentBlock->addInstruction(ss.str());
        // body
        LLVMBasicBlock *bodyBlock = new LLVMBasicBlock(bodyLabel);
        currentFunction->addBasicBlock(bodyBlock);
        currentBlock = bodyBlock;
        visitStmt(context->stmt());
        currentBlock->addInstruction("br label %" + condLabel);
        // end
        LLVMBasicBlock *endBlock = new LLVMBasicBlock(endLabel);
        currentFunction->addBasicBlock(endBlock);
        currentBlock = endBlock;
        curEndLabel = "";
        curCondLabel = "";
    } else if (context->BREAK_KW()) { // break
        if (curEndLabel.empty()) {
            std::cerr << "Error: break statement not in loop!" << std::endl;
            exit(EXIT_FAILURE);
        } else {
            currentBlock->addInstruction("br label %" + curEndLabel);
        }
    } else if (context->CONTINUE_KW()) { // continue
        if (curCondLabel.empty()) {
            std::cerr << "Error: continue statement not in loop!" << std::endl;
            exit(EXIT_FAILURE);
        } else {
            currentBlock->addInstruction("br label %" + curCondLabel);
        }
    } else if (context->RETURN_KW()) { // return exp;
        if (context->exp()) {
            auto ret = std::any_cast<LLVMValue> (visitExp(context->exp()));
            if (currentFunction->returnType != TypeToLLVM(ret.type) || currentFunction->returnType == "void") {
                std::cerr << "Error: Type mismatch in return statement! Expected " << currentFunction->returnType << ", got " << TypeToLLVM(ret.type) << std::endl;
                exit(EXIT_FAILURE);
            }
            currentBlock->addInstruction("ret " + currentFunction->returnType + " " + ret.name);
        } else {
            if (currentFunction->returnType != "void") {
                std::cerr << "Error: Function " << currentFunction->name << " must return a value!" << std::endl;
                exit(EXIT_FAILURE);
            }
            currentBlock->addInstruction("ret void");
        }
    } else { // exp?;
        if (context->exp()) {
            visit(context->exp());
        }
    }
    return 0;
}
std::any Analysis::visitExp(CactParser::ExpContext *context) {
    return (visitAddExp(context->addExp()));
}

std::any Analysis::visitCond(CactParser::CondContext *context) {
    auto exp = any_cast<LLVMValue> (visitLOrExp(context->lOrExp()));
    if (exp.type.baseType != BaseType::I1 || !exp.type.dimSizes.empty()) {
        std::cerr << "Error: Condition expression must be of type i1!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return exp.name;
}
std::any Analysis::visitLVal(CactParser::LValContext *context) {
    std::string ident = context->IDENT()->getText();
    // check if the identifier is already defined
    auto sp = currentSymbolTable->lookup(ident);
    Symbol *s = sp.first;
    if (s == nullptr) {
        std::cerr << "Error: Identifier " << ident << " not defined!" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (s->type.isConst) {
        std::cerr << "Error: Identifier " << ident << " is a constant and cannot be assigned!" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string identssa = s->ssa;
    if (s->type.isArray()) {
        std::vector<std::string> index;
        for (int i = 0; i < context->exp().size(); i++) {
            auto exp = std::any_cast<LLVMValue>(visitExp(context->exp(i)));
            if (exp.type.baseType != BaseType::I32 || !exp.type.dimSizes.empty()) {
                std::cerr << "Error: Array index must be of type i32!" << std::endl;
                exit(EXIT_FAILURE);
            }
            index.push_back(exp.name);
        }
        std::string ptr = "%" + newSSA("ptr");
        std::stringstream ss;
        ss << ptr << " = getelementptr inbounds " << TypeToLLVM(s->type) << ", " << TypeToLLVM(s->type) << "* " << (sp.second ? "@" : "%") << identssa;
        ss << ", i32 0"; // base address
        for (const auto &idx : index) {
            ss << ", i32 " << idx; // add index
        }
        currentBlock->addInstruction(ss.str());
        return LLVMValue(ptr, VarType(s->type.baseType));
    } else {
        return LLVMValue((sp.second ? "@" : "%") + identssa, VarType(s->type.baseType));
    }
}
std::any Analysis::visitSignedNumber(CactParser::SignedNumberContext *context) {
    auto num = std::any_cast<LLVMValue>(visitNumber(context->number()));
    if (context->MINUS()) {
        std::stringstream ss;
        std::string negated = "%" + newSSA("negated");
        ss << negated << " = sub " << TypeToLLVM(num.type) << " 0, " << num.name;
        currentBlock->addInstruction(ss.str());
        return LLVMValue(negated, num.type);
    } else {
        return num; // just return the number
    }
}
std::any Analysis::visitNumber(CactParser::NumberContext *context) {
    if (context->intConst()) {
        std::string intVal = std::any_cast<std::string>(visitIntConst(context->intConst()));
        return LLVMValue(intVal, VarType(BaseType::I32, true /*is const*/));
    } else if (context->FloatConst() || context->EXPONENT()) {
        std::string literal;
        if (context->FloatConst()) {
            literal = context->FloatConst()->getText();
        } else {
            literal = context->EXPONENT()->getText();
        }
        if (currentBType == BaseType::FLOAT) {
            float value = std::stof(literal);
            uint32_t bits;
            std::memcpy(&bits, &value, sizeof(float));
            uint64_t bits64 = static_cast<uint64_t>(bits) << 32;
            std::stringstream ss;
            ss << "0x" << std::hex << std::uppercase << bits64;
            return LLVMValue(ss.str(), VarType(BaseType::FLOAT, true /*is Const*/));
        } else {
            double value = std::stod(literal);
            uint64_t bits;
            std::memcpy(&bits, &value, sizeof(double));
            std::stringstream ss;
            ss << "0x" << std::hex << std::uppercase << bits;
            return LLVMValue(ss.str(), VarType(BaseType::DOUBLE, true /*is Const*/));
        }
    } else if (context->CharConst()) {
        std::string ch = context->CharConst()->getText();
        if (ch.size() == 3 && ch.front() == '\'' && ch.back() == '\'') {
            int val = static_cast<int>(ch[1]);
            return LLVMValue(std::to_string(val), VarType(BaseType::I8, true /*is Const*/));
        } else if (ch.size() == 4 && ch[1] == '\\') {
            char esc = ch[2];
            int val = 0;
            switch (esc) {
            case 'n': val = '\n'; break;
            case 't': val = '\t'; break;
            case 'r': val = '\r'; break;
            case 'b': val = '\b'; break;
            case 'f': val = '\f'; break;
            case '\\': val = '\\'; break;
            default: std::cerr << "Error: Unknown escape character!" << std::endl; exit(EXIT_FAILURE);
            }
            return LLVMValue(std::to_string(val), VarType(BaseType::I8, true /*is Const*/));
        } else {
            std::cerr << "Error: Invalid character constant!" << std::endl;
            exit(EXIT_FAILURE);
        }
    } else {
        std::cerr << "Error: Unknown number!" << std::endl;
        exit(EXIT_FAILURE);
    }
}
std::any Analysis::visitFuncRParams(CactParser::FuncRParamsContext *context) {
    std::vector<VarType> paramsT;
    std::stringstream ss;
    for (int i = 0; i < context->exp().size(); i++) {
        auto param = std::any_cast<LLVMValue>(visitExp(context->exp(i)));
        ss << TypeToLLVM(param.type) << " " << param.name;
        if (i != context->exp().size() - 1) {
            ss << ", ";
        }
        paramsT.push_back(param.type);
    }
    return std::make_pair(ss.str(), paramsT);
}
std::any Analysis::visitPrimaryExp(CactParser::PrimaryExpContext *context) {
    if (context->L_PAREN()) {
        return (visitExp(context->exp(0)));
    } else if (context->IDENT()) {
        std::string ident = context->IDENT()->getText();
        // check if the identifier is already defined
        auto s = currentSymbolTable->lookup(ident);
        if (s.first == nullptr) {
            std::cerr << "Error: Identifier " << ident << " not defined!" << std::endl;
            exit(EXIT_FAILURE);
        }
        std::string identssa = s.first->ssa;
        if (s.first->type.isArray()) {
            std::vector<std::string> index;
            for (int i = 0; i < context->exp().size(); i++) {
                auto exp = std::any_cast<LLVMValue>(visitExp(context->exp(i)));
                if (exp.type.baseType != BaseType::I32 || !exp.type.dimSizes.empty()) {
                    std::cerr << "Error: Array index must be of type i32!" << std::endl;
                    exit(EXIT_FAILURE);
                }
                index.push_back(exp.name);
            }
            std::string ptr = "%" + newSSA("ptr");
            std::stringstream ss;
            ss << ptr << " = getelementptr inbounds " << TypeToLLVM(s.first->type) << ", " << TypeToLLVM(s.first->type) << "* " << (s.second ? "@" : "%") << identssa;
            ss << ", i32 0"; // base address
            for (const auto &idx : index) {
                ss << ", i32 " << idx; // add index
            }
            currentBlock->addInstruction(ss.str());
            std::string load = "%" + newSSA("load");
            ss.str("");
            ss << load << " = load " << BTypeToLLVM(s.first->type.baseType) << ", " << BTypeToLLVM(s.first->type.baseType) << "* " << ptr;
            currentBlock->addInstruction(ss.str());
            return LLVMValue(load, VarType(s.first->type.baseType));
        } else {
            std::string load = "%" + newSSA("load");
            std::stringstream ss;
            ss << load << " = load " << TypeToLLVM(s.first->type) << ", " << TypeToLLVM(s.first->type) << "* " << (s.second ? "@" : "%") << identssa;
            currentBlock->addInstruction(ss.str());
            return LLVMValue(load, VarType(s.first->type.baseType));
        }
    } else if (context->number()) {
        return (visitNumber(context->number()));
    } else if (context->boolConst()) {
        return visitBoolConst(context->boolConst());
    }
}
std::any Analysis::visitUnaryExp(CactParser::UnaryExpContext *context) {
    if (context->primaryExp()) {
        return visitPrimaryExp(context->primaryExp());
    } else if (context->unaryOp() && context->unaryExp()) { // unaryOp unaryExp
        if (context->unaryOp()->PLUS()) {
            return visitUnaryExp(context->unaryExp());
        } else if (context->unaryOp()->MINUS()) {
            auto right = std::any_cast<LLVMValue>(visitUnaryExp(context->unaryExp()));
            std::string neg = "%" + newSSA("neg");
            std::stringstream ss;
            ss << neg << " = sub " << TypeToLLVM(right.type) << " 0, " << right.name;
            currentBlock->addInstruction(ss.str());
            return LLVMValue(neg, right.type);
        } else if (context->unaryOp()->NOT()) {
            auto right = std::any_cast<LLVMValue> (visitUnaryExp(context->unaryExp()));
            std::string notssa = "%" + newSSA("not");
            std::stringstream ss;
            ss << notssa << " = icmp eq " << TypeToLLVM(right.type) << " " << right.name << ", 0";
            currentBlock->addInstruction(ss.str());
            return LLVMValue(notssa, VarType(BaseType::I1));
        } else {
            std::cerr << "Error: Unknown unary operator!" << std::endl;
            exit(EXIT_FAILURE);
        }
    } else if (context->IDENT()) {
        std::string ident = context->IDENT()->getText();
        // check if the identifier is already defined
        auto s = currentSymbolTable->lookup(ident, true /*is function*/);
        if (s.first == nullptr) {
            std::cerr << "Error: Identifier " << ident << " not defined!" << std::endl;
            exit(EXIT_FAILURE);
        }
        // call a function
        std::stringstream ss;
        std::string funcret;
        if (s.first->type.baseType == BaseType::VOID) {
            funcret = "";
            ss << "call void @" << ident << "(";
        } else {
            funcret = "%" + newSSA("ret");
            ss << funcret << " = call " << TypeToLLVM(s.first->type) << " @" << ident << "(";
        }
        if (context->funcRParams()) {
            auto params = std::any_cast<std::pair<std::string, std::vector<VarType>>>(visitFuncRParams(context->funcRParams()));
            auto paramsT = params.second;
            if (paramsT.size() != s.first->params.size()) {
                std::cerr << "Error: Function " << ident << " expects " << s.first->params.size() << " parameters, but got " << paramsT.size() << std::endl;
                exit(EXIT_FAILURE);
            }
            for (size_t i = 0; i < paramsT.size(); ++i) {
                if (TypeToLLVM(paramsT[i]) != s.first->params[i]) {
                    std::cerr << "Error: Function " << ident << " expects parameter of type " << s.first->params[i] << ", but got " << TypeToLLVM(paramsT[i]) << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
            ss << params.first;
        } else {
            if (!s.first->params.empty()) {
                std::cerr << "Error: Function " << ident << " expects parameters, but none were provided!" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        ss << ")";
        currentBlock->addInstruction(ss.str());
        if (s.first->type.baseType == BaseType::VOID) {
            return LLVMValue("", VarType(BaseType::VOID, true /*is Const*/));
        } else {
            return LLVMValue(funcret, s.first->type);
        }
    } else {
        std::cerr << "Error: Unknown unary expression!" << std::endl;
        exit(EXIT_FAILURE);
    }
}
std::any Analysis::visitUnaryOp(CactParser::UnaryOpContext *context) {
}
std::any Analysis::visitMulExp(CactParser::MulExpContext *context) {
    auto left = std::any_cast<LLVMValue>(visitUnaryExp(context->unaryExp(0)));
    auto mul = left;
    for (int i = 1; i < context->unaryExp().size(); i++) {
        auto right = std::any_cast<LLVMValue>(visitUnaryExp(context->unaryExp(i)));
        if (right.type.baseType != left.type.baseType || !right.type.dimSizes.empty() || !left.type.dimSizes.empty()) {
            std::cerr << "Error: Type mismatch in multiplication! Expected " << TypeToLLVM(left.type) << ", got " << TypeToLLVM(right.type) << std::endl;
            exit(EXIT_FAILURE);
        }
        mul.name = "%" + newSSA("mul");
        std::stringstream ss;
        if (right.type.baseType == BaseType::I32) {
            if (context->mulOp(i - 1)->MUL()) {
                ss << mul.name << " = mul " << TypeToLLVM(left.type) << " " << left.name << ", " << right.name;
            } else if (context->mulOp(i - 1)->DIV()) {
                ss << mul.name << " = sdiv " << TypeToLLVM(left.type) << " " << left.name << ", " << right.name;
            } else if (context->mulOp(i - 1)->MOD()) {
                ss << mul.name << " = srem " << TypeToLLVM(left.type) << " " << left.name << ", " << right.name;
            }
        } else if (right.type.baseType == BaseType::FLOAT || right.type.baseType == BaseType::DOUBLE) {
            if (context->mulOp(i - 1)->MUL()) {
                ss << mul.name << " = fmul " << TypeToLLVM(left.type) << " " << left.name << ", " << right.name;
            } else if (context->mulOp(i - 1)->DIV()) {
                ss << mul.name << " = fdiv " << TypeToLLVM(left.type) << " " << left.name << ", " << right.name;
            }
        } else {
            std::cerr << "Error: Unknown type in multiplication!" << std::endl;
            exit(EXIT_FAILURE);
        }
        currentBlock->addInstruction(ss.str());
        left = mul;
    }
    return mul;
}
std::any Analysis::visitMulOp(CactParser::MulOpContext *context) {
}
std::any Analysis::visitAddExp(CactParser::AddExpContext *context) {
    auto left = std::any_cast<LLVMValue>(visitMulExp(context->mulExp(0)));
    auto sum = left;
    for (int i = 1; i < context->mulExp().size(); i++) {
        std::stringstream ss;
        auto right = std::any_cast<LLVMValue>(visitMulExp(context->mulExp(i)));
        if (left.type.baseType != right.type.baseType || !left.type.dimSizes.empty() || !right.type.dimSizes.empty()) {
            std::cerr << "Error: Type mismatch in addition! Expected " << TypeToLLVM(left.type) << ", got " << TypeToLLVM(right.type) << std::endl;
            exit(EXIT_FAILURE);
        }
        sum.name = "%" + newSSA("sum");
        if (context->addOp(i - 1)->PLUS()) {
            ss << sum.name << " = add " << TypeToLLVM(left.type) << " " << left.name << ", " << right.name;
        } else if (context->addOp(i - 1)->MINUS()) {
            ss << sum.name << " = sub " << TypeToLLVM(left.type) << " " << left.name << ", " << right.name;
        }
        currentBlock->addInstruction(ss.str());
        left = sum;
    }
    return sum;
}
std::any Analysis::visitAddOp(CactParser::AddOpContext *context) {
}
std::any Analysis::visitRelExp(CactParser::RelExpContext *context) {
    auto left = std::any_cast<LLVMValue>(visitAddExp(context->addExp(0)));
    auto rel = left;
    if (context->addExp().size() == 1) {
        return rel;
    } else if (context->addExp().size() == 2) {
        auto right = std::any_cast<LLVMValue>(visitAddExp(context->addExp(1)));
        if (left.type.baseType != right.type.baseType || !left.type.dimSizes.empty() || !right.type.dimSizes.empty()) {
            std::cerr << "Error: Type mismatch in relational expression! Expected " << TypeToLLVM(left.type) << ", got " << TypeToLLVM(right.type) << std::endl;
            exit(EXIT_FAILURE);
        }
        rel.name = "%" + newSSA("rel");
        if (context->relOp()->LT()) {
            currentBlock->addInstruction(rel.name + " = icmp slt " + TypeToLLVM(left.type) + " " + left.name + ", " + right.name);
        } else if (context->relOp()->GT()) {
            currentBlock->addInstruction(rel.name + " = icmp sgt " + TypeToLLVM(left.type) + " " + left.name + ", " + right.name);
        } else if (context->relOp()->GE()) {
            currentBlock->addInstruction(rel.name + " = icmp sge " + TypeToLLVM(left.type) + " " + left.name + ", " + right.name);
        } else if (context->relOp()->LE()) {
            currentBlock->addInstruction(rel.name + " = icmp sle " + TypeToLLVM(left.type) + " " + left.name + ", " + right.name);
        }
        rel.type = VarType(BaseType::I1);
        return rel;
    }
}
std::any Analysis::visitRelOp(CactParser::RelOpContext *context) {
}
std::any Analysis::visitEqExp(CactParser::EqExpContext *context) {
    auto left = std::any_cast<LLVMValue>(visitRelExp(context->relExp(0)));
    auto eq = left;
    if (context->relExp().size() == 1) {
        return eq;
    } else if (context->relExp().size() == 2) {
        auto right = std::any_cast<LLVMValue>(visitRelExp(context->relExp(1)));
        if (left.type.baseType == BaseType::I32 && right.type.baseType == BaseType::I1) {
            std::string newleft = "%" + newSSA("eq");
            currentBlock->addInstruction(newleft + " = icmp ne " + TypeToLLVM(left.type) + " " + left.name + ", 0");
            left.name = newleft;
            left.type = VarType(BaseType::I1); // convert to boolean type
            eq = left;
        }else if(left.type.baseType == BaseType::I1 && right.type.baseType == BaseType::I32) {
            std::string newright = "%" + newSSA("eq");
            currentBlock->addInstruction(newright + " = icmp ne " + TypeToLLVM(right.type) + " " + right.name + ", 0");
            right.name = newright;
            right.type = VarType(BaseType::I1); // convert to boolean type
        }

        if (left.type.baseType != right.type.baseType || !left.type.dimSizes.empty() || !right.type.dimSizes.empty()) {
            std::cerr << "Error: Type mismatch in equality expression! Expected " << TypeToLLVM(left.type) << ", got " << TypeToLLVM(right.type) << std::endl;
            exit(EXIT_FAILURE);
        }
        eq.name = "%" + newSSA("eq");
        if (context->eqOp()->EQ()) {
            currentBlock->addInstruction(eq.name + " = icmp eq " + TypeToLLVM(eq.type) + " " + left.name + ", " + right.name);
        } else if (context->eqOp()->NEQ()) {
            currentBlock->addInstruction(eq.name + " = icmp ne " + TypeToLLVM(eq.type) + " " + left.name + ", " + right.name);
        }
        eq.type = VarType(BaseType::I1);
        return eq;
    } else {
        std::cerr << "Error: Unknown eqExp!" << std::endl;
        exit(EXIT_FAILURE);
    }

}
std::any Analysis::visitEqOp(CactParser::EqOpContext *context) {
}
std::any Analysis::visitLAndExp(CactParser::LAndExpContext *context) {
    auto left = std::any_cast<LLVMValue>(visitEqExp(context->eqExp(0)));
    if (left.type.baseType != BaseType::I1) {
        std::string newleft = "%" + newSSA("land");
        currentBlock->addInstruction(newleft + " = icmp ne " + TypeToLLVM(left.type) + " " + left.name + ", 0");
        left.name = newleft;
        left.type = VarType(BaseType::I1); // convert to boolean type
    }
    if (context->eqExp().size() == 1) {
        return left;
    }
    auto land = left;
    std::string finalLabel = newLabel("land_final");
    std::vector<std::pair<std::string, std::string>> phiSources;
    for (int i = 1; i < context->eqExp().size(); i++) {
        std::string nextLabel = newLabel("land_next");
        currentBlock->addInstruction("br i1 " + left.name + ", label %" + nextLabel + ", label %" + finalLabel);
        phiSources.emplace_back("false", currentBlock->label);
        currentBlock = new LLVMBasicBlock(nextLabel);
        currentFunction->addBasicBlock(currentBlock);

        auto right = std::any_cast<LLVMValue>(visitEqExp(context->eqExp(i)));
        if (right.type.baseType != BaseType::I1) {
            std::string newright = "%" + newSSA("land");
            currentBlock->addInstruction(newright + " = icmp ne " + TypeToLLVM(right.type) + " " + right.name + ", 0");
            right.name = newright;
            right.type = VarType(BaseType::I1); // convert to boolean type
        }
        land.name = "%" + newSSA("land");
        currentBlock->addInstruction(land.name + " = and i1 " + left.name + ", " + right.name);
        left = land;
    }
    currentBlock->addInstruction("br label %" + finalLabel);
    phiSources.emplace_back(land.name, currentBlock->label);
    currentBlock = new LLVMBasicBlock(finalLabel);
    std::string phiName = "%" + newSSA("land_phi");
    std::stringstream phiSS;
    phiSS << phiName << " = phi i1 ";
    for (const auto &source : phiSources) {
        phiSS << "[" << source.first << ", %" << source.second << "]";
        if (&source != &phiSources.back()) {
            phiSS << ", ";
        }
    }
    currentBlock->addInstruction(phiSS.str());
    currentFunction->addBasicBlock(currentBlock);
    return LLVMValue(phiName, VarType(BaseType::I1));
}
std::any Analysis::visitLOrExp(CactParser::LOrExpContext *context) {
    auto left = std::any_cast<LLVMValue>(visitLAndExp(context->lAndExp(0)));
    if (left.type.baseType != BaseType::I1) {
        std::string newleft = "%" + newSSA("lor");
        currentBlock->addInstruction(newleft + " = icmp ne " + TypeToLLVM(left.type) + " " + left.name + ", 0");
        left.name = newleft;
        left.type = VarType(BaseType::I1); // convert to boolean type
    }
    if (context->lAndExp().size() == 1) {
        return left;
    }
    auto lor = left;
    std::string finalLabel = newLabel("lor_final");
    std::vector<std::pair<std::string, std::string>> phiSources;
    for (int i = 1; i < context->lAndExp().size(); i++) {
        std::string nextLabel = newLabel("lor_next");
        currentBlock->addInstruction("br i1 " + left.name + ", label %" + finalLabel + ", label %" + nextLabel);
        phiSources.emplace_back("true", currentBlock->label);
        currentBlock = new LLVMBasicBlock(nextLabel);
        currentFunction->addBasicBlock(currentBlock);

        auto right = std::any_cast<LLVMValue>(visitLAndExp(context->lAndExp(i)));
        if (right.type.baseType != BaseType::I1) {
            std::string newright = "%" + newSSA("lor");
            currentBlock->addInstruction(newright + " = icmp ne " + TypeToLLVM(right.type) + " " + right.name + ", 0");
            right.name = newright;
            right.type = VarType(BaseType::I1); // convert to boolean type
        }
        lor.name = "%" + newSSA("lor");
        currentBlock->addInstruction(lor.name + " = or i1 " + left.name + ", " + right.name);
        left = lor;
    }
    currentBlock->addInstruction("br label %" + finalLabel);
    phiSources.emplace_back(lor.name, currentBlock->label);
    currentBlock = new LLVMBasicBlock(finalLabel);
    currentFunction->addBasicBlock(currentBlock);
    std::string phiName = "%" + newSSA("lor_phi");
    std::stringstream phiSS;
    phiSS << phiName << " = phi i1 ";
    for (const auto &source : phiSources) {
        phiSS << "[" << source.first << ", %" << source.second << "]";
        if (&source != &phiSources.back()) {
            phiSS << ", ";
        }
    }
    currentBlock->addInstruction(phiSS.str());
    return LLVMValue(phiName, VarType(BaseType::I1));
}
std::any Analysis::visitIntConst(CactParser::IntConstContext *context) {
    if (context->DECIMAL_CONST()) {
        return context->DECIMAL_CONST()->getText();
    } else if (context->OCTAL_CONST()) {
        std::string octal = context->OCTAL_CONST()->getText();
        int decimal = std::stoi(octal, nullptr, 8);
        return std::to_string(decimal);
    } else if (context->HEXADECIMAL_CONST()) {
        std::string hex = context->HEXADECIMAL_CONST()->getText();
        int decimal = std::stoi(hex, nullptr, 16);
        return std::to_string(decimal);
    } else {
        std::cerr << "Error: Unknown integer constant!" << std::endl;
        exit(EXIT_FAILURE);
    }
}
std::any Analysis::visitBoolConst(CactParser::BoolConstContext *context) {
    if (context->TRUE()) {
        return LLVMValue("1", VarType(BaseType::I1, true /*is Const*/));
    } else if (context->FALSE()) {
        return LLVMValue("0", VarType(BaseType::I1, true /*is Const*/));
    } else {
        std::cerr << "Error: Unknown boolean constant!" << std::endl;
        exit(EXIT_FAILURE);
    }
}
std::any Analysis::visitErrorNode(tree::ErrorNode *node) {
    std::cout << "visit error node!" << std::endl;
    return nullptr;
}
std::string Analysis::newLabel(const std::string &prefix) {
    return prefix + std::to_string(labelCounter++);
}

std::string Analysis::newSSA(const std::string &prefix) {
    return prefix + std::to_string(ssaCounter++);
}
void Analysis::addBuiltinFunc() {
    std::vector<std::string> paramsT;
    paramsT.push_back("i32");
    currentSymbolTable->define(Symbol("print_int", VarType(BaseType::VOID, false, true), ("print_int"), paramsT));
    paramsT.clear();
    paramsT.push_back("float");
    currentSymbolTable->define(Symbol("print_float", VarType(BaseType::VOID, false, true), ("print_float"), paramsT));
    paramsT.clear();
    paramsT.push_back("i8");
    currentSymbolTable->define(Symbol("print_char", VarType(BaseType::VOID, false, true), ("print_char"), paramsT));
    paramsT.clear();
    currentSymbolTable->define(Symbol("get_int", VarType(BaseType::I32, false, true), ("get_int"), paramsT));
    currentSymbolTable->define(Symbol("get_float", VarType(BaseType::FLOAT, false, true), ("get_float"), paramsT));
    currentSymbolTable->define(Symbol("get_char", VarType(BaseType::I8, false, true), ("get_char"), paramsT));

    LLVMGlobalVar print_int("print_int", VarType(BaseType::VOID, false, true), "i32", false);
    LLVMGlobalVar print_float("print_float", VarType(BaseType::VOID, false, true), "float", false);
    LLVMGlobalVar print_char("print_char", VarType(BaseType::VOID, false, true), "i8", false);
    LLVMGlobalVar get_int("get_int", VarType(BaseType::I32, false, true), "", false);
    LLVMGlobalVar get_float("get_float", VarType(BaseType::FLOAT, false, true), "", false);
    LLVMGlobalVar get_char("get_char", VarType(BaseType::I8, false, true), "", false);
    llvmmodule.addGlobalVar(print_int);
    llvmmodule.addGlobalVar(print_float);
    llvmmodule.addGlobalVar(print_char);
    llvmmodule.addGlobalVar(get_int);
    llvmmodule.addGlobalVar(get_float);
    llvmmodule.addGlobalVar(get_char);
}