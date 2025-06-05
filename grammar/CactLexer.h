
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
    EXPONENT = 21, HexFloat = 22, CharConst = 23, STRING = 24, PLUS = 25, 
    MINUS = 26, NOT = 27, MUL = 28, DIV = 29, MOD = 30, ASSIGN = 31, EQ = 32, 
    NEQ = 33, GT = 34, LT = 35, GE = 36, LE = 37, AND = 38, OR = 39, L_PAREN = 40, 
    R_PAREN = 41, L_BRACE = 42, R_BRACE = 43, L_BRACKET = 44, R_BRACKET = 45, 
    COMMA = 46, SEMICOLON = 47, DOUBLE_QUOTE = 48, WS = 49, LineComment = 50, 
    BlockComment = 51
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

