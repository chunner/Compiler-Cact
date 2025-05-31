
    #include <vector>


// Generated from Cact.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  CactLexer : public antlr4::Lexer {
public:
  enum {
    CONST_KW = 1, INT_KW = 2, DOUBLE_KW = 3, CHAR_KW = 4, FLOAT_KW = 5, 
    BOOL_KW = 6, VOID_KW = 7, IF_KW = 8, ELSE_KW = 9, WHILE_KW = 10, BREAK_KW = 11, 
    CONTINUE_KW = 12, RETURN_KW = 13, IDENT = 14, DECIMAL_CONST = 15, OCTAL_CONST = 16, 
    HEXADECIMAL_CONST = 17, FloatConst = 18, EXPONENT = 19, CharConst = 20, 
    STRING = 21, PLUS = 22, MINUS = 23, NOT = 24, MUL = 25, DIV = 26, MOD = 27, 
    ASSIGN = 28, EQ = 29, NEQ = 30, GT = 31, LT = 32, GE = 33, LE = 34, 
    AND = 35, OR = 36, L_PAREN = 37, R_PAREN = 38, L_BRACE = 39, R_BRACE = 40, 
    L_BRACKET = 41, R_BRACKET = 42, COMMA = 43, SEMICOLON = 44, DOUBLE_QUOTE = 45, 
    WS = 46, LineComment = 47, BlockComment = 48
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

