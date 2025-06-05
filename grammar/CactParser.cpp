
    #include <vector>


// Generated from Cact.g4 by ANTLR 4.13.1


#include "CactVisitor.h"

#include "CactParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CactParserStaticData final {
  CactParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CactParserStaticData(const CactParserStaticData&) = delete;
  CactParserStaticData(CactParserStaticData&&) = delete;
  CactParserStaticData& operator=(const CactParserStaticData&) = delete;
  CactParserStaticData& operator=(CactParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag cactParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
CactParserStaticData *cactParserStaticData = nullptr;

void cactParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (cactParserStaticData != nullptr) {
    return;
  }
#else
  assert(cactParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CactParserStaticData>(
    std::vector<std::string>{
      "program", "compUnit", "decl", "bType", "constDecl", "constDef", "constInitVal", 
      "varDecl", "varDef", "funcDef", "funcType", "funcFParams", "funcFParam", 
      "block", "blockItem", "stmt", "elseIFStmt", "elseStmt", "exp", "cond", 
      "lVal", "number", "signedNumber", "funcRParams", "primaryExp", "unaryExp", 
      "unaryOp", "mulExp", "mulOp", "addExp", "addOp", "relExp", "relOp", 
      "eqExp", "eqOp", "lAndExp", "lOrExp", "intConst", "boolConst"
    },
    std::vector<std::string>{
      "", "'const'", "'int'", "'double'", "'char'", "'float'", "'bool'", 
      "'void'", "'if'", "'else'", "'while'", "'break'", "'continue'", "'return'", 
      "'false'", "'true'", "", "", "", "", "", "", "", "", "", "'+'", "'-'", 
      "'!'", "'*'", "'/'", "'%'", "'='", "'=='", "'!='", "'>'", "'<'", "'>='", 
      "'<='", "'&&'", "'||'", "'('", "')'", "'{'", "'}'", "'['", "']'", 
      "','", "';'", "'\"'"
    },
    std::vector<std::string>{
      "", "CONST_KW", "INT_KW", "DOUBLE_KW", "CHAR_KW", "FLOAT_KW", "BOOL_KW", 
      "VOID_KW", "IF_KW", "ELSE_KW", "WHILE_KW", "BREAK_KW", "CONTINUE_KW", 
      "RETURN_KW", "FALSE", "TRUE", "IDENT", "DECIMAL_CONST", "OCTAL_CONST", 
      "HEXADECIMAL_CONST", "FloatConst", "EXPONENT", "HexFloat", "CharConst", 
      "STRING", "PLUS", "MINUS", "NOT", "MUL", "DIV", "MOD", "ASSIGN", "EQ", 
      "NEQ", "GT", "LT", "GE", "LE", "AND", "OR", "L_PAREN", "R_PAREN", 
      "L_BRACE", "R_BRACE", "L_BRACKET", "R_BRACKET", "COMMA", "SEMICOLON", 
      "DOUBLE_QUOTE", "WS", "LineComment", "BlockComment"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,51,388,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,1,0,1,0,1,1,1,1,4,1,83,8,1,11,1,12,1,
  	84,1,1,1,1,1,2,1,2,3,2,91,8,2,1,3,1,3,1,4,1,4,1,4,1,4,1,4,5,4,100,8,4,
  	10,4,12,4,103,9,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,5,5,112,8,5,10,5,12,5,115,
  	9,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,5,6,125,8,6,10,6,12,6,128,9,6,3,6,
  	130,8,6,1,6,1,6,3,6,134,8,6,1,7,1,7,1,7,1,7,5,7,140,8,7,10,7,12,7,143,
  	9,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,5,8,152,8,8,10,8,12,8,155,9,8,1,8,1,8,
  	3,8,159,8,8,1,9,1,9,1,9,1,9,3,9,165,8,9,1,9,1,9,1,9,1,10,1,10,3,10,172,
  	8,10,1,11,1,11,1,11,5,11,177,8,11,10,11,12,11,180,9,11,1,12,1,12,1,12,
  	1,12,3,12,186,8,12,1,12,1,12,1,12,1,12,1,12,5,12,193,8,12,10,12,12,12,
  	196,9,12,3,12,198,8,12,1,13,1,13,5,13,202,8,13,10,13,12,13,205,9,13,1,
  	13,1,13,1,14,1,14,3,14,211,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,5,15,225,8,15,10,15,12,15,228,9,15,1,15,3,15,231,
  	8,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,
  	245,8,15,1,15,1,15,3,15,249,8,15,1,15,3,15,252,8,15,1,16,1,16,1,16,1,
  	16,1,16,1,16,1,16,1,17,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,20,1,
  	20,1,20,5,20,273,8,20,10,20,12,20,276,9,20,1,21,1,21,1,21,1,21,1,21,3,
  	21,283,8,21,1,22,3,22,286,8,22,1,22,1,22,1,23,1,23,1,23,5,23,293,8,23,
  	10,23,12,23,296,9,23,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,5,24,
  	307,8,24,10,24,12,24,310,9,24,1,24,1,24,3,24,314,8,24,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,3,25,323,8,25,1,25,3,25,326,8,25,1,26,1,26,1,27,1,
  	27,1,27,1,27,5,27,334,8,27,10,27,12,27,337,9,27,1,28,1,28,1,29,1,29,1,
  	29,1,29,5,29,345,8,29,10,29,12,29,348,9,29,1,30,1,30,1,31,1,31,1,31,1,
  	31,3,31,356,8,31,1,32,1,32,1,33,1,33,1,33,1,33,3,33,364,8,33,1,34,1,34,
  	1,35,1,35,1,35,5,35,371,8,35,10,35,12,35,374,9,35,1,36,1,36,1,36,5,36,
  	379,8,36,10,36,12,36,382,9,36,1,37,1,37,1,38,1,38,1,38,0,0,39,0,2,4,6,
  	8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,
  	56,58,60,62,64,66,68,70,72,74,76,0,8,1,0,2,6,1,0,25,26,1,0,25,27,1,0,
  	28,30,1,0,34,37,1,0,32,33,1,0,17,19,1,0,14,15,399,0,78,1,0,0,0,2,82,1,
  	0,0,0,4,90,1,0,0,0,6,92,1,0,0,0,8,94,1,0,0,0,10,106,1,0,0,0,12,133,1,
  	0,0,0,14,135,1,0,0,0,16,146,1,0,0,0,18,160,1,0,0,0,20,171,1,0,0,0,22,
  	173,1,0,0,0,24,181,1,0,0,0,26,199,1,0,0,0,28,210,1,0,0,0,30,251,1,0,0,
  	0,32,253,1,0,0,0,34,260,1,0,0,0,36,263,1,0,0,0,38,265,1,0,0,0,40,267,
  	1,0,0,0,42,282,1,0,0,0,44,285,1,0,0,0,46,289,1,0,0,0,48,313,1,0,0,0,50,
  	325,1,0,0,0,52,327,1,0,0,0,54,329,1,0,0,0,56,338,1,0,0,0,58,340,1,0,0,
  	0,60,349,1,0,0,0,62,351,1,0,0,0,64,357,1,0,0,0,66,359,1,0,0,0,68,365,
  	1,0,0,0,70,367,1,0,0,0,72,375,1,0,0,0,74,383,1,0,0,0,76,385,1,0,0,0,78,
  	79,3,2,1,0,79,1,1,0,0,0,80,83,3,4,2,0,81,83,3,18,9,0,82,80,1,0,0,0,82,
  	81,1,0,0,0,83,84,1,0,0,0,84,82,1,0,0,0,84,85,1,0,0,0,85,86,1,0,0,0,86,
  	87,5,0,0,1,87,3,1,0,0,0,88,91,3,8,4,0,89,91,3,14,7,0,90,88,1,0,0,0,90,
  	89,1,0,0,0,91,5,1,0,0,0,92,93,7,0,0,0,93,7,1,0,0,0,94,95,5,1,0,0,95,96,
  	3,6,3,0,96,101,3,10,5,0,97,98,5,46,0,0,98,100,3,10,5,0,99,97,1,0,0,0,
  	100,103,1,0,0,0,101,99,1,0,0,0,101,102,1,0,0,0,102,104,1,0,0,0,103,101,
  	1,0,0,0,104,105,5,47,0,0,105,9,1,0,0,0,106,113,5,16,0,0,107,108,5,44,
  	0,0,108,109,3,74,37,0,109,110,5,45,0,0,110,112,1,0,0,0,111,107,1,0,0,
  	0,112,115,1,0,0,0,113,111,1,0,0,0,113,114,1,0,0,0,114,116,1,0,0,0,115,
  	113,1,0,0,0,116,117,5,31,0,0,117,118,3,12,6,0,118,11,1,0,0,0,119,134,
  	3,44,22,0,120,129,5,42,0,0,121,126,3,12,6,0,122,123,5,46,0,0,123,125,
  	3,12,6,0,124,122,1,0,0,0,125,128,1,0,0,0,126,124,1,0,0,0,126,127,1,0,
  	0,0,127,130,1,0,0,0,128,126,1,0,0,0,129,121,1,0,0,0,129,130,1,0,0,0,130,
  	131,1,0,0,0,131,134,5,43,0,0,132,134,3,76,38,0,133,119,1,0,0,0,133,120,
  	1,0,0,0,133,132,1,0,0,0,134,13,1,0,0,0,135,136,3,6,3,0,136,141,3,16,8,
  	0,137,138,5,46,0,0,138,140,3,16,8,0,139,137,1,0,0,0,140,143,1,0,0,0,141,
  	139,1,0,0,0,141,142,1,0,0,0,142,144,1,0,0,0,143,141,1,0,0,0,144,145,5,
  	47,0,0,145,15,1,0,0,0,146,153,5,16,0,0,147,148,5,44,0,0,148,149,3,74,
  	37,0,149,150,5,45,0,0,150,152,1,0,0,0,151,147,1,0,0,0,152,155,1,0,0,0,
  	153,151,1,0,0,0,153,154,1,0,0,0,154,158,1,0,0,0,155,153,1,0,0,0,156,157,
  	5,31,0,0,157,159,3,12,6,0,158,156,1,0,0,0,158,159,1,0,0,0,159,17,1,0,
  	0,0,160,161,3,20,10,0,161,162,5,16,0,0,162,164,5,40,0,0,163,165,3,22,
  	11,0,164,163,1,0,0,0,164,165,1,0,0,0,165,166,1,0,0,0,166,167,5,41,0,0,
  	167,168,3,26,13,0,168,19,1,0,0,0,169,172,3,6,3,0,170,172,5,7,0,0,171,
  	169,1,0,0,0,171,170,1,0,0,0,172,21,1,0,0,0,173,178,3,24,12,0,174,175,
  	5,46,0,0,175,177,3,24,12,0,176,174,1,0,0,0,177,180,1,0,0,0,178,176,1,
  	0,0,0,178,179,1,0,0,0,179,23,1,0,0,0,180,178,1,0,0,0,181,182,3,6,3,0,
  	182,197,5,16,0,0,183,185,5,44,0,0,184,186,3,74,37,0,185,184,1,0,0,0,185,
  	186,1,0,0,0,186,187,1,0,0,0,187,194,5,45,0,0,188,189,5,44,0,0,189,190,
  	3,74,37,0,190,191,5,45,0,0,191,193,1,0,0,0,192,188,1,0,0,0,193,196,1,
  	0,0,0,194,192,1,0,0,0,194,195,1,0,0,0,195,198,1,0,0,0,196,194,1,0,0,0,
  	197,183,1,0,0,0,197,198,1,0,0,0,198,25,1,0,0,0,199,203,5,42,0,0,200,202,
  	3,28,14,0,201,200,1,0,0,0,202,205,1,0,0,0,203,201,1,0,0,0,203,204,1,0,
  	0,0,204,206,1,0,0,0,205,203,1,0,0,0,206,207,5,43,0,0,207,27,1,0,0,0,208,
  	211,3,4,2,0,209,211,3,30,15,0,210,208,1,0,0,0,210,209,1,0,0,0,211,29,
  	1,0,0,0,212,213,3,40,20,0,213,214,5,31,0,0,214,215,3,36,18,0,215,216,
  	5,47,0,0,216,252,1,0,0,0,217,252,3,26,13,0,218,219,5,8,0,0,219,220,5,
  	40,0,0,220,221,3,38,19,0,221,222,5,41,0,0,222,226,3,30,15,0,223,225,3,
  	32,16,0,224,223,1,0,0,0,225,228,1,0,0,0,226,224,1,0,0,0,226,227,1,0,0,
  	0,227,230,1,0,0,0,228,226,1,0,0,0,229,231,3,34,17,0,230,229,1,0,0,0,230,
  	231,1,0,0,0,231,252,1,0,0,0,232,233,5,10,0,0,233,234,5,40,0,0,234,235,
  	3,38,19,0,235,236,5,41,0,0,236,237,3,30,15,0,237,252,1,0,0,0,238,239,
  	5,11,0,0,239,252,5,47,0,0,240,241,5,12,0,0,241,252,5,47,0,0,242,244,5,
  	13,0,0,243,245,3,36,18,0,244,243,1,0,0,0,244,245,1,0,0,0,245,246,1,0,
  	0,0,246,252,5,47,0,0,247,249,3,36,18,0,248,247,1,0,0,0,248,249,1,0,0,
  	0,249,250,1,0,0,0,250,252,5,47,0,0,251,212,1,0,0,0,251,217,1,0,0,0,251,
  	218,1,0,0,0,251,232,1,0,0,0,251,238,1,0,0,0,251,240,1,0,0,0,251,242,1,
  	0,0,0,251,248,1,0,0,0,252,31,1,0,0,0,253,254,5,9,0,0,254,255,5,8,0,0,
  	255,256,5,40,0,0,256,257,3,38,19,0,257,258,5,41,0,0,258,259,3,30,15,0,
  	259,33,1,0,0,0,260,261,5,9,0,0,261,262,3,30,15,0,262,35,1,0,0,0,263,264,
  	3,58,29,0,264,37,1,0,0,0,265,266,3,72,36,0,266,39,1,0,0,0,267,274,5,16,
  	0,0,268,269,5,44,0,0,269,270,3,36,18,0,270,271,5,45,0,0,271,273,1,0,0,
  	0,272,268,1,0,0,0,273,276,1,0,0,0,274,272,1,0,0,0,274,275,1,0,0,0,275,
  	41,1,0,0,0,276,274,1,0,0,0,277,283,3,74,37,0,278,283,5,20,0,0,279,283,
  	5,21,0,0,280,283,5,22,0,0,281,283,5,23,0,0,282,277,1,0,0,0,282,278,1,
  	0,0,0,282,279,1,0,0,0,282,280,1,0,0,0,282,281,1,0,0,0,283,43,1,0,0,0,
  	284,286,7,1,0,0,285,284,1,0,0,0,285,286,1,0,0,0,286,287,1,0,0,0,287,288,
  	3,42,21,0,288,45,1,0,0,0,289,294,3,36,18,0,290,291,5,46,0,0,291,293,3,
  	36,18,0,292,290,1,0,0,0,293,296,1,0,0,0,294,292,1,0,0,0,294,295,1,0,0,
  	0,295,47,1,0,0,0,296,294,1,0,0,0,297,298,5,40,0,0,298,299,3,72,36,0,299,
  	300,5,41,0,0,300,314,1,0,0,0,301,308,5,16,0,0,302,303,5,44,0,0,303,304,
  	3,36,18,0,304,305,5,45,0,0,305,307,1,0,0,0,306,302,1,0,0,0,307,310,1,
  	0,0,0,308,306,1,0,0,0,308,309,1,0,0,0,309,314,1,0,0,0,310,308,1,0,0,0,
  	311,314,3,42,21,0,312,314,3,76,38,0,313,297,1,0,0,0,313,301,1,0,0,0,313,
  	311,1,0,0,0,313,312,1,0,0,0,314,49,1,0,0,0,315,326,3,48,24,0,316,317,
  	3,52,26,0,317,318,3,50,25,0,318,326,1,0,0,0,319,320,5,16,0,0,320,322,
  	5,40,0,0,321,323,3,46,23,0,322,321,1,0,0,0,322,323,1,0,0,0,323,324,1,
  	0,0,0,324,326,5,41,0,0,325,315,1,0,0,0,325,316,1,0,0,0,325,319,1,0,0,
  	0,326,51,1,0,0,0,327,328,7,2,0,0,328,53,1,0,0,0,329,335,3,50,25,0,330,
  	331,3,56,28,0,331,332,3,50,25,0,332,334,1,0,0,0,333,330,1,0,0,0,334,337,
  	1,0,0,0,335,333,1,0,0,0,335,336,1,0,0,0,336,55,1,0,0,0,337,335,1,0,0,
  	0,338,339,7,3,0,0,339,57,1,0,0,0,340,346,3,54,27,0,341,342,3,60,30,0,
  	342,343,3,54,27,0,343,345,1,0,0,0,344,341,1,0,0,0,345,348,1,0,0,0,346,
  	344,1,0,0,0,346,347,1,0,0,0,347,59,1,0,0,0,348,346,1,0,0,0,349,350,7,
  	1,0,0,350,61,1,0,0,0,351,355,3,58,29,0,352,353,3,64,32,0,353,354,3,58,
  	29,0,354,356,1,0,0,0,355,352,1,0,0,0,355,356,1,0,0,0,356,63,1,0,0,0,357,
  	358,7,4,0,0,358,65,1,0,0,0,359,363,3,62,31,0,360,361,3,68,34,0,361,362,
  	3,62,31,0,362,364,1,0,0,0,363,360,1,0,0,0,363,364,1,0,0,0,364,67,1,0,
  	0,0,365,366,7,5,0,0,366,69,1,0,0,0,367,372,3,66,33,0,368,369,5,38,0,0,
  	369,371,3,66,33,0,370,368,1,0,0,0,371,374,1,0,0,0,372,370,1,0,0,0,372,
  	373,1,0,0,0,373,71,1,0,0,0,374,372,1,0,0,0,375,380,3,70,35,0,376,377,
  	5,39,0,0,377,379,3,70,35,0,378,376,1,0,0,0,379,382,1,0,0,0,380,378,1,
  	0,0,0,380,381,1,0,0,0,381,73,1,0,0,0,382,380,1,0,0,0,383,384,7,6,0,0,
  	384,75,1,0,0,0,385,386,7,7,0,0,386,77,1,0,0,0,38,82,84,90,101,113,126,
  	129,133,141,153,158,164,171,178,185,194,197,203,210,226,230,244,248,251,
  	274,282,285,294,308,313,322,325,335,346,355,363,372,380
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  cactParserStaticData = staticData.release();
}

}

CactParser::CactParser(TokenStream *input) : CactParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CactParser::CactParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CactParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *cactParserStaticData->atn, cactParserStaticData->decisionToDFA, cactParserStaticData->sharedContextCache, options);
}

