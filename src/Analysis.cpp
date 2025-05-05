#include <Analysis.h>

// class Analysis : public CactVisitor {
// public:
//     std::any visitProgram(CactParser::ProgramContext *context) {
//         std::cout << "enter rule [Program]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitCompUnit(CactParser::CompUnitContext *context) {
//         std::cout << "enter rule [compUnit]!" << std::endl;
//         return visitChildren(context);
//     }
//     // decl
//     std::any visitDecl(CactParser::DeclContext *context) {
//         std::cout << "enter rule [decl]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitConstDecl(CactParser::ConstDeclContext *context) {
//         std::cout << "enter rule [constDecl]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitBType(CactParser::BTypeContext *context) {
//         std::cout << "enter rule [bType]!" << "\t";
//         std::cout << "the type is: " << context->getText().c_str() << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitConstDef(CactParser::ConstDefContext *context) {
//         std::cout << "enter rule [constDef]!" << "\t";
//         std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitConstInitVal(CactParser::ConstInitValContext *context) {
//         std::cout << "enter rule [constInitVal]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitVarDecl(CactParser::VarDeclContext *context) {
//         std::cout << "enter rule [varDecl]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitVarDef(CactParser::VarDefContext *context) {
//         std::cout << "enter rule [varDef]!" << "\t";
//         std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
//         return visitChildren(context);
//     }
//     // func
//     std::any visitFuncDef(CactParser::FuncDefContext *context) {
//         std::cout << "enter rule [funcDef]!" << "\t";
//         std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitFuncType(CactParser::FuncTypeContext *context) {
//         std::cout << "enter rule [funcType]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitFuncFParams(CactParser::FuncFParamsContext *context) {
//         std::cout << "enter rule [funcFParams]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitFuncFParam(CactParser::FuncFParamContext *context) {
//         std::cout << "enter rule [funcFParam]!" << "\t";
//         std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitBlock(CactParser::BlockContext *context) {
//         std::cout << "enter rule [block]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitBlockItem(CactParser::BlockItemContext *context) {
//         std::cout << "enter rule [blockItem]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitStmt(CactParser::StmtContext *context) {
//         std::cout << "enter rule [stmt]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitExp(CactParser::ExpContext *context) {
//         std::cout << "enter rule [exp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitConstExp(CactParser::ConstExpContext *context) {
//         std::cout << "enter rule [constExp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitCond(CactParser::CondContext *context) {
//         std::cout << "enter rule [cond]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitLVal(CactParser::LValContext *context) {
//         std::cout << "enter rule [lVal]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitNumber(CactParser::NumberContext *context) {
//         std::cout << "enter rule [number]!" << "\t";
//         std::cout << "the number is: " << context->getText().c_str() << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitFuncRParams(CactParser::FuncRParamsContext *context) {
//         std::cout << "enter rule [funcRParams]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitPrimaryExp(CactParser::PrimaryExpContext *context) {
//         std::cout << "enter rule [primaryExp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitUnaryExp(CactParser::UnaryExpContext *context) {
//         std::cout << "enter rule [unaryExp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitUnaryOp(CactParser::UnaryOpContext *context) {
//         std::cout << "enter rule [unaryOp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitMulExp(CactParser::MulExpContext *context) {
//         std::cout << "enter rule [mulExp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitMulOp(CactParser::MulOpContext *context) {
//         std::cout << "enter rule [mulOp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitAddExp(CactParser::AddExpContext *context) {
//         std::cout << "enter rule [addExp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitAddOp(CactParser::AddOpContext *context) {
//         std::cout << "enter rule [addOp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitRelExp(CactParser::RelExpContext *context) {
//         std::cout << "enter rule [relExp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitRelOp(CactParser::RelOpContext *context) {
//         std::cout << "enter rule [relOp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitEqExp(CactParser::EqExpContext *context) {
//         std::cout << "enter rule [eqExp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitEqOp(CactParser::EqOpContext *context) {
//         std::cout << "enter rule [eqOp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitLAndExp(CactParser::LAndExpContext *context) {
//         std::cout << "enter rule [lAndExp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitLOrExp(CactParser::LOrExpContext *context) {
//         std::cout << "enter rule [lOrExp]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitIntConst(CactParser::IntConstContext *context) {
//         std::cout << "enter rule [intConst]!" << std::endl;
//         return visitChildren(context);
//     }
//     std::any visitErrorNode(tree::ErrorNode *node) override {
//         std::cout << "visit error node!" << std::endl;
//         return nullptr;
// //     }
// }
std::any Analysis::visitProgram(CactParser::ProgramContext *context) {
    std::cout << "enter rule [Program]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitCompUnit(CactParser::CompUnitContext *context) {
    std::cout << "enter rule [compUnit]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitDecl(CactParser::DeclContext *context) {
    std::cout << "enter rule [decl]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitConstDecl(CactParser::ConstDeclContext *context) {
    std::cout << "enter rule [constDecl]!" << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitBType(CactParser::BTypeContext *context) {
    std::cout << "enter rule [bType]!" << "\t";
    std::cout << "the type is: " << context->getText().c_str() << std::endl;
    return visitChildren(context);
}
std::any Analysis::visitConstDef(CactParser::ConstDefContext *context) {
    std::cout << "enter rule [constDef]!" << "\t";
    std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
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