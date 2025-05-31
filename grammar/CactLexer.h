
    #include <vector>


// Generated from Cact.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  CactLexer : public antlr4::Lexer {
public:
  enum {
    CONST_KW = 1, INT_KW = 2, DOUBLE_KW = 3, CHAR_KW = 4, FLOAT_KW = 5, 
    BOOL_KW = 6, VOID_KW = 7, IF_KW = 8, ELSE_KW = 9, WHILE_KW = 10, BREAK_KW = 11, 
    CONTINUE_KW = 12, RETURN_KW = 13, FALSE = 14, TRUE = 15, IDENT = 16, 
    DECIMAL_CONST = 17, OCTAL_CONST = 18, HEXADECIMAL_CONST = 19, FloatConst = 20, 
    EXPONENT = 21, CharConst = 22, STRING = 23, PLUS = 24, MINUS = 25, NOT = 26, 
    MUL = 27, DIV = 28, MOD = 29, ASSIGN = 30, EQ = 31, NEQ = 32, GT = 33, 
    LT = 34, GE = 35, LE = 36, AND = 37, OR = 38, L_PAREN = 39, R_PAREN = 40, 
    L_BRACE = 41, R_BRACE = 42, L_BRACKET = 43, R_BRACKET = 44, COMMA = 45, 
    SEMICOLON = 46, DOUBLE_QUOTE = 47, WS = 48, LineComment = 49, BlockComment = 50
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