CactParser::~CactParser() {
  delete _interpreter;
}

const atn::ATN& CactParser::getATN() const {
  return *cactParserStaticData->atn;
}

std::string CactParser::getGrammarFileName() const {
  return "Cact.g4";
}

const std::vector<std::string>& CactParser::getRuleNames() const {
  return cactParserStaticData->ruleNames;
}

const dfa::Vocabulary& CactParser::getVocabulary() const {
  return cactParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CactParser::getSerializedATN() const {
  return cactParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

CactParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::CompUnitContext* CactParser::ProgramContext::compUnit() {
  return getRuleContext<CactParser::CompUnitContext>(0);
}


size_t CactParser::ProgramContext::getRuleIndex() const {
  return CactParser::RuleProgram;
}


std::any CactParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

CactParser::ProgramContext* CactParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, CactParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    compUnit();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompUnitContext ------------------------------------------------------------------

CactParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::CompUnitContext::EOF() {
  return getToken(CactParser::EOF, 0);
}

std::vector<CactParser::DeclContext *> CactParser::CompUnitContext::decl() {
  return getRuleContexts<CactParser::DeclContext>();
}

CactParser::DeclContext* CactParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<CactParser::DeclContext>(i);
}

std::vector<CactParser::FuncDefContext *> CactParser::CompUnitContext::funcDef() {
  return getRuleContexts<CactParser::FuncDefContext>();
}

CactParser::FuncDefContext* CactParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<CactParser::FuncDefContext>(i);
}


