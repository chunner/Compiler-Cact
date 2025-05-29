
    #include <vector>


// Generated from Cact.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "CactVisitor.h"


/**
 * This class provides an empty implementation of CactVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CactBaseVisitor : public CactVisitor {
public:

  virtual std::any visitProgram(CactParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompUnit(CactParser::CompUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl(CactParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBType(CactParser::BTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDecl(CactParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDef(CactParser::ConstDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstInitVal(CactParser::ConstInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(CactParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDef(CactParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDef(CactParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncType(CactParser::FuncTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFParams(CactParser::FuncFParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFParam(CactParser::FuncFParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(CactParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockItem(CactParser::BlockItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt(CactParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp(CactParser::ExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCond(CactParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLVal(CactParser::LValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(CactParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncRParams(CactParser::FuncRParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExp(CactParser::PrimaryExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExp(CactParser::UnaryExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOp(CactParser::UnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulExp(CactParser::MulExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulOp(CactParser::MulOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddExp(CactParser::AddExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddOp(CactParser::AddOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelExp(CactParser::RelExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelOp(CactParser::RelOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqExp(CactParser::EqExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqOp(CactParser::EqOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLAndExp(CactParser::LAndExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLOrExp(CactParser::LOrExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntConst(CactParser::IntConstContext *ctx) override {
    return visitChildren(ctx);
  }


};

