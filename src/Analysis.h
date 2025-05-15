#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <iostream>
#include <vector>
#include "antlr4-runtime.h"
// #include "tree/ErrorNode.h"

#include "CactLexer.h"
#include "CactParser.h"
#include "CactVisitor.h"
#include "CactBaseVisitor.h"

#include "SymbolTable.h"
#include "IRGenerator.h"
using namespace antlr4;

class Analysis : public CactVisitor {
public:
    SymbolTable *currentSymbolTable;
    bool isGlobal;

    // bool isConstant;
    BaseType currentType;

    LLVMModule llvmmodule;
    LLVMBasicBlock *currentBlock;

    int labelCounter = 0;

    std::any visitProgram(CactParser::ProgramContext *context) override;
    std::any visitCompUnit(CactParser::CompUnitContext *context) override;
    std::any visitDecl(CactParser::DeclContext *context) override;
    std::any visitBType(CactParser::BTypeContext *context) override;
    std::any visitConstDecl(CactParser::ConstDeclContext *context) override;
    std::any visitConstDef(CactParser::ConstDefContext *context) override;
    std::any visitConstInitVal(CactParser::ConstInitValContext *context) override;
    std::any visitVarDecl(CactParser::VarDeclContext *context) override;
    std::any visitVarDef(CactParser::VarDefContext *context) override;
    std::any visitFuncDef(CactParser::FuncDefContext *context) override;
    std::any visitFuncType(CactParser::FuncTypeContext *context) override;
    std::any visitFuncFParams(CactParser::FuncFParamsContext *context) override;
    std::any visitFuncFParam(CactParser::FuncFParamContext *context) override;
    std::any visitBlock(CactParser::BlockContext *context) override;
    std::any visitBlockItem(CactParser::BlockItemContext *context) override;
    std::any visitStmt(CactParser::StmtContext *context) override;
    std::any visitExp(CactParser::ExpContext *context) override;
    std::any visitConstExp(CactParser::ConstExpContext *context) override;
    std::any visitCond(CactParser::CondContext *context) override;
    std::any visitLVal(CactParser::LValContext *context) override;
    std::any visitNumber(CactParser::NumberContext *context) override;
    std::any visitFuncRParams(CactParser::FuncRParamsContext *context) override;
    std::any visitPrimaryExp(CactParser::PrimaryExpContext *context) override;
    std::any visitUnaryExp(CactParser::UnaryExpContext *context) override;
    std::any visitUnaryOp(CactParser::UnaryOpContext *context) override;
    std::any visitMulExp(CactParser::MulExpContext *context) override;
    std::any visitMulOp(CactParser::MulOpContext *context) override;
    std::any visitAddExp(CactParser::AddExpContext *context) override;
    std::any visitAddOp(CactParser::AddOpContext *context) override;
    std::any visitRelExp(CactParser::RelExpContext *context) override;
    std::any visitRelOp(CactParser::RelOpContext *context) override;
    std::any visitEqExp(CactParser::EqExpContext *context) override;
    std::any visitEqOp(CactParser::EqOpContext *context) override;
    std::any visitLAndExp(CactParser::LAndExpContext *context) override;
    std::any visitLOrExp(CactParser::LOrExpContext *context) override;
    std::any visitIntConst(CactParser::IntConstContext *context) override;
    std::any visitErrorNode(tree::ErrorNode *node) override;


    std::string newLabel(const std::string &prefix);
};

# endif