size_t CactParser::CompUnitContext::getRuleIndex() const {
  return CactParser::RuleCompUnit;
}


std::any CactParser::CompUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitCompUnit(this);
  else
    return visitor->visitChildren(this);
}

CactParser::CompUnitContext* CactParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 2, CactParser::RuleCompUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(82);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(80);
        decl();
        break;
      }

      case 2: {
        setState(81);
        funcDef();
        break;
      }

      default:
        break;
      }
      setState(84); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 254) != 0));
    setState(86);
    match(CactParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

CactParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::ConstDeclContext* CactParser::DeclContext::constDecl() {
  return getRuleContext<CactParser::ConstDeclContext>(0);
}

CactParser::VarDeclContext* CactParser::DeclContext::varDecl() {
  return getRuleContext<CactParser::VarDeclContext>(0);
}


size_t CactParser::DeclContext::getRuleIndex() const {
  return CactParser::RuleDecl;
}


std::any CactParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

CactParser::DeclContext* CactParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 4, CactParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(90);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::CONST_KW: {
        enterOuterAlt(_localctx, 1);
        setState(88);
        constDecl();
        break;
      }

      case CactParser::INT_KW:
      case CactParser::DOUBLE_KW:
      case CactParser::CHAR_KW:
      case CactParser::FLOAT_KW:
      case CactParser::BOOL_KW: {
        enterOuterAlt(_localctx, 2);
        setState(89);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

CactParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::BTypeContext::INT_KW() {
  return getToken(CactParser::INT_KW, 0);
}

tree::TerminalNode* CactParser::BTypeContext::DOUBLE_KW() {
  return getToken(CactParser::DOUBLE_KW, 0);
}

tree::TerminalNode* CactParser::BTypeContext::CHAR_KW() {
  return getToken(CactParser::CHAR_KW, 0);
}

tree::TerminalNode* CactParser::BTypeContext::FLOAT_KW() {
  return getToken(CactParser::FLOAT_KW, 0);
}

tree::TerminalNode* CactParser::BTypeContext::BOOL_KW() {
  return getToken(CactParser::BOOL_KW, 0);
}


size_t CactParser::BTypeContext::getRuleIndex() const {
  return CactParser::RuleBType;
}


std::any CactParser::BTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitBType(this);
  else
    return visitor->visitChildren(this);
}

CactParser::BTypeContext* CactParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, CactParser::RuleBType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 124) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

CactParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::ConstDeclContext::CONST_KW() {
  return getToken(CactParser::CONST_KW, 0);
}

CactParser::BTypeContext* CactParser::ConstDeclContext::bType() {
  return getRuleContext<CactParser::BTypeContext>(0);
}

std::vector<CactParser::ConstDefContext *> CactParser::ConstDeclContext::constDef() {
  return getRuleContexts<CactParser::ConstDefContext>();
}

CactParser::ConstDefContext* CactParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<CactParser::ConstDefContext>(i);
}

tree::TerminalNode* CactParser::ConstDeclContext::SEMICOLON() {
  return getToken(CactParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> CactParser::ConstDeclContext::COMMA() {
  return getTokens(CactParser::COMMA);
}

tree::TerminalNode* CactParser::ConstDeclContext::COMMA(size_t i) {
  return getToken(CactParser::COMMA, i);
}


size_t CactParser::ConstDeclContext::getRuleIndex() const {
  return CactParser::RuleConstDecl;
}


std::any CactParser::ConstDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitConstDecl(this);
  else
    return visitor->visitChildren(this);
}

CactParser::ConstDeclContext* CactParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, CactParser::RuleConstDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(CactParser::CONST_KW);
    setState(95);
    bType();
    setState(96);
    constDef();
    setState(101);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::COMMA) {
      setState(97);
      match(CactParser::COMMA);
      setState(98);
      constDef();
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(104);
    match(CactParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

CactParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::ConstDefContext::IDENT() {
  return getToken(CactParser::IDENT, 0);
}

tree::TerminalNode* CactParser::ConstDefContext::ASSIGN() {
  return getToken(CactParser::ASSIGN, 0);
}

CactParser::ConstInitValContext* CactParser::ConstDefContext::constInitVal() {
  return getRuleContext<CactParser::ConstInitValContext>(0);
}

std::vector<tree::TerminalNode *> CactParser::ConstDefContext::L_BRACKET() {
  return getTokens(CactParser::L_BRACKET);
}

tree::TerminalNode* CactParser::ConstDefContext::L_BRACKET(size_t i) {
  return getToken(CactParser::L_BRACKET, i);
}

std::vector<CactParser::IntConstContext *> CactParser::ConstDefContext::intConst() {
  return getRuleContexts<CactParser::IntConstContext>();
}

CactParser::IntConstContext* CactParser::ConstDefContext::intConst(size_t i) {
  return getRuleContext<CactParser::IntConstContext>(i);
}

std::vector<tree::TerminalNode *> CactParser::ConstDefContext::R_BRACKET() {
  return getTokens(CactParser::R_BRACKET);
}

tree::TerminalNode* CactParser::ConstDefContext::R_BRACKET(size_t i) {
  return getToken(CactParser::R_BRACKET, i);
}


size_t CactParser::ConstDefContext::getRuleIndex() const {
  return CactParser::RuleConstDef;
}


std::any CactParser::ConstDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitConstDef(this);
  else
    return visitor->visitChildren(this);
}

CactParser::ConstDefContext* CactParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 10, CactParser::RuleConstDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    match(CactParser::IDENT);
    setState(113);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::L_BRACKET) {
      setState(107);
      match(CactParser::L_BRACKET);
      setState(108);
      intConst();
      setState(109);
      match(CactParser::R_BRACKET);
      setState(115);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(116);
    match(CactParser::ASSIGN);
    setState(117);
    constInitVal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitValContext ------------------------------------------------------------------

CactParser::ConstInitValContext::ConstInitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::SignedNumberContext* CactParser::ConstInitValContext::signedNumber() {
  return getRuleContext<CactParser::SignedNumberContext>(0);
}

tree::TerminalNode* CactParser::ConstInitValContext::L_BRACE() {
  return getToken(CactParser::L_BRACE, 0);
}

tree::TerminalNode* CactParser::ConstInitValContext::R_BRACE() {
  return getToken(CactParser::R_BRACE, 0);
}

std::vector<CactParser::ConstInitValContext *> CactParser::ConstInitValContext::constInitVal() {
  return getRuleContexts<CactParser::ConstInitValContext>();
}

CactParser::ConstInitValContext* CactParser::ConstInitValContext::constInitVal(size_t i) {
  return getRuleContext<CactParser::ConstInitValContext>(i);
}

std::vector<tree::TerminalNode *> CactParser::ConstInitValContext::COMMA() {
  return getTokens(CactParser::COMMA);
}

tree::TerminalNode* CactParser::ConstInitValContext::COMMA(size_t i) {
  return getToken(CactParser::COMMA, i);
}

CactParser::BoolConstContext* CactParser::ConstInitValContext::boolConst() {
  return getRuleContext<CactParser::BoolConstContext>(0);
}


size_t CactParser::ConstInitValContext::getRuleIndex() const {
  return CactParser::RuleConstInitVal;
}


std::any CactParser::ConstInitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitConstInitVal(this);
  else
    return visitor->visitChildren(this);
}

