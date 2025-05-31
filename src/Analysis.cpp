#include <Analysis.h>
using namespace std;
std::any Analysis::visitProgram(CactParser::ProgramContext *context) {
    visitCompUnit(context->compUnit());
    return llvmmodule.toString();
}
std::any Analysis::visitCompUnit(CactParser::CompUnitContext *context) {
    currentSymbolTable = new SymbolTable(nullptr);
    isGlobal = true;
    return visitChildren(context);
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
    // std::cout << "enter rule [bType]!" << "\t";
    // std::cout << "the type is: " << context->getText().c_str() << std::endl;
    if (context->INT_KW()) return BaseType::I32;
    if (context->DOUBLE_KW()) return BaseType::DOUBLE;
    if (context->CHAR_KW()) return BaseType::I8;
    if (context->FLOAT_KW()) return BaseType::FLOAT;
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
    currentSymbolTable->define(Symbol(ident, currentT, newSSA(ident)));
    // generate LLVM code
    if (isGlobal) {
        auto initval = std::any_cast<std::pair<std::string, std::string>>(visitConstInitVal(context->constInitVal()));
        LLVMGlobalVar globalVar(ident, initval.first, initval.first + " " + initval.second, true /* is Const*/);
        llvmmodule.addGlobalVar(globalVar);
    } else {
        std::stringstream ss;
        ss << "%" << ident << " = alloca " << TypeToLLVM(currentT);
        currentBlock->addInstruction(ss.str());
        ss.str("");
        auto initval = std::any_cast<std::pair<std::string, std::string>>(visitConstInitVal(context->constInitVal()));
        if (!dimSize.empty()) {
            std::string globalid = newSSA("__const." + ident);
            LLVMGlobalVar globalVar(globalid, initval.first, initval.first + " " + initval.second, true /* is Const*/);
            llvmmodule.addGlobalVar(globalVar);
            std::string identcast = newSSA("cast." + ident);
            ss << "%" << identcast << " = bitcast " << TypeToLLVM(currentT) << "* " << "%" << ident << " to i8*";
            currentBlock->addInstruction(ss.str());
            ss << "";
            std::string globalcast = newSSA("cast." + globalid);
            ss << "%" << globalcast << " = bitcast " << TypeToLLVM(currentT) << "* @" << globalid << " to i8*";
            currentBlock->addInstruction(ss.str());
            ss << "";
            ss << "call void @llvm.memcpy.p0i8.p0i8.i32(i8* " << "%" << identcast << ", i8* " << "%" << globalcast << ", i32 " << currentT.getArraySize() << ", i1 false)";
            currentBlock->addInstruction(ss.str());
        } else {
            ss << "store " << initval.first << " " << initval.second << ", " << TypeToLLVM(currentBType) << "* %" << ident;
            currentBlock->addInstruction(ss.str());
        }
    }
    return 0;;
}
// return {value, type}
std::any Analysis::visitConstInitVal(CactParser::ConstInitValContext *context) {
    if (context->number()) {
        auto num = std::any_cast<std::pair<std::string, std::string>>(visitNumber(context->number()));
        std::string basellT = BTypeToLLVM(currentBType);
        if (num.first != basellT) {
            std::cerr << "Error: Type mismatch in constant initialization! Expected " << basellT << ", got " << num.second << std::endl;
            exit(EXIT_FAILURE);
        }
        return std::make_pair(basellT, num.second); // return {type, value}
    } else { // {{{4,5},{6,7}}, {{1, 2}, {2, 3}}} -> [2 x [2 x [2 x i32]]] [[2 x [2 x i32]] [[2 x i32] [i32 4, i32 5], [2 x i32] [i32 6, i32 7]], [2 x [2 x i32]] [[2 x i32] [i32 1, i32 2], [2 x i32] [i32 2, i32 3]]
        std::vector<std::pair<std::string, std::string>> initVals;
        for (const auto &it : context->constInitVal()) {
            initVals.push_back(std::any_cast<std::pair<std::string, std::string>>(visitConstInitVal(it)));
        }
        std::string childT = initVals[0].second;
        std::string arrayT = "[" + std::to_string(initVals.size()) + " x " + childT + "]";
        std::stringstream ss;
        ss << "[";
        for (size_t i = 0; i < initVals.size(); ++i) {
            ss << initVals[i].first;
            if (i < initVals.size() - 1) {
                ss << ", ";
            }
        }
        ss << "]";
        return std::make_pair(arrayT, ss.str());
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
    currentSymbolTable->define(Symbol(ident, currentT, newSSA(ident)));
    // generate LLVM code
    if (isGlobal) {
        if (context->constInitVal()) {
            auto initval = std::any_cast<std::pair<std::string, std::string>>(visitConstInitVal(context->constInitVal()));
            LLVMGlobalVar globalVar(ident, initval.first, initval.first + " " + initval.second, false /* not Const*/);
            llvmmodule.addGlobalVar(globalVar);
        } else {
            LLVMGlobalVar globalVar(ident, TypeToLLVM(currentT), "", false /* not Const*/);
            llvmmodule.addGlobalVar(globalVar);
        }
    } else {
        std::stringstream ss;
        ss << "%" << ident << " = alloca " << TypeToLLVM(currentT);
        currentBlock->addInstruction(ss.str());
        ss.str("");
        if (context->constInitVal()) {
            auto initval = std::any_cast<std::pair<std::string, std::string>>(visitConstInitVal(context->constInitVal()));
            if (!dimSize.empty()) {
                std::string globalid = newSSA("__const." + ident);
                LLVMGlobalVar globalVar(globalid, initval.first, initval.first + " " + initval.second, false /* not Const*/);
                llvmmodule.addGlobalVar(globalVar);
                std::string identcast = newSSA("cast." + ident);
                ss << "%" << identcast << " = bitcast " << TypeToLLVM(currentT) << "* " << "%" << ident << " to i8*";
                currentBlock->addInstruction(ss.str());
                ss.str("");
                std::string globalcast = newSSA("cast." + globalid);
                ss << "%" << globalcast << " = bitcast " << TypeToLLVM(currentT) << "* @" << globalid << " to i8*";
                currentBlock->addInstruction(ss.str());
                ss.str("");
                ss << "call void @llvm.memcpy.p0i8.p0i8.i32(i8* " << "%" << identcast << ", i8* " << "%" << globalcast << ", i32 " << currentT.getArraySize() << ", i1 false)";
                currentBlock->addInstruction(ss.str());
            } else {
                ss << "store " << initval.first << " " << initval.second << ", " << BTypeToLLVM(currentBType) << "* %" << ident;
                currentBlock->addInstruction(ss.str());
            }
        }
    }
    return 0;
}
std::any Analysis::visitFuncDef(CactParser::FuncDefContext *context) {
    BaseType retBT = std::any_cast<BaseType>(visitFuncType(context->funcType()));
    std::string ident = context->IDENT()->getText();
    // check if the identifier is already defined
    bool defined = currentSymbolTable->lookupInCurrentScope(ident, true /*is function*/);
    if (defined) {
        std::cerr << "Error: Identifier " << ident << " already defined!" << std::endl;
        exit(EXIT_FAILURE);
    }
    // add symbol to symbol table
    VarType retT = VarType(retBT, false /*not Const*/, true /*is Function*/);
    currentSymbolTable->define(Symbol(ident, retT, newSSA(ident)));
    // generate LLVM code
    std::vector<LLVMValue> parameters;
    if (context->funcFParams()) {
        parameters = std::move(std::any_cast<std::vector<LLVMValue>>(visitFuncFParams(context->funcFParams())));
    }
    LLVMFunction *function = new LLVMFunction(ident, BTypeToLLVM(retBT), parameters);
    currentFunction = function;
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
        ss << "store " << TypeToLLVM(parameters[i].type) << " %" << parameters[i].name << ", " << TypeToLLVM(parameters[i].type) << "* %" << parameters[i].name;
        currentBlock->addInstruction(ss.str());
        currentSymbolTable->define(Symbol(parameters[i].name, parameters[i].type, newSSA(parameters[i].name)));
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
std::any Analysis::visitStmt(CactParser::StmtContext *context) {
    if (context->lVal()) {  // lva = exp;
        auto left_ptr = std::any_cast<std::pair<std::string, std::string>>(visitLVal(context->lVal()));
        auto right = std::any_cast<std::pair<std::string, std::string>>(visitExp(context->exp()));
        if (left_ptr.first != right.first) {
            std::cerr << "Error: Type mismatch in assignment! Expected " << left_ptr.first << ", got " << right.first << std::endl;
            exit(EXIT_FAILURE);
        }
        std::stringstream ss;
        ss << "store " << right.first << " " << right.second << ", " << left_ptr.first << "* " << left_ptr.second;
        currentBlock->addInstruction(ss.str());
    } else if (context->block()) { // block
        LLVMBasicBlock *block = new LLVMBasicBlock(newLabel("block"));
        // LLVMBasicBlock *oldBlock = currentBlock;
        currentBlock = block;
        currentSymbolTable = new SymbolTable(currentSymbolTable);
        visitBlock(context->block());
        currentFunction->addBasicBlock(block);
        // currentBlock = oldBlock;
        currentSymbolTable = currentSymbolTable->getParent();
    } else if (context->IF_KW()) { // if (cond) stmt else stmt
        std::string thenLabel = newLabel("then");
        std::string elseLabel = context->ELSE_KW() ? newLabel("else") : "";
        std::string endLabel = newLabel("ifend");
        std::string cond = std::any_cast<std::string>(visitCond(context->cond()));

        std::stringstream ss;
        if (context->ELSE_KW()) {
            ss << "br i1 " << cond << ", label %" << thenLabel << ", label %" << elseLabel;
        } else {
            ss << "br i1 " << cond << ", label %" << thenLabel << ", label %" << endLabel;
        }
        currentBlock->addInstruction(ss.str());
        // then
        LLVMBasicBlock *thenBlock = new LLVMBasicBlock(thenLabel);
        currentBlock = thenBlock;
        visitStmt(context->stmt(0));
        currentBlock->addInstruction("br label %" + endLabel);
        currentFunction->addBasicBlock(thenBlock);

        // else
        if (context->ELSE_KW()) {
            LLVMBasicBlock *elseBlock = new LLVMBasicBlock(elseLabel);
            currentBlock = elseBlock;
            visitStmt(context->stmt(1));
            currentBlock->addInstruction("br label %" + endLabel);
            currentFunction->addBasicBlock(elseBlock);
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
        currentBlock = condBlock;
        std::string cond = std::any_cast<std::string>(visitCond(context->cond()));
        std::stringstream ss;
        ss << "br i1 " << cond << ", label %" << bodyLabel << ", label %" << endLabel;
        currentBlock->addInstruction(ss.str());
        // body
        LLVMBasicBlock *bodyBlock = new LLVMBasicBlock(bodyLabel);
        currentFunction->addBasicBlock(bodyBlock);
        currentBlock = bodyBlock;
        visitStmt(context->stmt(0));
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
            auto ret = std::any_cast<std::pair<std::string, std::string>>(visitExp(context->exp()));
            if (currentFunction->returnType != ret.first && currentFunction->returnType != "void") {
                std::cerr << "Error: Type mismatch in return statement! Expected " << currentFunction->returnType << ", got " << ret.first << std::endl;
                exit(EXIT_FAILURE);
            }
            currentBlock->addInstruction("ret " + currentFunction->returnType + " " + ret.second);
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
    auto exp = std::any_cast<std::pair<std::string, std::string>>(visitLOrExp(context->lOrExp()));
    if (exp.first != "i1") {
        std::cerr << "Error: Condition expression must be of type i1!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return exp.second;
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
    std::string identssa = s->ssa;
    if (s->type.isArray()) {
        std::vector<std::string> index;
        for (int i = 0; i < context->exp().size(); i++) {
            auto exp = std::any_cast<std::pair<std::string, std::string>>(visitExp(context->exp(i)));
            if (exp.first != "i32") {
                std::cerr << "Error: Array index must be of type i32!" << std::endl;
                exit(EXIT_FAILURE);
            }
            index.push_back(exp.second);
        }
        std::string ptr = newSSA("ptr");
        std::stringstream ss;
        ss << "%" << ptr << " = getelementptr inbounds " << TypeToLLVM(s->type) << ", " << TypeToLLVM(s->type) << "* %" << identssa;
        ss << ", i32 0"; // base address
        for (const auto &idx : index) {
            ss << ", i32 " << idx; // add index
        }
        currentBlock->addInstruction(ss.str());
        return std::make_pair(TypeToLLVM(s->type), ptr);
    } else {
        return std::make_pair(BTypeToLLVM(s->type.baseType), "%" + identssa);
    }
}
// return the (LLVM type,LLVM value)
std::any Analysis::visitNumber(CactParser::NumberContext *context) {
    if (context->intConst()) {
        std::string intVal = std::any_cast<std::string>(visitIntConst(context->intConst()));
        return std::pair<std::string, std::string>{"i32", intVal};
    } else if (context->FloatConst()) {
        std::string floatConst = context->FloatConst()->getText();
        if (!floatConst.empty() && (floatConst.back() == 'f' || floatConst.back() == 'F')) {
            floatConst.pop_back();
        }
        return std::make_pair("float", floatConst);
    } else if (context->EXPONENT()) {
        std::string exponent = context->EXPONENT()->getText();
        if (!exponent.empty() && (exponent.back() == 'f' || exponent.back() == 'F')) {
            exponent.pop_back();
        }
        return std::make_pair("float", exponent);
    } else if (context->CharConst()) {
        std::string ch = context->CharConst()->getText();
        if (ch.size() == 3 && ch.front() == '\'' && ch.back() == '\'') {
            int val = static_cast<int>(ch[1]);
            return std::make_pair("i8", std::to_string(val));
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
            return std::make_pair("i8", std::to_string(val));
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
    std::stringstream ss;
    for (int i = 0; i < context->exp().size(); i++) {
        auto param = std::any_cast<std::pair<std::string, std::string>>(visitExp(context->exp(i)));
        ss << param.first << " " << param.second;
        if (i != context->exp().size() - 1) {
            ss << ", ";
        }
    }
    return ss.str();
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
                auto exp = std::any_cast<pair<std::string, std::string>>(visitExp(context->exp(i)));
                if (exp.first != "i32") {
                    std::cerr << "Error: Array index must be of type i32!" << std::endl;
                    exit(EXIT_FAILURE);
                }
                index.push_back(exp.second);
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
            ss<< load << " = load " << TypeToLLVM(s.first->type) << ", " << TypeToLLVM(s.first->type) << "* %" << ptr;
            currentBlock->addInstruction(ss.str());
            return std::make_pair(TypeToLLVM(s.first->type), load);
        } else {
            std::string load = "%" + newSSA("load");
            std::stringstream ss;
            ss<< load << " = load " << TypeToLLVM(s.first->type) << ", " << TypeToLLVM(s.first->type) << "* " << (s.second ? "@" : "%") << identssa;
            currentBlock->addInstruction(ss.str());
            return std::make_pair(TypeToLLVM(s.first->type), load);
        }
    } else if (context->number()) {
        return (visitNumber(context->number()));
    }
}
std::any Analysis::visitUnaryExp(CactParser::UnaryExpContext *context) {
    if (context->primaryExp()) {
        return visitPrimaryExp(context->primaryExp());
    } else if (context->unaryOp() && context->unaryExp()) { // unaryOp unaryExp
        if (context->unaryOp()->PLUS()) {
            return visitUnaryExp(context->unaryExp());
        } else if (context->unaryOp()->MINUS()) {
            auto right = std::any_cast<std::pair<std::string, std::string>>(visitUnaryExp(context->unaryExp()));
            std::string neg = "%" + newSSA("neg");
            std::stringstream ss;
            ss << neg << " = sub " << TypeToLLVM(VarType(currentBType)) << " 0, " << right.second;
            currentBlock->addInstruction(ss.str());
            return std::make_pair(right.first, neg);
        } else if (context->unaryOp()->NOT()) {
            auto right = std::any_cast<std::pair<std::string, std::string>> (visitUnaryExp(context->unaryExp()));
            if (right.first != "i1") {
                std::cerr << "Error: Type mismatch in unary NOT! Expected i1, got " << right.first << std::endl;
                exit(EXIT_FAILURE);
            }
            std::string notssa = "%" + newSSA("not");
            std::stringstream ss;
            ss << notssa << " = icmp eq " << TypeToLLVM(VarType(currentBType)) << " " << right.second << ", 0";
            currentBlock->addInstruction(ss.str());
            return std::make_pair("i1", notssa);
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
        std::string funcret = "%" + newSSA("ret");
        std::stringstream ss;
        ss << funcret << " = call " << TypeToLLVM(VarType(currentBType)) << " @" << ident << "(";
        if (context->funcRParams()) {
            std::string params = std::any_cast<std::string>(visitFuncRParams(context->funcRParams()));
            ss << params;
        }
        ss << ")";
        currentBlock->addInstruction(ss.str());
        if (s.first->type.baseType == BaseType::VOID) {
            return std::make_pair("", funcret);
        } else {
            return std::make_pair(TypeToLLVM(s.first->type), funcret);
        }
    } else {
        std::cerr << "Error: Unknown unary expression!" << std::endl;
        exit(EXIT_FAILURE);
    }
}
std::any Analysis::visitUnaryOp(CactParser::UnaryOpContext *context) {
}
std::any Analysis::visitMulExp(CactParser::MulExpContext *context) {
    auto left = std::any_cast<std::pair<std::string, std::string>>(visitUnaryExp(context->unaryExp(0)));
    auto mul = left;
    for (int i = 1; i < context->unaryExp().size(); i++) {
        auto right = std::any_cast<std::pair<std::string, std::string>>(visitUnaryExp(context->unaryExp(i))); // "llvmtype, llvmvalue"
        if (right.first != left.first) {
            std::cerr << "Error: Type mismatch in multiplication! Expected " << left.first << ", got " << right.first << std::endl;
            exit(EXIT_FAILURE);
        }
        mul.second = "%" + newSSA("mul");
        std::stringstream ss;
        if (right.first == "i32") {
            if (context->mulOp(i - 1)->MUL()) {
                ss << mul.second << " = mul " << left.first << " " << left.second << ", " << right.second;
            } else if (context->mulOp(i - 1)->DIV()) {
                ss << mul.second << " = sdiv " << left.first << " " << left.second << ", " << right.second;
            } else if (context->mulOp(i - 1)->MOD()) {
                ss << mul.second << " = srem " << left.first << " " << left.second << ", " << right.second;
            }
        } else if (right.first == "float") {
            if (context->mulOp(i - 1)->MUL()) {
                ss << mul.second << " = fmul " << left.first << " " << left.second << ", " << right.second;
            } else if (context->mulOp(i - 1)->DIV()) {
                ss << mul.second << " = fdiv " << left.first << " " << left.second << ", " << right.second;
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
    auto left = std::any_cast<std::pair<std::string, std::string>>(visitMulExp(context->mulExp(0)));
    auto sum = left;
    for (int i = 1; i < context->mulExp().size(); i++) {
        std::stringstream ss;
        auto right = std::any_cast<std::pair<std::string, std::string>>(visitMulExp(context->mulExp(i))); // "llvmtype, llvmvalue"
        if (right.first != sum.first) {
            std::cerr << "Error: Type mismatch in addition! Expected " << sum.first << ", got " << right.first << std::endl;
            exit(EXIT_FAILURE);
        }
        sum.second = "%" + newSSA("sum");
        if (context->addOp(i - 1)->PLUS()) {
            ss << sum.second << " = add " << left.first << " " << left.second << ", " << right.second;
        } else if (context->addOp(i - 1)->MINUS()) {
            ss << sum.second << " = sub " << left.first << " " << left.second << ", " << right.second;
        }
        currentBlock->addInstruction(ss.str());
        left = sum;
    }
    return sum;
}
std::any Analysis::visitAddOp(CactParser::AddOpContext *context) {
}
std::any Analysis::visitRelExp(CactParser::RelExpContext *context) {
    auto left = std::any_cast<std::pair<std::string, std::string>>(visitAddExp(context->addExp(0)));
    auto rel = left;
    if (context->addExp().size() == 1) {
        return rel;
    } else if (context->addExp().size() == 2) {
        auto right = std::any_cast<std::pair<std::string, std::string>>(visitAddExp(context->addExp(1)));
        if (left.first != right.first) {
            std::cerr << "Error: Type mismatch in relational expression! Expected " << left.first << ", got " << right.first << std::endl;
            exit(EXIT_FAILURE);
        }
        rel.second = newSSA("rel");
        if (context->relOp()->LT()) {
            currentBlock->addInstruction("%" + rel.second + " = icmp slt " + left.first + " " + left.second + ", " + right.second);
        } else if (context->relOp()->GT()) {
            currentBlock->addInstruction("%" + rel.second + " = icmp sgt " + left.first + " " + left.second + ", " + right.second);
        } else if (context->relOp()->GE()) {
            currentBlock->addInstruction("%" + rel.second + " = icmp sge " + left.first + " " + left.second + ", " + right.second);
        } else if (context->relOp()->LE()) {
            currentBlock->addInstruction("%" + rel.second + " = icmp sle " + left.first + " " + left.second + ", " + right.second);
        }
        rel.first = "i1";
        return rel;
    }
}
std::any Analysis::visitRelOp(CactParser::RelOpContext *context) {
}
std::any Analysis::visitEqExp(CactParser::EqExpContext *context) {
    auto left = std::any_cast<std::pair<std::string, std::string>>(visitRelExp(context->relExp(0)));
    auto eq = left;
    if (context->relExp().size() == 1) {
        return eq;
    } else if (context->relExp().size() == 2) {
        auto right = std::any_cast<std::pair<std::string, std::string>>(visitRelExp(context->relExp(1)));
        if (left.first != right.first) {
            std::cerr << "Error: Type mismatch in equality expression! Expected " << left.first << ", got " << right.first << std::endl;
            exit(EXIT_FAILURE);
        }
        eq.second = newSSA("eq");
        if (context->eqOp()->EQ()) {
            currentBlock->addInstruction("%" + eq.second + " = icmp eq " + eq.first + " " + left.second + ", " + right.second);
        } else if (context->eqOp()->NEQ()) {
            currentBlock->addInstruction("%" + eq.second + " = icmp ne " + eq.first + " " + left.second + ", " + right.second);
        }
        eq.first = "i1";
        return eq;
    } else {
        std::cerr << "Error: Unknown eqExp!" << std::endl;
        exit(EXIT_FAILURE);
    }

}
std::any Analysis::visitEqOp(CactParser::EqOpContext *context) {
}
std::any Analysis::visitLAndExp(CactParser::LAndExpContext *context) {
    auto left = std::any_cast<std::pair<string, std::string>>(visitEqExp(context->eqExp(0)));
    if (left.first != "i1") {
        std::cerr << "Error: Type mismatch in logical AND expression! Expected i1, got " << left.first << std::endl;
        exit(EXIT_FAILURE);
    }
    auto land = left;
    for (int i = 1; i < context->eqExp().size(); i++) {
        auto right = std::any_cast<std::pair<std::string, std::string>>(visitEqExp(context->eqExp(i)));
        if (left.first != right.first) {
            std::cerr << "Error: Type mismatch in logical AND expression! Expected " << left.first << ", got " << right.first << std::endl;
            exit(EXIT_FAILURE);
        }
        land.second = newSSA("land");
        currentBlock->addInstruction("%" + land.second + " = and i1 " + left.second + ", " + right.second);
    }
    return land;
}
std::any Analysis::visitLOrExp(CactParser::LOrExpContext *context) {
    auto left = std::any_cast<std::pair<std::string, std::string>>(visitLAndExp(context->lAndExp(0)));
    if (left.first != "i1") {
        std::cerr << "Error: Type mismatch in logical OR expression! Expected i1, got " << left.first << std::endl;
        exit(EXIT_FAILURE);
    }
    auto lor = left;
    for (int i = 1; i < context->lAndExp().size(); i++) {
        auto right = std::any_cast<std::pair<std::string, std::string>>(visitLAndExp(context->lAndExp(i)));
        lor.second = newSSA("lor");
        currentBlock->addInstruction("%" + lor.second + " = or i1 " + left.second + ", " + right.second);
    }
    return lor;
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