#include <iostream>

#include "antlr4-runtime.h"
// #include "tree/ErrorNode.h"

#include "CactLexer.h"
#include "CactParser.h"
#include "CactVisitor.h"
#include "CactBaseVisitor.h"


using namespace antlr4;

class Analysis : public CactBaseVisitor {
public:
    std::any visitProgram(CactParser::ProgramContext *context) {
        // visitChildren( context );
        
        std::cout << "enter rule [Program]!" << std::endl;
       // std::cout << "the ID is: " << context->ID()->getText().c_str() << std::endl;
        return visitChildren( context );
    }
    std::any visitCompUnit(CactParser::CompUnitContext *context) {
        // visitChildren( context );
        
        std::cout << "enter rule [compUnit]!" << std::endl;
       // std::cout << "the ID is: " << context->ID()->getText().c_str() << std::endl;
        return visitChildren( context );
    }
    // decl
    std::any visitDecl(CactParser::DeclContext *context) {
        std::cout << "enter rule [decl]!" << std::endl;
        return visitChildren( context );
    }
    std::any visitConstDecl(CactParser::ConstDeclContext *context) {
        std::cout << "enter rule [constDecl]!" << std::endl;
        return visitChildren( context );
    }
    std::any visitConstDef(CactParser::ConstDefContext *context) {
        std::cout << "enter rule [constDef]!" << std::endl;
        std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
        return visitChildren( context );
    }
    std::any visitVarDecl(CactParser::VarDeclContext *context) {
        std::cout << "enter rule [varDecl]!" << std::endl;
        return visitChildren( context );
    }
    std::any visitVarDef(CactParser::VarDefContext *context) {
        std::cout << "enter rule [varDef]!" << std::endl;
        std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
        return visitChildren( context );
    }
    // func
    std::any visitFuncDef(CactParser::FuncDefContext *context) {
        std::cout << "enter rule [funcDef]!" << std::endl;
        std::cout << "the IDENT is: " << context->IDENT()->getText().c_str() << std::endl;
        return visitChildren( context );
    }
    std::any visitErrorNode(tree::ErrorNode * node) override {
        std::cout << "visit error node!" << std::endl;
        return nullptr;
    }
};

int main(int argc, const char* argv[]) {
  std::ifstream stream;
  stream.open(argv[1]);

  ANTLRInputStream         input(stream);
  CactLexer         lexer(&input);
  CommonTokenStream        tokens(&lexer);
  CactParser        parser(&tokens);

  Analysis visitor;
  visitor.visit( parser.program() );

  return 0;
}