CactParser::ConstInitValContext* CactParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 12, CactParser::RuleConstInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(133);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::DECIMAL_CONST:
      case CactParser::OCTAL_CONST:
      case CactParser::HEXADECIMAL_CONST:
      case CactParser::FloatConst:
      case CactParser::EXPONENT:
      case CactParser::HexFloat:
      case CactParser::CharConst:
      case CactParser::PLUS:
      case CactParser::MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(119);
        signedNumber();
        break;
      }

      case CactParser::L_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(120);
        match(CactParser::L_BRACE);
        setState(129);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 4398163869696) != 0)) {
          setState(121);
          constInitVal();
          setState(126);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == CactParser::COMMA) {
            setState(122);
            match(CactParser::COMMA);
            setState(123);
            constInitVal();
            setState(128);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(131);
        match(CactParser::R_BRACE);
        break;
      }

      case CactParser::FALSE:
      case CactParser::TRUE: {
        enterOuterAlt(_localctx, 3);
        setState(132);
        boolConst();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

CactParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::BTypeContext* CactParser::VarDeclContext::bType() {
  return getRuleContext<CactParser::BTypeContext>(0);
}

std::vector<CactParser::VarDefContext *> CactParser::VarDeclContext::varDef() {
  return getRuleContexts<CactParser::VarDefContext>();
}

CactParser::VarDefContext* CactParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<CactParser::VarDefContext>(i);
}

tree::TerminalNode* CactParser::VarDeclContext::SEMICOLON() {
  return getToken(CactParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> CactParser::VarDeclContext::COMMA() {
  return getTokens(CactParser::COMMA);
}

tree::TerminalNode* CactParser::VarDeclContext::COMMA(size_t i) {
  return getToken(CactParser::COMMA, i);
}


size_t CactParser::VarDeclContext::getRuleIndex() const {
  return CactParser::RuleVarDecl;
}


std::any CactParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

CactParser::VarDeclContext* CactParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 14, CactParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    bType();
    setState(136);
    varDef();
    setState(141);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::COMMA) {
      setState(137);
      match(CactParser::COMMA);
      setState(138);
      varDef();
      setState(143);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(144);
    match(CactParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

CactParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::VarDefContext::IDENT() {
  return getToken(CactParser::IDENT, 0);
}

std::vector<tree::TerminalNode *> CactParser::VarDefContext::L_BRACKET() {
  return getTokens(CactParser::L_BRACKET);
}

tree::TerminalNode* CactParser::VarDefContext::L_BRACKET(size_t i) {
  return getToken(CactParser::L_BRACKET, i);
}

std::vector<CactParser::IntConstContext *> CactParser::VarDefContext::intConst() {
  return getRuleContexts<CactParser::IntConstContext>();
}

CactParser::IntConstContext* CactParser::VarDefContext::intConst(size_t i) {
  return getRuleContext<CactParser::IntConstContext>(i);
}

std::vector<tree::TerminalNode *> CactParser::VarDefContext::R_BRACKET() {
  return getTokens(CactParser::R_BRACKET);
}

tree::TerminalNode* CactParser::VarDefContext::R_BRACKET(size_t i) {
  return getToken(CactParser::R_BRACKET, i);
}

tree::TerminalNode* CactParser::VarDefContext::ASSIGN() {
  return getToken(CactParser::ASSIGN, 0);
}

CactParser::ConstInitValContext* CactParser::VarDefContext::constInitVal() {
  return getRuleContext<CactParser::ConstInitValContext>(0);
}


size_t CactParser::VarDefContext::getRuleIndex() const {
  return CactParser::RuleVarDef;
}


std::any CactParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

CactParser::VarDefContext* CactParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 16, CactParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    match(CactParser::IDENT);
    setState(153);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::L_BRACKET) {
      setState(147);
      match(CactParser::L_BRACKET);
      setState(148);
      intConst();
      setState(149);
      match(CactParser::R_BRACKET);
      setState(155);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(158);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CactParser::ASSIGN) {
      setState(156);
      match(CactParser::ASSIGN);
      setState(157);
      constInitVal();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

CactParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::FuncTypeContext* CactParser::FuncDefContext::funcType() {
  return getRuleContext<CactParser::FuncTypeContext>(0);
}

tree::TerminalNode* CactParser::FuncDefContext::IDENT() {
  return getToken(CactParser::IDENT, 0);
}

tree::TerminalNode* CactParser::FuncDefContext::L_PAREN() {
  return getToken(CactParser::L_PAREN, 0);
}

tree::TerminalNode* CactParser::FuncDefContext::R_PAREN() {
  return getToken(CactParser::R_PAREN, 0);
}

CactParser::BlockContext* CactParser::FuncDefContext::block() {
  return getRuleContext<CactParser::BlockContext>(0);
}

CactParser::FuncFParamsContext* CactParser::FuncDefContext::funcFParams() {
  return getRuleContext<CactParser::FuncFParamsContext>(0);
}


size_t CactParser::FuncDefContext::getRuleIndex() const {
  return CactParser::RuleFuncDef;
}


std::any CactParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

CactParser::FuncDefContext* CactParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 18, CactParser::RuleFuncDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    funcType();
    setState(161);
    match(CactParser::IDENT);
    setState(162);
    match(CactParser::L_PAREN);
    setState(164);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 124) != 0)) {
      setState(163);
      funcFParams();
    }
    setState(166);
    match(CactParser::R_PAREN);
    setState(167);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

CactParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::BTypeContext* CactParser::FuncTypeContext::bType() {
  return getRuleContext<CactParser::BTypeContext>(0);
}

tree::TerminalNode* CactParser::FuncTypeContext::VOID_KW() {
  return getToken(CactParser::VOID_KW, 0);
}


size_t CactParser::FuncTypeContext::getRuleIndex() const {
  return CactParser::RuleFuncType;
}


std::any CactParser::FuncTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitFuncType(this);
  else
    return visitor->visitChildren(this);
}

CactParser::FuncTypeContext* CactParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, CactParser::RuleFuncType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(171);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::INT_KW:
      case CactParser::DOUBLE_KW:
      case CactParser::CHAR_KW:
      case CactParser::FLOAT_KW:
      case CactParser::BOOL_KW: {
        enterOuterAlt(_localctx, 1);
        setState(169);
        bType();
        break;
      }

      case CactParser::VOID_KW: {
        enterOuterAlt(_localctx, 2);
        setState(170);
        match(CactParser::VOID_KW);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamsContext ------------------------------------------------------------------

CactParser::FuncFParamsContext::FuncFParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CactParser::FuncFParamContext *> CactParser::FuncFParamsContext::funcFParam() {
  return getRuleContexts<CactParser::FuncFParamContext>();
}

CactParser::FuncFParamContext* CactParser::FuncFParamsContext::funcFParam(size_t i) {
  return getRuleContext<CactParser::FuncFParamContext>(i);
}

std::vector<tree::TerminalNode *> CactParser::FuncFParamsContext::COMMA() {
  return getTokens(CactParser::COMMA);
}

tree::TerminalNode* CactParser::FuncFParamsContext::COMMA(size_t i) {
  return getToken(CactParser::COMMA, i);
}


size_t CactParser::FuncFParamsContext::getRuleIndex() const {
  return CactParser::RuleFuncFParams;
}


std::any CactParser::FuncFParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitFuncFParams(this);
  else
    return visitor->visitChildren(this);
}

