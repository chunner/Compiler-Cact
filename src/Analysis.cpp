#include <Analysis.h>
std::any Analysis::visitProgram(CactParser::ProgramContext *context) {
    return visitCompUnit(context->compUnit());
}
std::any Analysis::visitCompUnit(CactParser::CompUnitContext *context) {
    currentSymbolTable = new SymbolTable(nullptr);
    isGlobal = true;
    return visitChildren(context);
}
std::any Analysis::visitDecl(CactParser::DeclContext *context) {
    return visitChildren(context);
}
std::any Analysis::visitConstDecl(CactParser::ConstDeclContext *context) {
    currentBType = std::any_cast<BaseType>(visitBType(context->bType()));
    for (const auto &it : context->constDef()) {
        visitConstDef(it);
    }
}
std::any Analysis::visitBType(CactParser::BTypeContext *context) {
    // std::cout << "enter rule [bType]!" << "\t";
    // std::cout << "the type is: " << context->getText().c_str() << std::endl;
    if (context->INT_KW()) return BaseType::INT;
    if (context->DOUBLE_KW()) return BaseType::DOUBLE;
    if (context->CHAR_KW()) return BaseType::CHAR;
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
    if (!dimSize.empty() && currentBType != BaseType::INT && currentBType != BaseType::FLOAT && currentBType != BaseType::CHAR) {
        std::cerr << "Error: array must be of type INT, FLOAT or CHAR!" << std::endl;
        exit(EXIT_FAILURE);
    }
    VarType currentT = VarType(currentBType, true /*is Const*/, false /*not function*/, dimSize);
    currentSymbolTable->define(Symbol(ident, currentT));
    // generate LLVM code
    if (isGlobal) {
        std::string initval = std::any_cast<std::string> (visitConstInitVal(context->constInitVal()));
        LLVMGlobalVar globalVar(ident, CactToLLVM(currentT), initval, true /* is Const*/);
        llvmmodule.addGlobalVar(globalVar);
    } else {
        std::stringstream ss;
        ss << "%" << ident << " = alloca " << CactToLLVM(currentT);
        currentBlock->addInstruction(ss.str());
        ss.str("");
        ss << "store " << CactToLLVM(currentT) << " " << context->constInitVal()->getText() << ", " << CactToLLVM(currentT) << "* %" << ident;
        currentBlock->addInstruction(ss.str());
    }
    return visitChildren(context);
}
// return the LLVM IR for the constant initialization value
std::any Analysis::visitConstInitVal(CactParser::ConstInitValContext *context) {
    if (context->number()) {
        return visitNumber(context->number());
    } else { // {{1, 2}, {2, 3}}
        std::vector<std::string> initVals;
        for (const auto &it : context->constInitVal()) {
            initVals.push_back(std::any_cast<std::string>(visitConstInitVal(it)));
        }
        if (initVals.empty()) {
            return std::string("zeroinitializer");
        }
        std::stringstream ss;
        ss << "[";
        for (size_t i = 0; i < initVals.size(); ++i) {
            

        }
    }
}
std::any Analysis::visitVarDecl(CactParser::VarDeclContext *context) {
    //std::cout << "enter rule [varDecl]!" << std::endl;
    currentBType = std::any_cast<BaseType>(visitBType(context->bType()));
    for (auto it : context->varDef()) {
        visitVarDef(it);
    }
    // return visitChildren(context);
}
std::any Analysis::visitVarDef(CactParser::VarDefContext *context) {
    // std::cout << "enter rule [varDef]!" << "\t";
    // std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
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
        dimSize.push_back(std::stoi(it->getText()));
    }
    VarType symbolType{ currentBType,false /*not Const*/,false /* not function*/, dimSize };
    Symbol symbol{ ident,symbolType };
    currentSymbolTable->define(symbol);
    // generate LLVM code
    if (isGlobal) {
        LLVMGlobalVar globalVar(ident, CactToLLVM(symbolType), context->constInitVal()->getText(), false /* is Const*/);
        llvmmodule.addGlobalVar(globalVar);
    } else {
        std::stringstream ss;
        ss << "%" << ident << " = alloca " << CactToLLVM(symbolType);
        currentBlock->addInstruction(ss.str());
        ss.str("");
        ss << "store " << CactToLLVM(symbolType) << " " << context->constInitVal()->getText() << ", " << CactToLLVM(symbolType) << "* %" << ident;
        currentBlock->addInstruction(ss.str());
    }
    return visitChildren(context);
}
std::any Analysis::visitFuncDef(CactParser::FuncDefContext *context) {
    // std::cout << "enter rule [funcDef]!" << "\t";
    // std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
    // return visitChildren(context);
    BaseType retT = std::any_cast<BaseType>(visitFuncType(context->funcType()));
    std::string ident = context->IDENT()->getText();
    // check if the identifier is already defined
    bool defined = currentSymbolTable->lookupInCurrentScope(ident, true /*is function*/);
    if (defined) {
        std::cerr << "Error: Identifier " << ident << " already defined!" << std::endl;
        exit(EXIT_FAILURE);
    }
    // add symbol to symbol table
    VarType symbolType = VarType(retT, false /*not Const*/, true /*is Function*/, std::vector<int>());
    Symbol symbol{ ident, symbolType };
    currentSymbolTable->define(symbol);
    // generate LLVM code
    std::vector<LLVMValue> parameters;
    if (context->funcFParams()) {
        parameters = std::move(std::any_cast<std::vector<LLVMValue>>(visitFuncFParams(context->funcFParams())));
    }
    LLVMFunction function(ident, CactToLLVM(symbolType), parameters);
    llvmmodule.addFunction(function);
    currentFunction = &function;
    LLVMBasicBlock block("entry");
    function.addBasicBlock(block);

    // visit the function body
    currentBlock = &block;
    isGlobal = false;
    currentSymbolTable = new SymbolTable(currentSymbolTable);
    visitBlock(context->block());
    isGlobal = true;
    currentSymbolTable = currentSymbolTable->getParent();
}
std::any Analysis::visitFuncType(CactParser::FuncTypeContext *context) {
    // std::cout << "enter rule [funcType]!" << std::endl;
    // return visitChildren(context);
    if (context->VOID_KW()) return BaseType::VOID;
    if (context->bType()) {
        return std::any_cast<BaseType>(visitBType(context->bType()));
    }
}
std::any Analysis::visitFuncFParams(CactParser::FuncFParamsContext *context) {
    // std::cout << "enter rule [funcFParams]!" << std::endl;
    // return visitChildren(context);
    std::vector<LLVMValue> params;
    for (const auto &it : context->funcFParam()) {
        params.push_back(std::any_cast<LLVMValue>(visitFuncFParam(it)));
    }
}
std::any Analysis::visitFuncFParam(CactParser::FuncFParamContext *context) {
    // std::cout << "enter rule [funcFParam]!" << "\t";
    // std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
    // return visitChildren(context);
    std::string ident = context->IDENT()->getText();
    BaseType baseT = std::any_cast<BaseType>(visitBType(context->bType()));
    std::vector<int> dimSize;
    for (int i = 0; i < context->intConst().size(); i++) {
        if (context->intConst(i) == nullptr) {
            dimSize.push_back(-1);
        } else {
            dimSize.push_back(std::stoi(context->intConst(i)->getText()));
        }
    }
    VarType varT = { baseT, false /*not Const*/, false /*not function*/ , dimSize };
    return LLVMValue(ident, CactToLLVM(varT));
}
std::any Analysis::visitBlock(CactParser::BlockContext *context) {
    // std::cout << "enter rule [block]!" << std::endl;
    // return visitChildren(context);
    for (const auto &it : context->blockItem()) {
        visitBlockItem(it);
    }
}
std::any Analysis::visitBlockItem(CactParser::BlockItemContext *context) {
    // std::cout << "enter rule [blockItem]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitStmt(CactParser::StmtContext *context) {
    // std::cout << "enter rule [stmt]!" << std::endl;
    // return visitChildren(context);
    if (context->lVal()) {  // lva = exp;
        std::string lval = std::any_cast<std::string> (visitLVal(context->lVal()));
        std::string rval = std::any_cast<std::string> (visitExp(context->exp()));
        std::stringstream ss;
        VarType lvalType = VarType(currentBType, false /*not Const*/, false /*not function*/, std::vector<int>());
        ss << "store " << CactToLLVM(lvalType) << " " << rval << ", " << CactToLLVM(lvalType) << "* %" << lval;
        currentBlock->addInstruction(ss.str());
    } else if (context->block()) { // block
        LLVMBasicBlock block(newLabel("block"));
        currentFunction->addBasicBlock(block);
        LLVMBasicBlock *oldBlock = currentBlock;
        currentBlock = &block;
        currentSymbolTable = new SymbolTable(currentSymbolTable);
        visitBlock(context->block());
        currentBlock = oldBlock;
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
        currentFunction->addBasicBlock(*thenBlock);
        currentBlock = thenBlock;
        visitStmt(context->stmt(0));
        currentBlock->addInstruction("br label %" + endLabel);

        // else
        if (context->ELSE_KW()) {
            LLVMBasicBlock *elseBlock = new LLVMBasicBlock(elseLabel);
            currentFunction->addBasicBlock(*elseBlock);
            currentBlock = elseBlock;
            visitStmt(context->stmt(1));
            currentBlock->addInstruction("br label %" + endLabel);
        }

        // end
        LLVMBasicBlock *endBlock = new LLVMBasicBlock(endLabel);
        currentFunction->addBasicBlock(*endBlock);
        currentBlock = endBlock;
    } else if (context->WHILE_KW()) { // while (cond) stmt
        std::string condLabel = newLabel("while_cond");
        std::string bodyLabel = newLabel("while_body");
        std::string endLabel = newLabel("while_end");

        curCondLabel = condLabel;
        curEndLabel = endLabel;
        // cond
        LLVMBasicBlock *condBlock = new LLVMBasicBlock(condLabel);
        currentFunction->addBasicBlock(*condBlock);
        currentBlock = condBlock;
        std::string cond = std::any_cast<std::string>(visitCond(context->cond()));
        std::stringstream ss;
        ss << "br i1 " << cond << ", label %" << bodyLabel << ", label %" << endLabel;
        currentBlock->addInstruction(ss.str());
        // body
        LLVMBasicBlock *bodyBlock = new LLVMBasicBlock(bodyLabel);
        currentFunction->addBasicBlock(*bodyBlock);
        currentBlock = bodyBlock;
        visitStmt(context->stmt(0));
        currentBlock->addInstruction("br label %" + condLabel);
        // end
        LLVMBasicBlock *endBlock = new LLVMBasicBlock(endLabel);
        currentFunction->addBasicBlock(*endBlock);
        currentBlock = endBlock;
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
        std::string ret = std::any_cast<std::string>(visitExp(context->exp()));
        currentBlock->addInstruction("ret " + currentFunction->returnType + " " + ret);
    } else { // exp?;
        if (context->exp()) {
            visit(context->exp());
        }
    }
}
std::any Analysis::visitExp(CactParser::ExpContext *context) {
    // std::cout << "enter rule [exp]!" << std::endl;
    // return visitChildren(context);
    return std::any_cast<std::string> (visitAddExp(context->addExp()));
}

