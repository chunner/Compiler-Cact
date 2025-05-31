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
void printParseTreeAdvanced(antlr4::tree::ParseTree* node, CactParser* parser, 
                           const std::string& prefix = "", bool isLast = true) {
    if (!node) return;
    
    // 打印当前节点
    std::cout << prefix;
    std::cout << (isLast ? "└── " : "├── ");
    
    if (auto* ruleNode = dynamic_cast<antlr4::ParserRuleContext*>(node)) {
        std::string ruleName = parser->getRuleNames()[ruleNode->getRuleIndex()];
        std::cout << ruleName << std::endl;
    } else if (auto* terminalNode = dynamic_cast<antlr4::tree::TerminalNode*>(node)) {
        std::string text = terminalNode->getText();
        std::cout << "\"" << text << "\"" << std::endl;
    }
    
    // 准备子节点的前缀
    std::string childPrefix = prefix + (isLast ? "    " : "│   ");
    
    // 递归打印子节点
    for (size_t i = 0; i < node->children.size(); ++i) {
        bool isLastChild = (i == node->children.size() - 1);
        printParseTreeAdvanced(node->children[i], parser, childPrefix, isLastChild);
    }
}
int main(int argc, const char *argv[]) {
    std::ifstream stream;
    stream.open(argv[1]);
    if (!stream.is_open()) {
        std::cerr << "Error opening file: " << argv[1] << std::endl;
        return 1;
    }

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
    printParseTreeAdvanced(tree, &parser);

    Analysis visitor;
    visitor.visit(tree);

    return 0;
}