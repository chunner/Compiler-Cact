
    #include <vector>


// Generated from Cact.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "CactListener.h"


/**
 * This class provides an empty implementation of CactListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CactBaseListener : public CactListener {
public:

  virtual void enterProgram(CactParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(CactParser::ProgramContext * /*ctx*/) override { }

  virtual void enterCompUnit(CactParser::CompUnitContext * /*ctx*/) override { }
  virtual void exitCompUnit(CactParser::CompUnitContext * /*ctx*/) override { }

  virtual void enterDecl(CactParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(CactParser::DeclContext * /*ctx*/) override { }

  virtual void enterConstDecl(CactParser::ConstDeclContext * /*ctx*/) override { }
  virtual void exitConstDecl(CactParser::ConstDeclContext * /*ctx*/) override { }

  virtual void enterBType(CactParser::BTypeContext * /*ctx*/) override { }
  virtual void exitBType(CactParser::BTypeContext * /*ctx*/) override { }

  virtual void enterConstDef(CactParser::ConstDefContext * /*ctx*/) override { }
  virtual void exitConstDef(CactParser::ConstDefContext * /*ctx*/) override { }

  virtual void enterConstInitVal(CactParser::ConstInitValContext * /*ctx*/) override { }
  virtual void exitConstInitVal(CactParser::ConstInitValContext * /*ctx*/) override { }

  virtual void enterVarDecl(CactParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(CactParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterVarDef(CactParser::VarDefContext * /*ctx*/) override { }
  virtual void exitVarDef(CactParser::VarDefContext * /*ctx*/) override { }

  virtual void enterFuncDef(CactParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(CactParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterFuncType(CactParser::FuncTypeContext * /*ctx*/) override { }
  virtual void exitFuncType(CactParser::FuncTypeContext * /*ctx*/) override { }

  virtual void enterFuncFParams(CactParser::FuncFParamsContext * /*ctx*/) override { }
  virtual void exitFuncFParams(CactParser::FuncFParamsContext * /*ctx*/) override { }

  virtual void enterFuncFParam(CactParser::FuncFParamContext * /*ctx*/) override { }
  virtual void exitFuncFParam(CactParser::FuncFParamContext * /*ctx*/) override { }

  virtual void enterBlock(CactParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(CactParser::BlockContext * /*ctx*/) override { }

  virtual void enterBlockItem(CactParser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(CactParser::BlockItemContext * /*ctx*/) override { }

  virtual void enterStmt(CactParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(CactParser::StmtContext * /*ctx*/) override { }

  virtual void enterExp(CactParser::ExpContext * /*ctx*/) override { }
  virtual void exitExp(CactParser::ExpContext * /*ctx*/) override { }

  virtual void enterConstExp(CactParser::ConstExpContext * /*ctx*/) override { }
  virtual void exitConstExp(CactParser::ConstExpContext * /*ctx*/) override { }

  virtual void enterCond(CactParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(CactParser::CondContext * /*ctx*/) override { }

  virtual void enterLVal(CactParser::LValContext * /*ctx*/) override { }
  virtual void exitLVal(CactParser::LValContext * /*ctx*/) override { }

  virtual void enterNumber(CactParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(CactParser::NumberContext * /*ctx*/) override { }

  virtual void enterFuncRParams(CactParser::FuncRParamsContext * /*ctx*/) override { }
  virtual void exitFuncRParams(CactParser::FuncRParamsContext * /*ctx*/) override { }

  virtual void enterPrimaryExp(CactParser::PrimaryExpContext * /*ctx*/) override { }
  virtual void exitPrimaryExp(CactParser::PrimaryExpContext * /*ctx*/) override { }

  virtual void enterUnaryExp(CactParser::UnaryExpContext * /*ctx*/) override { }
  virtual void exitUnaryExp(CactParser::UnaryExpContext * /*ctx*/) override { }

  virtual void enterUnaryOp(CactParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(CactParser::UnaryOpContext * /*ctx*/) override { }

  virtual void enterMulExp(CactParser::MulExpContext * /*ctx*/) override { }
  virtual void exitMulExp(CactParser::MulExpContext * /*ctx*/) override { }

  virtual void enterMulOp(CactParser::MulOpContext * /*ctx*/) override { }
  virtual void exitMulOp(CactParser::MulOpContext * /*ctx*/) override { }

  virtual void enterAddExp(CactParser::AddExpContext * /*ctx*/) override { }
  virtual void exitAddExp(CactParser::AddExpContext * /*ctx*/) override { }

  virtual void enterAddOp(CactParser::AddOpContext * /*ctx*/) override { }
  virtual void exitAddOp(CactParser::AddOpContext * /*ctx*/) override { }

  virtual void enterRelExp(CactParser::RelExpContext * /*ctx*/) override { }
  virtual void exitRelExp(CactParser::RelExpContext * /*ctx*/) override { }

  virtual void enterRelOp(CactParser::RelOpContext * /*ctx*/) override { }
  virtual void exitRelOp(CactParser::RelOpContext * /*ctx*/) override { }

  virtual void enterEqExp(CactParser::EqExpContext * /*ctx*/) override { }
  virtual void exitEqExp(CactParser::EqExpContext * /*ctx*/) override { }

  virtual void enterEqOp(CactParser::EqOpContext * /*ctx*/) override { }
  virtual void exitEqOp(CactParser::EqOpContext * /*ctx*/) override { }

  virtual void enterLAndExp(CactParser::LAndExpContext * /*ctx*/) override { }
  virtual void exitLAndExp(CactParser::LAndExpContext * /*ctx*/) override { }

  virtual void enterLOrExp(CactParser::LOrExpContext * /*ctx*/) override { }
  virtual void exitLOrExp(CactParser::LOrExpContext * /*ctx*/) override { }

  virtual void enterIntConst(CactParser::IntConstContext * /*ctx*/) override { }
  virtual void exitIntConst(CactParser::IntConstContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