std::any Analysis::visitCond(CactParser::CondContext *context) {
    // std::cout << "enter rule [cond]!" << std::endl;
    // return visitChildren(context);
    currentBType = BaseType::BOOL;
    return std::any_cast<std::string>(visitLOrExp(context->lOrExp()));
}
std::any Analysis::visitLVal(CactParser::LValContext *context) {
    // std::cout << "enter rule [lVal]!" << std::endl;
    // return visitChildren(context);
    std::string ident = context->IDENT()->getText();
    // check if the identifier is already defined
    Symbol *s = currentSymbolTable->lookup(ident);
    if (s == nullptr) {
        std::cerr << "Error: Identifier " << ident << " not defined!" << std::endl;
        exit(EXIT_FAILURE);
    }
    currentBType = s->type.baseType;
    if (s->type.isArray()) {
        std::string tmpid = ident;
        VarType tmpT = s->type;
        for (int i = 0; i < context->exp().size(); i++) {
            std::string index = std::any_cast<std::string>(visitExp(context->exp(i)));
            tmpid += index;
            std::stringstream ss;
            ss << "%" << ident << "_ptr" << " = " << "getelementptr inbounds " << CactToLLVM(tmpT) << ", " << CactToLLVM(tmpT) << "* %" << tmpid << ", " << "i32 0" << ", i32 " << index;
            currentBlock->addInstruction(ss.str());
            tmpT = VarType(tmpT.baseType, tmpT.isConst, tmpT.isFunction, std::vector<int>(tmpT.dimSizes.begin() + 1, tmpT.dimSizes.end()));
        }
        return tmpid + "_ptr";
    } else {
        return ident;
    }
}
// return the LLVM IR for the integer constant
std::any Analysis::visitNumber(CactParser::NumberContext *context) {
    if (context->intConst()) {
        return std::any_cast<std::string>(visitIntConst(context->intConst()));
    } else if (context->FloatConst()) {
        std::string floatConst = context->FloatConst()->getText();
        if (!floatConst.empty() && (floatConst.back() == 'f' || floatConst.back() == 'F')) {
            floatConst.pop_back();
        }
        return floatConst;
    } else if (context->EXPONENT()) {
        std::string exponent = context->EXPONENT()->getText();
        if (!exponent.empty() && (exponent.back() == 'f' || exponent.back() == 'F')) {
            exponent.pop_back();
        }
        return exponent;
    } else if (context->CharConst()) {
        std::string ch = context->CharConst()->getText();
        if (ch.size() == 3 && ch.front() == '\'' && ch.back() == '\'') {
            int val = static_cast<int>(ch[1]);
            return std::to_string(val);
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
            return std::to_string(val);
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
    // std::cout << "enter rule [funcRParams]!" << std::endl;
    // return visitChildren(context);
    std::stringstream ss;
    for (int i = 0; i < context->exp().size(); i++) {
        std::string param = std::any_cast<std::string>(visitExp(context->exp(i)));
        ss << param;
        if (i != context->exp().size() - 1) {
            ss << ", ";
        }
    }
    return ss.str();
}
std::any Analysis::visitPrimaryExp(CactParser::PrimaryExpContext *context) {
    // std::cout << "enter rule [primaryExp]!" << std::endl;
    // return visitChildren(context);
    if (context->exp()) {
        return std::any_cast<std::string>(visitExp(context->exp()));
    } else if (context->lVal()) {
        return std::any_cast<std::string>(visitLVal(context->lVal()));
    } else if (context->number()) {
        return std::any_cast<std::string>(visitNumber(context->number()));
    }
}
std::any Analysis::visitUnaryExp(CactParser::UnaryExpContext *context) {
    // std::cout << "enter rule [unaryExp]!" << std::endl;
    // return visitChildren(context);
    if (context->primaryExp()) {
        return std::any_cast<std::string>(visitPrimaryExp(context->primaryExp()));
    } else if (context->unaryOp() && context->unaryExp()) {
        if (context->unaryOp()->PLUS()) {
            return std::any_cast<std::string>(visitUnaryExp(context->unaryExp()));
        } else if (context->unaryOp()->MINUS()) {
            std::string right = std::any_cast<std::string>(visitUnaryExp(context->unaryExp()));
            std::string neg = newSSA("neg");
            std::stringstream ss;
            ss << "%" << neg << " = sub " << CactToLLVM(VarType(currentBType)) << " 0, " << right;
            currentBlock->addInstruction(ss.str());
            return neg;
        } else if (context->unaryOp()->NOT()) {
            std::string right = std::any_cast<std::string>(visitUnaryExp(context->unaryExp()));
            std::string notssa = newSSA("not");
            std::stringstream ss;
            ss << "%" << notssa << " = icmp eq " << CactToLLVM(VarType(currentBType)) << " " << right << ", 0";
            currentBlock->addInstruction(ss.str());
            return notssa;
        } else {
            std::cerr << "Error: Unknown unary operator!" << std::endl;
            exit(EXIT_FAILURE);
        }
    } else if (context->IDENT()) {
        std::string ident = context->IDENT()->getText();
        // check if the identifier is already defined
        Symbol *s = currentSymbolTable->lookup(ident, true /*is function*/);
        if (s == nullptr) {
            std::cerr << "Error: Identifier " << ident << " not defined!" << std::endl;
            exit(EXIT_FAILURE);
        }
        // TODO : call a function
        std::string funcret = newSSA("ret");
        std::stringstream ss;
        ss << "%" << funcret << " = call " << CactToLLVM(VarType(currentBType)) << " @" << ident << "(";
        if (context->funcRParams()) {
            std::string params = std::any_cast<std::string>(visitFuncRParams(context->funcRParams()));
            ss << params;
        }
        ss << ")";
        currentBlock->addInstruction(ss.str());
        return funcret;
    } else {
        std::cerr << "Error: Unknown unary expression!" << std::endl;
        exit(EXIT_FAILURE);
    }
}
std::any Analysis::visitUnaryOp(CactParser::UnaryOpContext *context) {
    return;
}
std::any Analysis::visitMulExp(CactParser::MulExpContext *context) {
    // std::cout << "enter rule [mulExp]!" << std::endl;
    // return visitChildren(context);
    std::string left = std::any_cast<std::string>(visitUnaryExp(context->unaryExp(0)));
    std::stringstream ss;
    std::string mul = left;
    for (int i = 1; i < context->unaryExp().size(); i++) {
        std::string right = std::any_cast<std::string>(visitUnaryExp(context->unaryExp(i)));
        mul = newSSA("mul");
        if (context->mulOp(i - 1)->MUL()) {
            ss << "%" << mul << " = mul " << CactToLLVM(VarType(currentBType)) << " " << left << ", " << right;
        } else if (context->mulOp(i - 1)->DIV()) {
            ss << "%" << mul << " = sdiv " << CactToLLVM(VarType(currentBType)) << " " << left << ", " << right;
        } else if (context->mulOp(i - 1)->MOD()) {
            ss << "%" << mul << " = srem " << CactToLLVM(VarType(currentBType)) << " " << left << ", " << right;
        }
        currentBlock->addInstruction(ss.str());
        ss.str("");
        left = mul;
    }
    return mul;
}
std::any Analysis::visitMulOp(CactParser::MulOpContext *context) {
    std::cout << "enter rule [mulOp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitAddExp(CactParser::AddExpContext *context) {
    // std::cout << "enter rule [addExp]!" << std::endl;
    // return visitChildren(context);
    std::stringstream ss;
    std::string left = std::any_cast<std::string>(visitMulExp(context->mulExp(0)));
    std::string sum = left;
    for (int i = 1; i < context->mulExp().size(); i++) {
        std::string right = std::any_cast<std::string>(visitMulExp(context->mulExp(i)));
        sum = newSSA("sum");
        if (context->addOp(i - 1)->PLUS()) {
            ss << "%" << sum << " = add " << CactToLLVM(VarType(currentBType)) << " " << left << ", " << right;
        } else if (context->addOp(i - 1)->MINUS()) {
            ss << "%" << sum << " = sub " << CactToLLVM(VarType(currentBType)) << " " << left << ", " << right;
        }
        currentBlock->addInstruction(ss.str());
        ss.str("");
        left = sum;
    }
    return sum;
}
std::any Analysis::visitAddOp(CactParser::AddOpContext *context) {
    std::cout << "enter rule [addOp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitRelExp(CactParser::RelExpContext *context) {
    // std::cout << "enter rule [relExp]!" << std::endl;
    // return visitChildren(context);
    std::string left = std::any_cast<std::string>(visitAddExp(context->addExp(0)));
    std::string rel = left;
    if (context->addExp().size() == 1) {
        return rel;
    } else if (context->addExp().size() == 2) {
        std::string right = std::any_cast<std::string>(visitAddExp(context->addExp(1)));
        rel = newSSA("rel");
        if (context->relOp()->LT()) {
            currentBlock->addInstruction("%" + rel + " = icmp slt " + CactToLLVM(VarType(currentBType)) + " " + left + ", " + right);
        } else if (context->relOp()->GT()) {
            currentBlock->addInstruction("%" + rel + " = icmp sgt " + CactToLLVM(VarType(currentBType)) + " " + left + ", " + right);
        } else if (context->relOp()->LE()) {
            currentBlock->addInstruction("%" + rel + " = icmp sle " + CactToLLVM(VarType(currentBType)) + " " + left + ", " + right);
        } else if (context->relOp()->GE()) {
            currentBlock->addInstruction("%" + rel + " = icmp sge " + CactToLLVM(VarType(currentBType)) + " " + left + ", " + right);
        }
        return rel;
    } else {
        std::cerr << "Error: Unknown relExp!" << std::endl;
        exit(EXIT_FAILURE);
    }
}
std::any Analysis::visitRelOp(CactParser::RelOpContext *context) {
    std::cout << "enter rule [relOp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitEqExp(CactParser::EqExpContext *context) {
    // std::cout << "enter rule [eqExp]!" << std::endl;
    // return visitChildren(context);
    std::string left = std::any_cast<std::string>(visitRelExp(context->relExp(0)));
    std::string eq = left;
    if (context->relExp().size() == 1) {
        return eq;
    } else if (context->relExp().size() == 2) {
        std::string right = std::any_cast<std::string>(visitRelExp(context->relExp(1)));
        eq = newSSA("eq");
        currentBlock->addInstruction("%" + eq + " = icmp eq " + CactToLLVM(VarType(currentBType)) + " " + left + ", " + right);
        return eq;
    } else {
        std::cerr << "Error: Unknown eqExp!" << std::endl;
        exit(EXIT_FAILURE);
    }

}
std::any Analysis::visitEqOp(CactParser::EqOpContext *context) {
    std::cout << "enter rule [eqOp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitLAndExp(CactParser::LAndExpContext *context) {
    // std::cout << "enter rule [lAndExp]!" << std::endl;
    // return visitChildren(context);
    std::string left = std::any_cast<std::string>(visitEqExp(context->eqExp(0)));
    std::string land = left;
    for (int i = 1; i < context->eqExp().size(); i++) {
        std::string right = std::any_cast<std::string>(visitEqExp(context->eqExp(i)));
        land = newSSA("land");
        currentBlock->addInstruction("%" + land + " = and i1 " + left + ", " + right);
    }
    return land;
}
std::any Analysis::visitLOrExp(CactParser::LOrExpContext *context) {
    // std::cout << "enter rule [lOrExp]!" << std::endl;
    // return visitChildren(context);
    std::string left = std::any_cast<std::string>(visitLAndExp(context->lAndExp(0)));
    std::string lor = left;
    for (int i = 1; i < context->lAndExp().size(); i++) {
        std::string right = std::any_cast<std::string>(visitLAndExp(context->lAndExp(i)));
        lor = newSSA("lor");
        currentBlock->addInstruction("%" + lor + " = or i1 " + left + ", " + right);
    }
    return lor;
}
std::any Analysis::visitIntConst(CactParser::IntConstContext *context) {
    // std::cout << "enter rule [intConst]!" << std::endl;
    // return visitChildren(context);
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