CactParser::FuncFParamsContext* CactParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 22, CactParser::RuleFuncFParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    funcFParam();
    setState(178);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::COMMA) {
      setState(174);
      match(CactParser::COMMA);
      setState(175);
      funcFParam();
      setState(180);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamContext ------------------------------------------------------------------

CactParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::BTypeContext* CactParser::FuncFParamContext::bType() {
  return getRuleContext<CactParser::BTypeContext>(0);
}

tree::TerminalNode* CactParser::FuncFParamContext::IDENT() {
  return getToken(CactParser::IDENT, 0);
}

std::vector<tree::TerminalNode *> CactParser::FuncFParamContext::L_BRACKET() {
  return getTokens(CactParser::L_BRACKET);
}

tree::TerminalNode* CactParser::FuncFParamContext::L_BRACKET(size_t i) {
  return getToken(CactParser::L_BRACKET, i);
}

std::vector<tree::TerminalNode *> CactParser::FuncFParamContext::R_BRACKET() {
  return getTokens(CactParser::R_BRACKET);
}

tree::TerminalNode* CactParser::FuncFParamContext::R_BRACKET(size_t i) {
  return getToken(CactParser::R_BRACKET, i);
}

std::vector<CactParser::IntConstContext *> CactParser::FuncFParamContext::intConst() {
  return getRuleContexts<CactParser::IntConstContext>();
}

CactParser::IntConstContext* CactParser::FuncFParamContext::intConst(size_t i) {
  return getRuleContext<CactParser::IntConstContext>(i);
}


size_t CactParser::FuncFParamContext::getRuleIndex() const {
  return CactParser::RuleFuncFParam;
}


std::any CactParser::FuncFParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitFuncFParam(this);
  else
    return visitor->visitChildren(this);
}

CactParser::FuncFParamContext* CactParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 24, CactParser::RuleFuncFParam);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    bType();
    setState(182);
    match(CactParser::IDENT);
    setState(197);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CactParser::L_BRACKET) {
      setState(183);
      match(CactParser::L_BRACKET);
      setState(185);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 917504) != 0)) {
        setState(184);
        intConst();
      }
      setState(187);
      match(CactParser::R_BRACKET);
      setState(194);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CactParser::L_BRACKET) {
        setState(188);
        match(CactParser::L_BRACKET);
        setState(189);
        intConst();
        setState(190);
        match(CactParser::R_BRACKET);
        setState(196);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

CactParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::BlockContext::L_BRACE() {
  return getToken(CactParser::L_BRACE, 0);
}

tree::TerminalNode* CactParser::BlockContext::R_BRACE() {
  return getToken(CactParser::R_BRACE, 0);
}

std::vector<CactParser::BlockItemContext *> CactParser::BlockContext::blockItem() {
  return getRuleContexts<CactParser::BlockItemContext>();
}

CactParser::BlockItemContext* CactParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<CactParser::BlockItemContext>(i);
}


size_t CactParser::BlockContext::getRuleIndex() const {
  return CactParser::RuleBlock;
}


std::any CactParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

CactParser::BlockContext* CactParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 26, CactParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    match(CactParser::L_BRACE);
    setState(203);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 146235298151806) != 0)) {
      setState(200);
      blockItem();
      setState(205);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(206);
    match(CactParser::R_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

CactParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::DeclContext* CactParser::BlockItemContext::decl() {
  return getRuleContext<CactParser::DeclContext>(0);
}

CactParser::StmtContext* CactParser::BlockItemContext::stmt() {
  return getRuleContext<CactParser::StmtContext>(0);
}


size_t CactParser::BlockItemContext::getRuleIndex() const {
  return CactParser::RuleBlockItem;
}


std::any CactParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

CactParser::BlockItemContext* CactParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 28, CactParser::RuleBlockItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(210);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::CONST_KW:
      case CactParser::INT_KW:
      case CactParser::DOUBLE_KW:
      case CactParser::CHAR_KW:
      case CactParser::FLOAT_KW:
      case CactParser::BOOL_KW: {
        enterOuterAlt(_localctx, 1);
        setState(208);
        decl();
        break;
      }

      case CactParser::IF_KW:
      case CactParser::WHILE_KW:
      case CactParser::BREAK_KW:
      case CactParser::CONTINUE_KW:
      case CactParser::RETURN_KW:
      case CactParser::FALSE:
      case CactParser::TRUE:
      case CactParser::IDENT:
      case CactParser::DECIMAL_CONST:
      case CactParser::OCTAL_CONST:
      case CactParser::HEXADECIMAL_CONST:
      case CactParser::FloatConst:
      case CactParser::EXPONENT:
      case CactParser::HexFloat:
      case CactParser::CharConst:
      case CactParser::PLUS:
      case CactParser::MINUS:
      case CactParser::NOT:
      case CactParser::L_PAREN:
      case CactParser::L_BRACE:
      case CactParser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);
        setState(209);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

CactParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::LValContext* CactParser::StmtContext::lVal() {
  return getRuleContext<CactParser::LValContext>(0);
}

tree::TerminalNode* CactParser::StmtContext::ASSIGN() {
  return getToken(CactParser::ASSIGN, 0);
}

CactParser::ExpContext* CactParser::StmtContext::exp() {
  return getRuleContext<CactParser::ExpContext>(0);
}

tree::TerminalNode* CactParser::StmtContext::SEMICOLON() {
  return getToken(CactParser::SEMICOLON, 0);
}

CactParser::BlockContext* CactParser::StmtContext::block() {
  return getRuleContext<CactParser::BlockContext>(0);
}

tree::TerminalNode* CactParser::StmtContext::IF_KW() {
  return getToken(CactParser::IF_KW, 0);
}

tree::TerminalNode* CactParser::StmtContext::L_PAREN() {
  return getToken(CactParser::L_PAREN, 0);
}

CactParser::CondContext* CactParser::StmtContext::cond() {
  return getRuleContext<CactParser::CondContext>(0);
}

tree::TerminalNode* CactParser::StmtContext::R_PAREN() {
  return getToken(CactParser::R_PAREN, 0);
}

CactParser::StmtContext* CactParser::StmtContext::stmt() {
  return getRuleContext<CactParser::StmtContext>(0);
}

std::vector<CactParser::ElseIFStmtContext *> CactParser::StmtContext::elseIFStmt() {
  return getRuleContexts<CactParser::ElseIFStmtContext>();
}

CactParser::ElseIFStmtContext* CactParser::StmtContext::elseIFStmt(size_t i) {
  return getRuleContext<CactParser::ElseIFStmtContext>(i);
}

CactParser::ElseStmtContext* CactParser::StmtContext::elseStmt() {
  return getRuleContext<CactParser::ElseStmtContext>(0);
}

tree::TerminalNode* CactParser::StmtContext::WHILE_KW() {
  return getToken(CactParser::WHILE_KW, 0);
}

tree::TerminalNode* CactParser::StmtContext::BREAK_KW() {
  return getToken(CactParser::BREAK_KW, 0);
}

tree::TerminalNode* CactParser::StmtContext::CONTINUE_KW() {
  return getToken(CactParser::CONTINUE_KW, 0);
}

tree::TerminalNode* CactParser::StmtContext::RETURN_KW() {
  return getToken(CactParser::RETURN_KW, 0);
}


size_t CactParser::StmtContext::getRuleIndex() const {
  return CactParser::RuleStmt;
}


std::any CactParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

CactParser::StmtContext* CactParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 30, CactParser::RuleStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(251);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(212);
      lVal();
      setState(213);
      match(CactParser::ASSIGN);
      setState(214);
      exp();
      setState(215);
      match(CactParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(217);
      block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(218);
      match(CactParser::IF_KW);
      setState(219);
      match(CactParser::L_PAREN);
      setState(220);
      cond();
      setState(221);
      match(CactParser::R_PAREN);
      setState(222);
      stmt();
      setState(226);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(223);
          elseIFStmt(); 
        }
        setState(228);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
      }
      setState(230);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
      case 1: {
        setState(229);
        elseStmt();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(232);
      match(CactParser::WHILE_KW);
      setState(233);
      match(CactParser::L_PAREN);
      setState(234);
      cond();
      setState(235);
      match(CactParser::R_PAREN);
      setState(236);
      stmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(238);
      match(CactParser::BREAK_KW);
      setState(239);
      match(CactParser::SEMICOLON);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(240);
      match(CactParser::CONTINUE_KW);
      setState(241);
      match(CactParser::SEMICOLON);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(242);
      match(CactParser::RETURN_KW);
      setState(244);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1099763269632) != 0)) {
        setState(243);
        exp();
      }
      setState(246);
      match(CactParser::SEMICOLON);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(248);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1099763269632) != 0)) {
        setState(247);
        exp();
      }
      setState(250);
      match(CactParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseIFStmtContext ------------------------------------------------------------------

CactParser::ElseIFStmtContext::ElseIFStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::ElseIFStmtContext::ELSE_KW() {
  return getToken(CactParser::ELSE_KW, 0);
}

tree::TerminalNode* CactParser::ElseIFStmtContext::IF_KW() {
  return getToken(CactParser::IF_KW, 0);
}

tree::TerminalNode* CactParser::ElseIFStmtContext::L_PAREN() {
  return getToken(CactParser::L_PAREN, 0);
}

CactParser::CondContext* CactParser::ElseIFStmtContext::cond() {
  return getRuleContext<CactParser::CondContext>(0);
}

tree::TerminalNode* CactParser::ElseIFStmtContext::R_PAREN() {
  return getToken(CactParser::R_PAREN, 0);
}

CactParser::StmtContext* CactParser::ElseIFStmtContext::stmt() {
  return getRuleContext<CactParser::StmtContext>(0);
}


size_t CactParser::ElseIFStmtContext::getRuleIndex() const {
  return CactParser::RuleElseIFStmt;
}


std::any CactParser::ElseIFStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitElseIFStmt(this);
  else
    return visitor->visitChildren(this);
}

