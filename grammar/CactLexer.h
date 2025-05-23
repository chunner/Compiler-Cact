
    #include <vector>


// Generated from Cact.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  CactLexer : public antlr4::Lexer {
public:
  enum {
    CONST_KW = 1, INT_KW = 2, DOUBLE_KW = 3, CHAR_KW = 4, FLOAT_KW = 5, 
    VOID_KW = 6, IF_KW = 7, ELSE_KW = 8, WHILE_KW = 9, BREAK_KW = 10, CONTINUE_KW = 11, 
    RETURN_KW = 12, IDENT = 13, DECIMAL_CONST = 14, OCTAL_CONST = 15, HEXADECIMAL_CONST = 16, 
    FloatConst = 17, EXPONENT = 18, CharConst = 19, STRING = 20, PLUS = 21, 
    MINUS = 22, NOT = 23, MUL = 24, DIV = 25, MOD = 26, ASSIGN = 27, EQ = 28, 
    NEQ = 29, GT = 30, LT = 31, GE = 32, LE = 33, AND = 34, OR = 35, L_PAREN = 36, 
    R_PAREN = 37, L_BRACE = 38, R_BRACE = 39, L_BRACKET = 40, R_BRACKET = 41, 
    COMMA = 42, SEMICOLON = 43, DOUBLE_QUOTE = 44, WS = 45, LineComment = 46, 
    BlockComment = 47
  };

  explicit CactLexer(antlr4::CharStream *input);

  ~CactLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

