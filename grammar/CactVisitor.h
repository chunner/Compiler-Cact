
    #include <vector>


// Generated from Cact.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "CactParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CactParser.
 */
class  CactVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CactParser.
   */
    virtual std::any visitProgram(CactParser::ProgramContext *context) = 0;

    virtual std::any visitCompUnit(CactParser::CompUnitContext *context) = 0;

    virtual std::any visitDecl(CactParser::DeclContext *context) = 0;

    virtual std::any visitBType(CactParser::BTypeContext *context) = 0;

    virtual std::any visitConstDecl(CactParser::ConstDeclContext *context) = 0;

    virtual std::any visitConstDef(CactParser::ConstDefContext *context) = 0;

    virtual std::any visitConstInitVal(CactParser::ConstInitValContext *context) = 0;

    virtual std::any visitVarDecl(CactParser::VarDeclContext *context) = 0;

    virtual std::any visitVarDef(CactParser::VarDefContext *context) = 0;

    virtual std::any visitFuncDef(CactParser::FuncDefContext *context) = 0;

    virtual std::any visitFuncType(CactParser::FuncTypeContext *context) = 0;

    virtual std::any visitFuncFParams(CactParser::FuncFParamsContext *context) = 0;

    virtual std::any visitFuncFParam(CactParser::FuncFParamContext *context) = 0;

    virtual std::any visitBlock(CactParser::BlockContext *context) = 0;

    virtual std::any visitBlockItem(CactParser::BlockItemContext *context) = 0;

    virtual std::any visitStmt(CactParser::StmtContext *context) = 0;

    virtual std::any visitExp(CactParser::ExpContext *context) = 0;

    virtual std::any visitCond(CactParser::CondContext *context) = 0;

    virtual std::any visitLVal(CactParser::LValContext *context) = 0;

    virtual std::any visitNumber(CactParser::NumberContext *context) = 0;

    virtual std::any visitFuncRParams(CactParser::FuncRParamsContext *context) = 0;

    virtual std::any visitPrimaryExp(CactParser::PrimaryExpContext *context) = 0;

    virtual std::any visitUnaryExp(CactParser::UnaryExpContext *context) = 0;

    virtual std::any visitUnaryOp(CactParser::UnaryOpContext *context) = 0;

    virtual std::any visitMulExp(CactParser::MulExpContext *context) = 0;

    virtual std::any visitMulOp(CactParser::MulOpContext *context) = 0;

    virtual std::any visitAddExp(CactParser::AddExpContext *context) = 0;

    virtual std::any visitAddOp(CactParser::AddOpContext *context) = 0;

    virtual std::any visitRelExp(CactParser::RelExpContext *context) = 0;

    virtual std::any visitRelOp(CactParser::RelOpContext *context) = 0;

    virtual std::any visitEqExp(CactParser::EqExpContext *context) = 0;

    virtual std::any visitEqOp(CactParser::EqOpContext *context) = 0;

    virtual std::any visitLAndExp(CactParser::LAndExpContext *context) = 0;

    virtual std::any visitLOrExp(CactParser::LOrExpContext *context) = 0;

    virtual std::any visitIntConst(CactParser::IntConstContext *context) = 0;


};

