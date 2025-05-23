#include <Analysis.h>
std::any Analysis::visitProgram(CactParser::ProgramContext *context) {
    //std::cout << "enter rule [Program]!" << std::endl;
    // return visitChildren(context);
    return visitCompUnit(context->compUnit());
}
std::any Analysis::visitCompUnit(CactParser::CompUnitContext *context) {
    //std::cout << "enter rule [compUnit]!" << std::endl;
    currentSymbolTable = new SymbolTable(nullptr);
    isGlobal = true;
    return visitChildren(context);
}
std::any Analysis::visitDecl(CactParser::DeclContext *context) {
    //std::cout << "enter rule [decl]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitConstDecl(CactParser::ConstDeclContext *context) {
    // std::cout << "enter rule [constDecl]!" << std::endl;
    currentType = std::any_cast<BaseType>(visitBType(context->bType()));
    for (auto it : context->constDef()) {
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
    std::cerr << "Error: Unknown type!" << std::endl;
    exit(EXIT_FAILURE);
}
std::any Analysis::visitConstDef(CactParser::ConstDefContext *context) {
    // std::cout << "enter rule [constDef]!" << "\t";
    // std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
    // check if the identifier is already defined
    std::string ident = context->IDENT()->getText();
    bool defined = currentSymbolTable->lookupInCurrentScope(ident);
    if (defined) {
        std::cerr << "Error: Identifier " << ident << " already defined!" << std::endl;
        exit(EXIT_FAILURE);
        return nullptr;
    }
    // add symbol to symbol table
    std::vector<int> dimSize;
    for (auto it : context->intConst()) {
        dimSize.push_back(std::stoi(it->getText()));
    }
    VarType symbolType{ currentType,true /*is const*/,false /* not function*/, dimSize };
    Symbol symbol{ ident,symbolType };
    currentSymbolTable->define(symbol);
    // generate LLVM code
    if (isGlobal) {
        LLVMGlobalVar globalVar(ident, CactToLLVM(symbolType), context->constInitVal()->getText(), true /* is Const*/);
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
std::any Analysis::visitConstInitVal(CactParser::ConstInitValContext *context) {
    std::cout << "enter rule [constInitVal]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitVarDecl(CactParser::VarDeclContext *context) {
    //std::cout << "enter rule [varDecl]!" << std::endl;
    currentType = std::any_cast<BaseType>(visitBType(context->bType()));
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
    VarType symbolType{ currentType,false /*not Const*/,false /* not function*/, dimSize };
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
        VarType lvalType = VarType(currentType, false /*not Const*/, false /*not function*/, std::vector<int>());
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

    } else if (context->WHILE_KW()) { // while (cond) stmt

    } else if (context->BREAK_KW()) { // break

    } else if (context->CONTINUE_KW()) { // continue

    } else if (context->RETURN_KW()) { // return exp;
    } else { // exp?;
    }
}
std::any Analysis::visitExp(CactParser::ExpContext *context) {
    // std::cout << "enter rule [exp]!" << std::endl;
    // return visitChildren(context);
    return std::any_cast<std::string> (visitAddExp(context->addExp()));
}
std::any Analysis::visitConstExp(CactParser::ConstExpContext *context) {
    std::cout << "enter rule [constExp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitCond(CactParser::CondContext *context) {
    std::cout << "enter rule [cond]!" << std::endl;
    return visitChildren(context);
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
    currentType = s->type.baseType;
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
std::any Analysis::visitNumber(CactParser::NumberContext *context) {
    std::cout << "enter rule [number]!" << "\t";
    std::cout << "the number is: " << context->getText().c_str() << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitFuncRParams(CactParser::FuncRParamsContext *context) {
    std::cout << "enter rule [funcRParams]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitPrimaryExp(CactParser::PrimaryExpContext *context) {
    std::cout << "enter rule [primaryExp]!" << std::endl;
    return visitChildren(context);
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
            ss << "%" << neg << " = sub " << CactToLLVM(VarType(currentType)) << " 0, " << right;
            currentBlock->addInstruction(ss.str());
            return neg;
        } else if (context->unaryOp()->NOT()) {
            std::string right = std::any_cast<std::string>(visitUnaryExp(context->unaryExp()));
            std::string notssa = newSSA("not");
            std::stringstream ss;
            ss << "%" << notssa << " = icmp eq " << CactToLLVM(VarType(currentType)) << " " << right << ", 0";
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
            ss << "%" << mul << " = mul " << CactToLLVM(VarType(currentType)) << " " << left << ", " << right;
        } else if (context->mulOp(i - 1)->DIV()) {
            ss << "%" << mul << " = sdiv " << CactToLLVM(VarType(currentType)) << " " << left << ", " << right;
        } else if (context->mulOp(i - 1)->MOD()) {
            ss << "%" << mul << " = srem " << CactToLLVM(VarType(currentType)) << " " << left << ", " << right;
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
            ss << "%" << sum << " = add " << CactToLLVM(VarType(currentType)) << " " << left << ", " << right;
        } else if (context->addOp(i - 1)->MINUS()) {
            ss << "%" << sum << " = sub " << CactToLLVM(VarType(currentType)) << " " << left << ", " << right;
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
    std::cout << "enter rule [relExp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitRelOp(CactParser::RelOpContext *context) {
    std::cout << "enter rule [relOp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitEqExp(CactParser::EqExpContext *context) {
    std::cout << "enter rule [eqExp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitEqOp(CactParser::EqOpContext *context) {
    std::cout << "enter rule [eqOp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitLAndExp(CactParser::LAndExpContext *context) {
    std::cout << "enter rule [lAndExp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitLOrExp(CactParser::LOrExpContext *context) {
    std::cout << "enter rule [lOrExp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitIntConst(CactParser::IntConstContext *context) {
    // std::cout << "enter rule [intConst]!" << std::endl;
    return visitChildren(context);
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