CactParser::ElseIFStmtContext* CactParser::elseIFStmt() {
  ElseIFStmtContext *_localctx = _tracker.createInstance<ElseIFStmtContext>(_ctx, getState());
  enterRule(_localctx, 32, CactParser::RuleElseIFStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(CactParser::ELSE_KW);
    setState(254);
    match(CactParser::IF_KW);
    setState(255);
    match(CactParser::L_PAREN);
    setState(256);
    cond();
    setState(257);
    match(CactParser::R_PAREN);
    setState(258);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStmtContext ------------------------------------------------------------------

CactParser::ElseStmtContext::ElseStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::ElseStmtContext::ELSE_KW() {
  return getToken(CactParser::ELSE_KW, 0);
}

CactParser::StmtContext* CactParser::ElseStmtContext::stmt() {
  return getRuleContext<CactParser::StmtContext>(0);
}


size_t CactParser::ElseStmtContext::getRuleIndex() const {
  return CactParser::RuleElseStmt;
}


std::any CactParser::ElseStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitElseStmt(this);
  else
    return visitor->visitChildren(this);
}

CactParser::ElseStmtContext* CactParser::elseStmt() {
  ElseStmtContext *_localctx = _tracker.createInstance<ElseStmtContext>(_ctx, getState());
  enterRule(_localctx, 34, CactParser::RuleElseStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    match(CactParser::ELSE_KW);
    setState(261);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

CactParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::AddExpContext* CactParser::ExpContext::addExp() {
  return getRuleContext<CactParser::AddExpContext>(0);
}


size_t CactParser::ExpContext::getRuleIndex() const {
  return CactParser::RuleExp;
}


std::any CactParser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::ExpContext* CactParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 36, CactParser::RuleExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    addExp();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

CactParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::LOrExpContext* CactParser::CondContext::lOrExp() {
  return getRuleContext<CactParser::LOrExpContext>(0);
}


size_t CactParser::CondContext::getRuleIndex() const {
  return CactParser::RuleCond;
}


std::any CactParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

CactParser::CondContext* CactParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 38, CactParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    lOrExp();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

CactParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::LValContext::IDENT() {
  return getToken(CactParser::IDENT, 0);
}

std::vector<tree::TerminalNode *> CactParser::LValContext::L_BRACKET() {
  return getTokens(CactParser::L_BRACKET);
}

tree::TerminalNode* CactParser::LValContext::L_BRACKET(size_t i) {
  return getToken(CactParser::L_BRACKET, i);
}

std::vector<CactParser::ExpContext *> CactParser::LValContext::exp() {
  return getRuleContexts<CactParser::ExpContext>();
}

CactParser::ExpContext* CactParser::LValContext::exp(size_t i) {
  return getRuleContext<CactParser::ExpContext>(i);
}

std::vector<tree::TerminalNode *> CactParser::LValContext::R_BRACKET() {
  return getTokens(CactParser::R_BRACKET);
}

tree::TerminalNode* CactParser::LValContext::R_BRACKET(size_t i) {
  return getToken(CactParser::R_BRACKET, i);
}


size_t CactParser::LValContext::getRuleIndex() const {
  return CactParser::RuleLVal;
}


std::any CactParser::LValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitLVal(this);
  else
    return visitor->visitChildren(this);
}

CactParser::LValContext* CactParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 40, CactParser::RuleLVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    match(CactParser::IDENT);
    setState(274);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::L_BRACKET) {
      setState(268);
      match(CactParser::L_BRACKET);
      setState(269);
      exp();
      setState(270);
      match(CactParser::R_BRACKET);
      setState(276);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

CactParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::IntConstContext* CactParser::NumberContext::intConst() {
  return getRuleContext<CactParser::IntConstContext>(0);
}

tree::TerminalNode* CactParser::NumberContext::FloatConst() {
  return getToken(CactParser::FloatConst, 0);
}

tree::TerminalNode* CactParser::NumberContext::EXPONENT() {
  return getToken(CactParser::EXPONENT, 0);
}

tree::TerminalNode* CactParser::NumberContext::HexFloat() {
  return getToken(CactParser::HexFloat, 0);
}

tree::TerminalNode* CactParser::NumberContext::CharConst() {
  return getToken(CactParser::CharConst, 0);
}


size_t CactParser::NumberContext::getRuleIndex() const {
  return CactParser::RuleNumber;
}


std::any CactParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

CactParser::NumberContext* CactParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 42, CactParser::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(282);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::DECIMAL_CONST:
      case CactParser::OCTAL_CONST:
      case CactParser::HEXADECIMAL_CONST: {
        enterOuterAlt(_localctx, 1);
        setState(277);
        intConst();
        break;
      }

      case CactParser::FloatConst: {
        enterOuterAlt(_localctx, 2);
        setState(278);
        match(CactParser::FloatConst);
        break;
      }

      case CactParser::EXPONENT: {
        enterOuterAlt(_localctx, 3);
        setState(279);
        match(CactParser::EXPONENT);
        break;
      }

      case CactParser::HexFloat: {
        enterOuterAlt(_localctx, 4);
        setState(280);
        match(CactParser::HexFloat);
        break;
      }

      case CactParser::CharConst: {
        enterOuterAlt(_localctx, 5);
        setState(281);
        match(CactParser::CharConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignedNumberContext ------------------------------------------------------------------

CactParser::SignedNumberContext::SignedNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::NumberContext* CactParser::SignedNumberContext::number() {
  return getRuleContext<CactParser::NumberContext>(0);
}

tree::TerminalNode* CactParser::SignedNumberContext::PLUS() {
  return getToken(CactParser::PLUS, 0);
}

tree::TerminalNode* CactParser::SignedNumberContext::MINUS() {
  return getToken(CactParser::MINUS, 0);
}


size_t CactParser::SignedNumberContext::getRuleIndex() const {
  return CactParser::RuleSignedNumber;
}


std::any CactParser::SignedNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitSignedNumber(this);
  else
    return visitor->visitChildren(this);
}

CactParser::SignedNumberContext* CactParser::signedNumber() {
  SignedNumberContext *_localctx = _tracker.createInstance<SignedNumberContext>(_ctx, getState());
  enterRule(_localctx, 44, CactParser::RuleSignedNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CactParser::PLUS

    || _la == CactParser::MINUS) {
      setState(284);
      _la = _input->LA(1);
      if (!(_la == CactParser::PLUS

      || _la == CactParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(287);
    number();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRParamsContext ------------------------------------------------------------------

CactParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CactParser::ExpContext *> CactParser::FuncRParamsContext::exp() {
  return getRuleContexts<CactParser::ExpContext>();
}

CactParser::ExpContext* CactParser::FuncRParamsContext::exp(size_t i) {
  return getRuleContext<CactParser::ExpContext>(i);
}

std::vector<tree::TerminalNode *> CactParser::FuncRParamsContext::COMMA() {
  return getTokens(CactParser::COMMA);
}

tree::TerminalNode* CactParser::FuncRParamsContext::COMMA(size_t i) {
  return getToken(CactParser::COMMA, i);
}


size_t CactParser::FuncRParamsContext::getRuleIndex() const {
  return CactParser::RuleFuncRParams;
}


std::any CactParser::FuncRParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitFuncRParams(this);
  else
    return visitor->visitChildren(this);
}

CactParser::FuncRParamsContext* CactParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 46, CactParser::RuleFuncRParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    exp();
    setState(294);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::COMMA) {
      setState(290);
      match(CactParser::COMMA);
      setState(291);
      exp();
      setState(296);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpContext ------------------------------------------------------------------

CactParser::PrimaryExpContext::PrimaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::PrimaryExpContext::L_PAREN() {
  return getToken(CactParser::L_PAREN, 0);
}

CactParser::LOrExpContext* CactParser::PrimaryExpContext::lOrExp() {
  return getRuleContext<CactParser::LOrExpContext>(0);
}

tree::TerminalNode* CactParser::PrimaryExpContext::R_PAREN() {
  return getToken(CactParser::R_PAREN, 0);
}

tree::TerminalNode* CactParser::PrimaryExpContext::IDENT() {
  return getToken(CactParser::IDENT, 0);
}

std::vector<tree::TerminalNode *> CactParser::PrimaryExpContext::L_BRACKET() {
  return getTokens(CactParser::L_BRACKET);
}

tree::TerminalNode* CactParser::PrimaryExpContext::L_BRACKET(size_t i) {
  return getToken(CactParser::L_BRACKET, i);
}

std::vector<CactParser::ExpContext *> CactParser::PrimaryExpContext::exp() {
  return getRuleContexts<CactParser::ExpContext>();
}

CactParser::ExpContext* CactParser::PrimaryExpContext::exp(size_t i) {
  return getRuleContext<CactParser::ExpContext>(i);
}

std::vector<tree::TerminalNode *> CactParser::PrimaryExpContext::R_BRACKET() {
  return getTokens(CactParser::R_BRACKET);
}

tree::TerminalNode* CactParser::PrimaryExpContext::R_BRACKET(size_t i) {
  return getToken(CactParser::R_BRACKET, i);
}

CactParser::NumberContext* CactParser::PrimaryExpContext::number() {
  return getRuleContext<CactParser::NumberContext>(0);
}

CactParser::BoolConstContext* CactParser::PrimaryExpContext::boolConst() {
  return getRuleContext<CactParser::BoolConstContext>(0);
}


size_t CactParser::PrimaryExpContext::getRuleIndex() const {
  return CactParser::RulePrimaryExp;
}


std::any CactParser::PrimaryExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitPrimaryExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::PrimaryExpContext* CactParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 48, CactParser::RulePrimaryExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(313);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::L_PAREN: {
        enterOuterAlt(_localctx, 1);
        setState(297);
        match(CactParser::L_PAREN);
        setState(298);
        lOrExp();
        setState(299);
        match(CactParser::R_PAREN);
        break;
      }

      case CactParser::IDENT: {
        enterOuterAlt(_localctx, 2);
        setState(301);
        match(CactParser::IDENT);
        setState(308);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CactParser::L_BRACKET) {
          setState(302);
          match(CactParser::L_BRACKET);
          setState(303);
          exp();
          setState(304);
          match(CactParser::R_BRACKET);
          setState(310);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case CactParser::DECIMAL_CONST:
      case CactParser::OCTAL_CONST:
      case CactParser::HEXADECIMAL_CONST:
      case CactParser::FloatConst:
      case CactParser::EXPONENT:
      case CactParser::HexFloat:
      case CactParser::CharConst: {
        enterOuterAlt(_localctx, 3);
        setState(311);
        number();
        break;
      }

      case CactParser::FALSE:
      case CactParser::TRUE: {
        enterOuterAlt(_localctx, 4);
        setState(312);
        boolConst();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExpContext ------------------------------------------------------------------

CactParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::PrimaryExpContext* CactParser::UnaryExpContext::primaryExp() {
  return getRuleContext<CactParser::PrimaryExpContext>(0);
}

CactParser::UnaryOpContext* CactParser::UnaryExpContext::unaryOp() {
  return getRuleContext<CactParser::UnaryOpContext>(0);
}

CactParser::UnaryExpContext* CactParser::UnaryExpContext::unaryExp() {
  return getRuleContext<CactParser::UnaryExpContext>(0);
}

tree::TerminalNode* CactParser::UnaryExpContext::IDENT() {
  return getToken(CactParser::IDENT, 0);
}

tree::TerminalNode* CactParser::UnaryExpContext::L_PAREN() {
  return getToken(CactParser::L_PAREN, 0);
}

tree::TerminalNode* CactParser::UnaryExpContext::R_PAREN() {
  return getToken(CactParser::R_PAREN, 0);
}

CactParser::FuncRParamsContext* CactParser::UnaryExpContext::funcRParams() {
  return getRuleContext<CactParser::FuncRParamsContext>(0);
}


size_t CactParser::UnaryExpContext::getRuleIndex() const {
  return CactParser::RuleUnaryExp;
}


std::any CactParser::UnaryExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitUnaryExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::UnaryExpContext* CactParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 50, CactParser::RuleUnaryExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(325);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(315);
      primaryExp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(316);
      unaryOp();
      setState(317);
      unaryExp();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(319);
      match(CactParser::IDENT);
      setState(320);
      match(CactParser::L_PAREN);
      setState(322);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1099763269632) != 0)) {
        setState(321);
        funcRParams();
      }
      setState(324);
      match(CactParser::R_PAREN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOpContext ------------------------------------------------------------------

CactParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::UnaryOpContext::PLUS() {
  return getToken(CactParser::PLUS, 0);
}

tree::TerminalNode* CactParser::UnaryOpContext::MINUS() {
  return getToken(CactParser::MINUS, 0);
}

tree::TerminalNode* CactParser::UnaryOpContext::NOT() {
  return getToken(CactParser::NOT, 0);
}


size_t CactParser::UnaryOpContext::getRuleIndex() const {
  return CactParser::RuleUnaryOp;
}


std::any CactParser::UnaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitUnaryOp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::UnaryOpContext* CactParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 52, CactParser::RuleUnaryOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 234881024) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExpContext ------------------------------------------------------------------

CactParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CactParser::UnaryExpContext *> CactParser::MulExpContext::unaryExp() {
  return getRuleContexts<CactParser::UnaryExpContext>();
}

CactParser::UnaryExpContext* CactParser::MulExpContext::unaryExp(size_t i) {
  return getRuleContext<CactParser::UnaryExpContext>(i);
}

std::vector<CactParser::MulOpContext *> CactParser::MulExpContext::mulOp() {
  return getRuleContexts<CactParser::MulOpContext>();
}

CactParser::MulOpContext* CactParser::MulExpContext::mulOp(size_t i) {
  return getRuleContext<CactParser::MulOpContext>(i);
}


size_t CactParser::MulExpContext::getRuleIndex() const {
  return CactParser::RuleMulExp;
}


std::any CactParser::MulExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitMulExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::MulExpContext* CactParser::mulExp() {
  MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, getState());
  enterRule(_localctx, 54, CactParser::RuleMulExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(329);
    unaryExp();
    setState(335);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1879048192) != 0)) {
      setState(330);
      mulOp();
      setState(331);
      unaryExp();
      setState(337);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulOpContext ------------------------------------------------------------------

CactParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::MulOpContext::MUL() {
  return getToken(CactParser::MUL, 0);
}

tree::TerminalNode* CactParser::MulOpContext::DIV() {
  return getToken(CactParser::DIV, 0);
}

tree::TerminalNode* CactParser::MulOpContext::MOD() {
  return getToken(CactParser::MOD, 0);
}


size_t CactParser::MulOpContext::getRuleIndex() const {
  return CactParser::RuleMulOp;
}


std::any CactParser::MulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitMulOp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::MulOpContext* CactParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 56, CactParser::RuleMulOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1879048192) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

CactParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CactParser::MulExpContext *> CactParser::AddExpContext::mulExp() {
  return getRuleContexts<CactParser::MulExpContext>();
}

CactParser::MulExpContext* CactParser::AddExpContext::mulExp(size_t i) {
  return getRuleContext<CactParser::MulExpContext>(i);
}

std::vector<CactParser::AddOpContext *> CactParser::AddExpContext::addOp() {
  return getRuleContexts<CactParser::AddOpContext>();
}

CactParser::AddOpContext* CactParser::AddExpContext::addOp(size_t i) {
  return getRuleContext<CactParser::AddOpContext>(i);
}


size_t CactParser::AddExpContext::getRuleIndex() const {
  return CactParser::RuleAddExp;
}


std::any CactParser::AddExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitAddExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::AddExpContext* CactParser::addExp() {
  AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, getState());
  enterRule(_localctx, 58, CactParser::RuleAddExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(340);
    mulExp();
    setState(346);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::PLUS

    || _la == CactParser::MINUS) {
      setState(341);
      addOp();
      setState(342);
      mulExp();
      setState(348);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddOpContext ------------------------------------------------------------------

CactParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::AddOpContext::PLUS() {
  return getToken(CactParser::PLUS, 0);
}

tree::TerminalNode* CactParser::AddOpContext::MINUS() {
  return getToken(CactParser::MINUS, 0);
}


size_t CactParser::AddOpContext::getRuleIndex() const {
  return CactParser::RuleAddOp;
}


std::any CactParser::AddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitAddOp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::AddOpContext* CactParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 60, CactParser::RuleAddOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(349);
    _la = _input->LA(1);
    if (!(_la == CactParser::PLUS

    || _la == CactParser::MINUS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

CactParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CactParser::AddExpContext *> CactParser::RelExpContext::addExp() {
  return getRuleContexts<CactParser::AddExpContext>();
}

CactParser::AddExpContext* CactParser::RelExpContext::addExp(size_t i) {
  return getRuleContext<CactParser::AddExpContext>(i);
}

CactParser::RelOpContext* CactParser::RelExpContext::relOp() {
  return getRuleContext<CactParser::RelOpContext>(0);
}


size_t CactParser::RelExpContext::getRuleIndex() const {
  return CactParser::RuleRelExp;
}


std::any CactParser::RelExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitRelExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::RelExpContext* CactParser::relExp() {
  RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, getState());
  enterRule(_localctx, 62, CactParser::RuleRelExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(351);
    addExp();
    setState(355);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 257698037760) != 0)) {
      setState(352);
      relOp();
      setState(353);
      addExp();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelOpContext ------------------------------------------------------------------

CactParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::RelOpContext::GT() {
  return getToken(CactParser::GT, 0);
}

tree::TerminalNode* CactParser::RelOpContext::LT() {
  return getToken(CactParser::LT, 0);
}

tree::TerminalNode* CactParser::RelOpContext::GE() {
  return getToken(CactParser::GE, 0);
}

tree::TerminalNode* CactParser::RelOpContext::LE() {
  return getToken(CactParser::LE, 0);
}


size_t CactParser::RelOpContext::getRuleIndex() const {
  return CactParser::RuleRelOp;
}


std::any CactParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::RelOpContext* CactParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 64, CactParser::RuleRelOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 257698037760) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

CactParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CactParser::RelExpContext *> CactParser::EqExpContext::relExp() {
  return getRuleContexts<CactParser::RelExpContext>();
}

CactParser::RelExpContext* CactParser::EqExpContext::relExp(size_t i) {
  return getRuleContext<CactParser::RelExpContext>(i);
}

CactParser::EqOpContext* CactParser::EqExpContext::eqOp() {
  return getRuleContext<CactParser::EqOpContext>(0);
}


size_t CactParser::EqExpContext::getRuleIndex() const {
  return CactParser::RuleEqExp;
}


std::any CactParser::EqExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitEqExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::EqExpContext* CactParser::eqExp() {
  EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, getState());
  enterRule(_localctx, 66, CactParser::RuleEqExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(359);
    relExp();
    setState(363);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CactParser::EQ

    || _la == CactParser::NEQ) {
      setState(360);
      eqOp();
      setState(361);
      relExp();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqOpContext ------------------------------------------------------------------

CactParser::EqOpContext::EqOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::EqOpContext::EQ() {
  return getToken(CactParser::EQ, 0);
}

tree::TerminalNode* CactParser::EqOpContext::NEQ() {
  return getToken(CactParser::NEQ, 0);
}


size_t CactParser::EqOpContext::getRuleIndex() const {
  return CactParser::RuleEqOp;
}


std::any CactParser::EqOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitEqOp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::EqOpContext* CactParser::eqOp() {
  EqOpContext *_localctx = _tracker.createInstance<EqOpContext>(_ctx, getState());
  enterRule(_localctx, 68, CactParser::RuleEqOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(365);
    _la = _input->LA(1);
    if (!(_la == CactParser::EQ

    || _la == CactParser::NEQ)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

CactParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CactParser::EqExpContext *> CactParser::LAndExpContext::eqExp() {
  return getRuleContexts<CactParser::EqExpContext>();
}

CactParser::EqExpContext* CactParser::LAndExpContext::eqExp(size_t i) {
  return getRuleContext<CactParser::EqExpContext>(i);
}

std::vector<tree::TerminalNode *> CactParser::LAndExpContext::AND() {
  return getTokens(CactParser::AND);
}

tree::TerminalNode* CactParser::LAndExpContext::AND(size_t i) {
  return getToken(CactParser::AND, i);
}


size_t CactParser::LAndExpContext::getRuleIndex() const {
  return CactParser::RuleLAndExp;
}


std::any CactParser::LAndExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitLAndExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::LAndExpContext* CactParser::lAndExp() {
  LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, getState());
  enterRule(_localctx, 70, CactParser::RuleLAndExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    eqExp();
    setState(372);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::AND) {
      setState(368);
      match(CactParser::AND);
      setState(369);
      eqExp();
      setState(374);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

CactParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CactParser::LAndExpContext *> CactParser::LOrExpContext::lAndExp() {
  return getRuleContexts<CactParser::LAndExpContext>();
}

CactParser::LAndExpContext* CactParser::LOrExpContext::lAndExp(size_t i) {
  return getRuleContext<CactParser::LAndExpContext>(i);
}

std::vector<tree::TerminalNode *> CactParser::LOrExpContext::OR() {
  return getTokens(CactParser::OR);
}

tree::TerminalNode* CactParser::LOrExpContext::OR(size_t i) {
  return getToken(CactParser::OR, i);
}


size_t CactParser::LOrExpContext::getRuleIndex() const {
  return CactParser::RuleLOrExp;
}


std::any CactParser::LOrExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitLOrExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::LOrExpContext* CactParser::lOrExp() {
  LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, getState());
  enterRule(_localctx, 72, CactParser::RuleLOrExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(375);
    lAndExp();
    setState(380);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::OR) {
      setState(376);
      match(CactParser::OR);
      setState(377);
      lAndExp();
      setState(382);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntConstContext ------------------------------------------------------------------

CactParser::IntConstContext::IntConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::IntConstContext::DECIMAL_CONST() {
  return getToken(CactParser::DECIMAL_CONST, 0);
}

tree::TerminalNode* CactParser::IntConstContext::OCTAL_CONST() {
  return getToken(CactParser::OCTAL_CONST, 0);
}

tree::TerminalNode* CactParser::IntConstContext::HEXADECIMAL_CONST() {
  return getToken(CactParser::HEXADECIMAL_CONST, 0);
}


size_t CactParser::IntConstContext::getRuleIndex() const {
  return CactParser::RuleIntConst;
}


std::any CactParser::IntConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitIntConst(this);
  else
    return visitor->visitChildren(this);
}

CactParser::IntConstContext* CactParser::intConst() {
  IntConstContext *_localctx = _tracker.createInstance<IntConstContext>(_ctx, getState());
  enterRule(_localctx, 74, CactParser::RuleIntConst);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(383);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 917504) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolConstContext ------------------------------------------------------------------

CactParser::BoolConstContext::BoolConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CactParser::BoolConstContext::TRUE() {
  return getToken(CactParser::TRUE, 0);
}

tree::TerminalNode* CactParser::BoolConstContext::FALSE() {
  return getToken(CactParser::FALSE, 0);
}


size_t CactParser::BoolConstContext::getRuleIndex() const {
  return CactParser::RuleBoolConst;
}


std::any CactParser::BoolConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitBoolConst(this);
  else
    return visitor->visitChildren(this);
}

CactParser::BoolConstContext* CactParser::boolConst() {
  BoolConstContext *_localctx = _tracker.createInstance<BoolConstContext>(_ctx, getState());
  enterRule(_localctx, 76, CactParser::RuleBoolConst);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(385);
    _la = _input->LA(1);
    if (!(_la == CactParser::FALSE

    || _la == CactParser::TRUE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void CactParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  cactParserInitialize();
#else
  ::antlr4::internal::call_once(cactParserOnceFlag, cactParserInitialize);
#endif
}
