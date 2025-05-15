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
    if (currentSymbolTable->lookup(ident) != nullptr) {
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
    Symbol symbol{ident,symbolType};
    currentSymbolTable->define(symbol);
    // generate LLVM code
    if (isGlobal) {
        LLVMGlobalVar globalVar(ident, mapCactTypeToLLVM(symbolType), context->constInitVal()->getText(), true /* is Const*/);
        llvmmodule.addGlobalVar(globalVar);
    } else {
        std::stringstream ss;
        ss << "%" << ident << " = alloca " << mapCactTypeToLLVM(symbolType);
        currentBlock->addInstruction(ss.str());
        ss.str("");
        ss << "store " << mapCactTypeToLLVM(symbolType) << " " << context->constInitVal()->getText() << ", " << mapCactTypeToLLVM(symbolType) << "* %" << ident;
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
    if (currentSymbolTable->lookup(ident) != nullptr) {
        std::cerr << "Error: Identifier " << ident << " already defined!" << std::endl;
        exit(EXIT_FAILURE);
    }
    // add symbol to symbol table
    std::vector<int> dimSize;
    for (auto it : context->intConst()) {
        dimSize.push_back(std::stoi(it->getText()));
    }
    VarType symbolType{ currentType,false /*not Const*/,false /* not function*/, dimSize };
    Symbol symbol{ident,symbolType};
    currentSymbolTable->define(symbol);
    // generate LLVM code
    if (isGlobal) {
        LLVMGlobalVar globalVar(ident, mapCactTypeToLLVM(symbolType), context->constInitVal()->getText(), false /* is Const*/);
        llvmmodule.addGlobalVar(globalVar);
    } else {
        std::stringstream ss;
        ss << "%" << ident << " = alloca " << mapCactTypeToLLVM(symbolType);
        currentBlock->addInstruction(ss.str());
        ss.str("");
        ss << "store " << mapCactTypeToLLVM(symbolType) << " " << context->constInitVal()->getText() << ", " << mapCactTypeToLLVM(symbolType) << "* %" << ident;
        currentBlock->addInstruction(ss.str());
    }
    return visitChildren(context);
}
std::any Analysis::visitFuncDef(CactParser::FuncDefContext *context) {
    std::cout << "enter rule [funcDef]!" << "\t";
    std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitFuncType(CactParser::FuncTypeContext *context) {
    std::cout << "enter rule [funcType]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitFuncFParams(CactParser::FuncFParamsContext *context) {
    std::cout << "enter rule [funcFParams]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitFuncFParam(CactParser::FuncFParamContext *context) {
    std::cout << "enter rule [funcFParam]!" << "\t";
    std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitBlock(CactParser::BlockContext *context) {
    std::cout << "enter rule [block]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitBlockItem(CactParser::BlockItemContext *context) {
    std::cout << "enter rule [blockItem]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitStmt(CactParser::StmtContext *context) {
    std::cout << "enter rule [stmt]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitExp(CactParser::ExpContext *context) {
    std::cout << "enter rule [exp]!" << std::endl;
    return visitChildren(context);
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
    std::cout << "enter rule [lVal]!" << std::endl;
    return visitChildren(context);
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
    std::cout << "enter rule [unaryExp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitUnaryOp(CactParser::UnaryOpContext *context) {
    std::cout << "enter rule [unaryOp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitMulExp(CactParser::MulExpContext *context) {
    std::cout << "enter rule [mulExp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitMulOp(CactParser::MulOpContext *context) {
    std::cout << "enter rule [mulOp]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitAddExp(CactParser::AddExpContext *context) {
    std::cout << "enter rule [addExp]!" << std::endl;
    return visitChildren(context);
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