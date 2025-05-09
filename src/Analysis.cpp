#include <Analysis.h>
std::any Analysis::visitProgram(CactParser::ProgramContext *context) {
    //std::cout << "enter rule [Program]!" << std::endl;
    // return visitChildren(context);
    return visitCompUnit(context->compUnit());
}
std::any Analysis::visitCompUnit(CactParser::CompUnitContext *context) {
    //std::cout << "enter rule [compUnit]!" << std::endl;
    currentSymbolTable = new SymbolTable(nullptr);
    return visitChildren(context);
}
std::any Analysis::visitDecl(CactParser::DeclContext *context) {
    //std::cout << "enter rule [decl]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitConstDecl(CactParser::ConstDeclContext *context) {
    // std::cout << "enter rule [constDecl]!" << std::endl;
    currentType = std::any_cast<std::string>(visitBType(context->bType()));
    for (auto it : context->constDef()) {
        visitConstDef(it);
    }
}
std::any Analysis::visitBType(CactParser::BTypeContext *context) {
    // std::cout << "enter rule [bType]!" << "\t";
    // std::cout << "the type is: " << context->getText().c_str() << std::endl;
    if (context->INT_KW()) return std::string("int");
    if (context->DOUBLE_KW()) return std::string("double");
    if (context->CHAR_KW()) return std::string("char");
    if (context->FLOAT_KW()) return std::string("float");
    std::cerr << "Error: Unknown type!" << std::endl;
    return std::string("unknown");
}
std::any Analysis::visitConstDef(CactParser::ConstDefContext *context) {
    // std::cout << "enter rule [constDef]!" << "\t";
    // std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
    std::string ident = context->IDENT()->getText();
    return visitChildren(context);
}
std::any Analysis::visitConstInitVal(CactParser::ConstInitValContext *context) {
    std::cout << "enter rule [constInitVal]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitVarDecl(CactParser::VarDeclContext *context) {
    std::cout << "enter rule [varDecl]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitVarDef(CactParser::VarDefContext *context) {
    std::cout << "enter rule [varDef]!" << "\t";
    std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
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
    std::cout << "enter rule [intConst]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitErrorNode(tree::ErrorNode *node) {
    std::cout << "visit error node!" << std::endl;
    return nullptr;
}