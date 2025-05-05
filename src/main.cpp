#include <iostream>

#include "antlr4-runtime.h"
// #include "tree/ErrorNode.h"

#include "CactLexer.h"
#include "CactParser.h"
#include "CactVisitor.h"
#include "CactBaseVisitor.h"
#include "Analysis.h"

using namespace antlr4;



class BailErrorListener : public antlr4::BaseErrorListener {
public:
    void syntaxError(antlr4::Recognizer *recognizer,
                     antlr4::Token *offendingSymbol,
                     size_t line,
                     size_t charPositionInLine,
                     const std::string &msg,
                     std::exception_ptr e) override {

        std::cerr << "Syntax Error at line " << line << ":" << charPositionInLine
                  << " - " << msg << std::endl;

        exit(EXIT_FAILURE);  // 错误发生时直接终止程序
    }
};

int main(int argc, const char *argv[]) {
    std::ifstream stream;
    stream.open(argv[1]);

    ANTLRInputStream         input(stream);
    CactLexer         lexer(&input);
    CommonTokenStream        tokens(&lexer);
    CactParser        parser(&tokens);

    // 移除默认错误监听器
    parser.removeErrorListeners();
    lexer.removeErrorListeners();

    // 添加自定义的终止型错误监听器
    parser.addErrorListener(new BailErrorListener());
    lexer.addErrorListener(new BailErrorListener());

    // === 获取语法树 ===
    CactParser::ProgramContext *tree = parser.program();

    // === 打印语法树结构 ===
    std::cout << "==== Parse Tree ====" << std::endl;
    std::cout << tree->toStringTree(&parser) << std::endl;

    Analysis visitor;
    visitor.visit(tree);

    return 0;
}