
    #include <vector>


// Generated from Cact.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "CactParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CactParser.
 */
class  CactListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(CactParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(CactParser::ProgramContext *ctx) = 0;

  virtual void enterCompUnit(CactParser::CompUnitContext *ctx) = 0;
  virtual void exitCompUnit(CactParser::CompUnitContext *ctx) = 0;

  virtual void enterDecl(CactParser::DeclContext *ctx) = 0;
  virtual void exitDecl(CactParser::DeclContext *ctx) = 0;

  virtual void enterConstDecl(CactParser::ConstDeclContext *ctx) = 0;
  virtual void exitConstDecl(CactParser::ConstDeclContext *ctx) = 0;

  virtual void enterBType(CactParser::BTypeContext *ctx) = 0;
  virtual void exitBType(CactParser::BTypeContext *ctx) = 0;

  virtual void enterConstDef(CactParser::ConstDefContext *ctx) = 0;
  virtual void exitConstDef(CactParser::ConstDefContext *ctx) = 0;

  virtual void enterConstInitVal(CactParser::ConstInitValContext *ctx) = 0;
  virtual void exitConstInitVal(CactParser::ConstInitValContext *ctx) = 0;

  virtual void enterVarDecl(CactParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(CactParser::VarDeclContext *ctx) = 0;

  virtual void enterVarDef(CactParser::VarDefContext *ctx) = 0;
  virtual void exitVarDef(CactParser::VarDefContext *ctx) = 0;

  virtual void enterFuncDef(CactParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(CactParser::FuncDefContext *ctx) = 0;

  virtual void enterFuncType(CactParser::FuncTypeContext *ctx) = 0;
  virtual void exitFuncType(CactParser::FuncTypeContext *ctx) = 0;

  virtual void enterFuncFParams(CactParser::FuncFParamsContext *ctx) = 0;
  virtual void exitFuncFParams(CactParser::FuncFParamsContext *ctx) = 0;

  virtual void enterFuncFParam(CactParser::FuncFParamContext *ctx) = 0;
  virtual void exitFuncFParam(CactParser::FuncFParamContext *ctx) = 0;

  virtual void enterBlock(CactParser::BlockContext *ctx) = 0;
  virtual void exitBlock(CactParser::BlockContext *ctx) = 0;

  virtual void enterBlockItem(CactParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(CactParser::BlockItemContext *ctx) = 0;

  virtual void enterStmt(CactParser::StmtContext *ctx) = 0;
  virtual void exitStmt(CactParser::StmtContext *ctx) = 0;

  virtual void enterExp(CactParser::ExpContext *ctx) = 0;
  virtual void exitExp(CactParser::ExpContext *ctx) = 0;

  virtual void enterConstExp(CactParser::ConstExpContext *ctx) = 0;
  virtual void exitConstExp(CactParser::ConstExpContext *ctx) = 0;

  virtual void enterCond(CactParser::CondContext *ctx) = 0;
  virtual void exitCond(CactParser::CondContext *ctx) = 0;

  virtual void enterLVal(CactParser::LValContext *ctx) = 0;
  virtual void exitLVal(CactParser::LValContext *ctx) = 0;

  virtual void enterNumber(CactParser::NumberContext *ctx) = 0;
  virtual void exitNumber(CactParser::NumberContext *ctx) = 0;

  virtual void enterFuncRParams(CactParser::FuncRParamsContext *ctx) = 0;
  virtual void exitFuncRParams(CactParser::FuncRParamsContext *ctx) = 0;

  virtual void enterPrimaryExp(CactParser::PrimaryExpContext *ctx) = 0;
  virtual void exitPrimaryExp(CactParser::PrimaryExpContext *ctx) = 0;

  virtual void enterUnaryExp(CactParser::UnaryExpContext *ctx) = 0;
  virtual void exitUnaryExp(CactParser::UnaryExpContext *ctx) = 0;

  virtual void enterUnaryOp(CactParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(CactParser::UnaryOpContext *ctx) = 0;

  virtual void enterMulExp(CactParser::MulExpContext *ctx) = 0;
  virtual void exitMulExp(CactParser::MulExpContext *ctx) = 0;

  virtual void enterMulOp(CactParser::MulOpContext *ctx) = 0;
  virtual void exitMulOp(CactParser::MulOpContext *ctx) = 0;

  virtual void enterAddExp(CactParser::AddExpContext *ctx) = 0;
  virtual void exitAddExp(CactParser::AddExpContext *ctx) = 0;

  virtual void enterAddOp(CactParser::AddOpContext *ctx) = 0;
  virtual void exitAddOp(CactParser::AddOpContext *ctx) = 0;

  virtual void enterRelExp(CactParser::RelExpContext *ctx) = 0;
  virtual void exitRelExp(CactParser::RelExpContext *ctx) = 0;

  virtual void enterRelOp(CactParser::RelOpContext *ctx) = 0;
  virtual void exitRelOp(CactParser::RelOpContext *ctx) = 0;

  virtual void enterEqExp(CactParser::EqExpContext *ctx) = 0;
  virtual void exitEqExp(CactParser::EqExpContext *ctx) = 0;

  virtual void enterEqOp(CactParser::EqOpContext *ctx) = 0;
  virtual void exitEqOp(CactParser::EqOpContext *ctx) = 0;

  virtual void enterLAndExp(CactParser::LAndExpContext *ctx) = 0;
  virtual void exitLAndExp(CactParser::LAndExpContext *ctx) = 0;

  virtual void enterLOrExp(CactParser::LOrExpContext *ctx) = 0;
  virtual void exitLOrExp(CactParser::LOrExpContext *ctx) = 0;

  virtual void enterIntConst(CactParser::IntConstContext *ctx) = 0;
  virtual void exitIntConst(CactParser::IntConstContext *ctx) = 0;


};

