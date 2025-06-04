
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
      "block", "blockItem", "stmt", "exp", "cond", "lVal", "number", "funcRParams", 
      "primaryExp", "unaryExp", "unaryOp", "mulExp", "mulOp", "addExp", 
      "addOp", "relExp", "relOp", "eqExp", "eqOp", "lAndExp", "lOrExp", 
      "intConst", "boolConst"
    },
    std::vector<std::string>{
      "", "'const'", "'int'", "'double'", "'char'", "'float'", "'bool'", 
      "'void'", "'if'", "'else'", "'while'", "'break'", "'continue'", "'return'", 
      "'false'", "'true'", "", "", "", "", "", "", "", "", "'+'", "'-'", 
      "'!'", "'*'", "'/'", "'%'", "'='", "'=='", "'!='", "'>'", "'<'", "'>='", 
      "'<='", "'&&'", "'||'", "'('", "')'", "'{'", "'}'", "'['", "']'", 
      "','", "';'", "'\"'"
    },
    std::vector<std::string>{
      "", "CONST_KW", "INT_KW", "DOUBLE_KW", "CHAR_KW", "FLOAT_KW", "BOOL_KW", 
      "VOID_KW", "IF_KW", "ELSE_KW", "WHILE_KW", "BREAK_KW", "CONTINUE_KW", 
      "RETURN_KW", "FALSE", "TRUE", "IDENT", "DECIMAL_CONST", "OCTAL_CONST", 
      "HEXADECIMAL_CONST", "FloatConst", "EXPONENT", "CharConst", "STRING", 
      "PLUS", "MINUS", "NOT", "MUL", "DIV", "MOD", "ASSIGN", "EQ", "NEQ", 
      "GT", "LT", "GE", "LE", "AND", "OR", "L_PAREN", "R_PAREN", "L_BRACE", 
      "R_BRACE", "L_BRACKET", "R_BRACKET", "COMMA", "SEMICOLON", "DOUBLE_QUOTE", 
      "WS", "LineComment", "BlockComment"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,50,364,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,1,0,1,0,1,1,1,1,4,1,77,8,1,11,1,12,1,78,1,1,1,1,1,2,1,2,3,2,85,8,2,
  	1,3,1,3,1,4,1,4,1,4,1,4,1,4,5,4,94,8,4,10,4,12,4,97,9,4,1,4,1,4,1,5,1,
  	5,1,5,1,5,1,5,5,5,106,8,5,10,5,12,5,109,9,5,1,5,1,5,1,5,1,6,1,6,1,6,1,
  	6,1,6,5,6,119,8,6,10,6,12,6,122,9,6,3,6,124,8,6,1,6,1,6,3,6,128,8,6,1,
  	7,1,7,1,7,1,7,5,7,134,8,7,10,7,12,7,137,9,7,1,7,1,7,1,8,1,8,1,8,1,8,1,
  	8,5,8,146,8,8,10,8,12,8,149,9,8,1,8,1,8,3,8,153,8,8,1,9,1,9,1,9,1,9,3,
  	9,159,8,9,1,9,1,9,1,9,1,10,1,10,3,10,166,8,10,1,11,1,11,1,11,5,11,171,
  	8,11,10,11,12,11,174,9,11,1,12,1,12,1,12,1,12,3,12,180,8,12,1,12,1,12,
  	1,12,1,12,1,12,5,12,187,8,12,10,12,12,12,190,9,12,3,12,192,8,12,1,13,
  	1,13,5,13,196,8,13,10,13,12,13,199,9,13,1,13,1,13,1,14,1,14,3,14,205,
  	8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	3,15,220,8,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,3,15,234,8,15,1,15,1,15,3,15,238,8,15,1,15,3,15,241,8,15,1,16,1,
  	16,1,17,1,17,1,18,1,18,1,18,1,18,1,18,5,18,252,8,18,10,18,12,18,255,9,
  	18,1,19,1,19,1,19,1,19,3,19,261,8,19,1,20,1,20,1,20,5,20,266,8,20,10,
  	20,12,20,269,9,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,5,21,280,
  	8,21,10,21,12,21,283,9,21,1,21,1,21,3,21,287,8,21,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,3,22,296,8,22,1,22,3,22,299,8,22,1,23,1,23,1,24,1,24,1,
  	24,1,24,5,24,307,8,24,10,24,12,24,310,9,24,1,25,1,25,1,26,1,26,1,26,1,
  	26,5,26,318,8,26,10,26,12,26,321,9,26,1,27,1,27,1,28,1,28,1,28,1,28,3,
  	28,329,8,28,1,29,1,29,1,30,1,30,1,30,1,30,3,30,337,8,30,1,31,1,31,1,32,
  	1,32,1,32,5,32,344,8,32,10,32,12,32,347,9,32,1,33,1,33,1,33,5,33,352,
  	8,33,10,33,12,33,355,9,33,1,34,3,34,358,8,34,1,34,1,34,1,35,1,35,1,35,
  	0,0,36,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,
  	46,48,50,52,54,56,58,60,62,64,66,68,70,0,8,1,0,2,6,1,0,24,26,1,0,27,29,
  	1,0,24,25,1,0,33,36,1,0,31,32,1,0,17,19,1,0,14,15,376,0,72,1,0,0,0,2,
  	76,1,0,0,0,4,84,1,0,0,0,6,86,1,0,0,0,8,88,1,0,0,0,10,100,1,0,0,0,12,127,
  	1,0,0,0,14,129,1,0,0,0,16,140,1,0,0,0,18,154,1,0,0,0,20,165,1,0,0,0,22,
  	167,1,0,0,0,24,175,1,0,0,0,26,193,1,0,0,0,28,204,1,0,0,0,30,240,1,0,0,
  	0,32,242,1,0,0,0,34,244,1,0,0,0,36,246,1,0,0,0,38,260,1,0,0,0,40,262,
  	1,0,0,0,42,286,1,0,0,0,44,298,1,0,0,0,46,300,1,0,0,0,48,302,1,0,0,0,50,
  	311,1,0,0,0,52,313,1,0,0,0,54,322,1,0,0,0,56,324,1,0,0,0,58,330,1,0,0,
  	0,60,332,1,0,0,0,62,338,1,0,0,0,64,340,1,0,0,0,66,348,1,0,0,0,68,357,
  	1,0,0,0,70,361,1,0,0,0,72,73,3,2,1,0,73,1,1,0,0,0,74,77,3,4,2,0,75,77,
  	3,18,9,0,76,74,1,0,0,0,76,75,1,0,0,0,77,78,1,0,0,0,78,76,1,0,0,0,78,79,
  	1,0,0,0,79,80,1,0,0,0,80,81,5,0,0,1,81,3,1,0,0,0,82,85,3,8,4,0,83,85,
  	3,14,7,0,84,82,1,0,0,0,84,83,1,0,0,0,85,5,1,0,0,0,86,87,7,0,0,0,87,7,
  	1,0,0,0,88,89,5,1,0,0,89,90,3,6,3,0,90,95,3,10,5,0,91,92,5,45,0,0,92,
  	94,3,10,5,0,93,91,1,0,0,0,94,97,1,0,0,0,95,93,1,0,0,0,95,96,1,0,0,0,96,
  	98,1,0,0,0,97,95,1,0,0,0,98,99,5,46,0,0,99,9,1,0,0,0,100,107,5,16,0,0,
  	101,102,5,43,0,0,102,103,3,68,34,0,103,104,5,44,0,0,104,106,1,0,0,0,105,
  	101,1,0,0,0,106,109,1,0,0,0,107,105,1,0,0,0,107,108,1,0,0,0,108,110,1,
  	0,0,0,109,107,1,0,0,0,110,111,5,30,0,0,111,112,3,12,6,0,112,11,1,0,0,
  	0,113,128,3,38,19,0,114,123,5,41,0,0,115,120,3,12,6,0,116,117,5,45,0,
  	0,117,119,3,12,6,0,118,116,1,0,0,0,119,122,1,0,0,0,120,118,1,0,0,0,120,
  	121,1,0,0,0,121,124,1,0,0,0,122,120,1,0,0,0,123,115,1,0,0,0,123,124,1,
  	0,0,0,124,125,1,0,0,0,125,128,5,42,0,0,126,128,3,70,35,0,127,113,1,0,
  	0,0,127,114,1,0,0,0,127,126,1,0,0,0,128,13,1,0,0,0,129,130,3,6,3,0,130,
  	135,3,16,8,0,131,132,5,45,0,0,132,134,3,16,8,0,133,131,1,0,0,0,134,137,
  	1,0,0,0,135,133,1,0,0,0,135,136,1,0,0,0,136,138,1,0,0,0,137,135,1,0,0,
  	0,138,139,5,46,0,0,139,15,1,0,0,0,140,147,5,16,0,0,141,142,5,43,0,0,142,
  	143,3,68,34,0,143,144,5,44,0,0,144,146,1,0,0,0,145,141,1,0,0,0,146,149,
  	1,0,0,0,147,145,1,0,0,0,147,148,1,0,0,0,148,152,1,0,0,0,149,147,1,0,0,
  	0,150,151,5,30,0,0,151,153,3,12,6,0,152,150,1,0,0,0,152,153,1,0,0,0,153,
  	17,1,0,0,0,154,155,3,20,10,0,155,156,5,16,0,0,156,158,5,39,0,0,157,159,
  	3,22,11,0,158,157,1,0,0,0,158,159,1,0,0,0,159,160,1,0,0,0,160,161,5,40,
  	0,0,161,162,3,26,13,0,162,19,1,0,0,0,163,166,3,6,3,0,164,166,5,7,0,0,
  	165,163,1,0,0,0,165,164,1,0,0,0,166,21,1,0,0,0,167,172,3,24,12,0,168,
  	169,5,45,0,0,169,171,3,24,12,0,170,168,1,0,0,0,171,174,1,0,0,0,172,170,
  	1,0,0,0,172,173,1,0,0,0,173,23,1,0,0,0,174,172,1,0,0,0,175,176,3,6,3,
  	0,176,191,5,16,0,0,177,179,5,43,0,0,178,180,3,68,34,0,179,178,1,0,0,0,
  	179,180,1,0,0,0,180,181,1,0,0,0,181,188,5,44,0,0,182,183,5,43,0,0,183,
  	184,3,68,34,0,184,185,5,44,0,0,185,187,1,0,0,0,186,182,1,0,0,0,187,190,
  	1,0,0,0,188,186,1,0,0,0,188,189,1,0,0,0,189,192,1,0,0,0,190,188,1,0,0,
  	0,191,177,1,0,0,0,191,192,1,0,0,0,192,25,1,0,0,0,193,197,5,41,0,0,194,
  	196,3,28,14,0,195,194,1,0,0,0,196,199,1,0,0,0,197,195,1,0,0,0,197,198,
  	1,0,0,0,198,200,1,0,0,0,199,197,1,0,0,0,200,201,5,42,0,0,201,27,1,0,0,
  	0,202,205,3,4,2,0,203,205,3,30,15,0,204,202,1,0,0,0,204,203,1,0,0,0,205,
  	29,1,0,0,0,206,207,3,36,18,0,207,208,5,30,0,0,208,209,3,32,16,0,209,210,
  	5,46,0,0,210,241,1,0,0,0,211,241,3,26,13,0,212,213,5,8,0,0,213,214,5,
  	39,0,0,214,215,3,34,17,0,215,216,5,40,0,0,216,219,3,30,15,0,217,218,5,
  	9,0,0,218,220,3,30,15,0,219,217,1,0,0,0,219,220,1,0,0,0,220,241,1,0,0,
  	0,221,222,5,10,0,0,222,223,5,39,0,0,223,224,3,34,17,0,224,225,5,40,0,
  	0,225,226,3,30,15,0,226,241,1,0,0,0,227,228,5,11,0,0,228,241,5,46,0,0,
  	229,230,5,12,0,0,230,241,5,46,0,0,231,233,5,13,0,0,232,234,3,32,16,0,
  	233,232,1,0,0,0,233,234,1,0,0,0,234,235,1,0,0,0,235,241,5,46,0,0,236,
  	238,3,32,16,0,237,236,1,0,0,0,237,238,1,0,0,0,238,239,1,0,0,0,239,241,
  	5,46,0,0,240,206,1,0,0,0,240,211,1,0,0,0,240,212,1,0,0,0,240,221,1,0,
  	0,0,240,227,1,0,0,0,240,229,1,0,0,0,240,231,1,0,0,0,240,237,1,0,0,0,241,
  	31,1,0,0,0,242,243,3,52,26,0,243,33,1,0,0,0,244,245,3,66,33,0,245,35,
  	1,0,0,0,246,253,5,16,0,0,247,248,5,43,0,0,248,249,3,32,16,0,249,250,5,
  	44,0,0,250,252,1,0,0,0,251,247,1,0,0,0,252,255,1,0,0,0,253,251,1,0,0,
  	0,253,254,1,0,0,0,254,37,1,0,0,0,255,253,1,0,0,0,256,261,3,68,34,0,257,
  	261,5,20,0,0,258,261,5,21,0,0,259,261,5,22,0,0,260,256,1,0,0,0,260,257,
  	1,0,0,0,260,258,1,0,0,0,260,259,1,0,0,0,261,39,1,0,0,0,262,267,3,32,16,
  	0,263,264,5,45,0,0,264,266,3,32,16,0,265,263,1,0,0,0,266,269,1,0,0,0,
  	267,265,1,0,0,0,267,268,1,0,0,0,268,41,1,0,0,0,269,267,1,0,0,0,270,271,
  	5,39,0,0,271,272,3,32,16,0,272,273,5,40,0,0,273,287,1,0,0,0,274,281,5,
  	16,0,0,275,276,5,43,0,0,276,277,3,32,16,0,277,278,5,44,0,0,278,280,1,
  	0,0,0,279,275,1,0,0,0,280,283,1,0,0,0,281,279,1,0,0,0,281,282,1,0,0,0,
  	282,287,1,0,0,0,283,281,1,0,0,0,284,287,3,38,19,0,285,287,3,70,35,0,286,
  	270,1,0,0,0,286,274,1,0,0,0,286,284,1,0,0,0,286,285,1,0,0,0,287,43,1,
  	0,0,0,288,299,3,42,21,0,289,290,3,46,23,0,290,291,3,44,22,0,291,299,1,
  	0,0,0,292,293,5,16,0,0,293,295,5,39,0,0,294,296,3,40,20,0,295,294,1,0,
  	0,0,295,296,1,0,0,0,296,297,1,0,0,0,297,299,5,40,0,0,298,288,1,0,0,0,
  	298,289,1,0,0,0,298,292,1,0,0,0,299,45,1,0,0,0,300,301,7,1,0,0,301,47,
  	1,0,0,0,302,308,3,44,22,0,303,304,3,50,25,0,304,305,3,44,22,0,305,307,
  	1,0,0,0,306,303,1,0,0,0,307,310,1,0,0,0,308,306,1,0,0,0,308,309,1,0,0,
  	0,309,49,1,0,0,0,310,308,1,0,0,0,311,312,7,2,0,0,312,51,1,0,0,0,313,319,
  	3,48,24,0,314,315,3,54,27,0,315,316,3,48,24,0,316,318,1,0,0,0,317,314,
  	1,0,0,0,318,321,1,0,0,0,319,317,1,0,0,0,319,320,1,0,0,0,320,53,1,0,0,
  	0,321,319,1,0,0,0,322,323,7,3,0,0,323,55,1,0,0,0,324,328,3,52,26,0,325,
  	326,3,58,29,0,326,327,3,52,26,0,327,329,1,0,0,0,328,325,1,0,0,0,328,329,
  	1,0,0,0,329,57,1,0,0,0,330,331,7,4,0,0,331,59,1,0,0,0,332,336,3,56,28,
  	0,333,334,3,62,31,0,334,335,3,56,28,0,335,337,1,0,0,0,336,333,1,0,0,0,
  	336,337,1,0,0,0,337,61,1,0,0,0,338,339,7,5,0,0,339,63,1,0,0,0,340,345,
  	3,60,30,0,341,342,5,37,0,0,342,344,3,60,30,0,343,341,1,0,0,0,344,347,
  	1,0,0,0,345,343,1,0,0,0,345,346,1,0,0,0,346,65,1,0,0,0,347,345,1,0,0,
  	0,348,353,3,64,32,0,349,350,5,38,0,0,350,352,3,64,32,0,351,349,1,0,0,
  	0,352,355,1,0,0,0,353,351,1,0,0,0,353,354,1,0,0,0,354,67,1,0,0,0,355,
  	353,1,0,0,0,356,358,7,3,0,0,357,356,1,0,0,0,357,358,1,0,0,0,358,359,1,
  	0,0,0,359,360,7,6,0,0,360,69,1,0,0,0,361,362,7,7,0,0,362,71,1,0,0,0,37,
  	76,78,84,95,107,120,123,127,135,147,152,158,165,172,179,188,191,197,204,
  	219,233,237,240,253,260,267,281,286,295,298,308,319,328,336,345,353,357
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
    setState(72);
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
    setState(76); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(76);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(74);
        decl();
        break;
      }

      case 2: {
        setState(75);
        funcDef();
        break;
      }

      default:
        break;
      }
      setState(78); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 254) != 0));
    setState(80);
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
    setState(84);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::CONST_KW: {
        enterOuterAlt(_localctx, 1);
        setState(82);
        constDecl();
        break;
      }

      case CactParser::INT_KW:
      case CactParser::DOUBLE_KW:
      case CactParser::CHAR_KW:
      case CactParser::FLOAT_KW:
      case CactParser::BOOL_KW: {
        enterOuterAlt(_localctx, 2);
        setState(83);
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
    setState(86);
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
    setState(88);
    match(CactParser::CONST_KW);
    setState(89);
    bType();
    setState(90);
    constDef();
    setState(95);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::COMMA) {
      setState(91);
      match(CactParser::COMMA);
      setState(92);
      constDef();
      setState(97);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(98);
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
    setState(100);
    match(CactParser::IDENT);
    setState(107);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::L_BRACKET) {
      setState(101);
      match(CactParser::L_BRACKET);
      setState(102);
      intConst();
      setState(103);
      match(CactParser::R_BRACKET);
      setState(109);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(110);
    match(CactParser::ASSIGN);
    setState(111);
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

CactParser::NumberContext* CactParser::ConstInitValContext::number() {
  return getRuleContext<CactParser::NumberContext>(0);
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
    setState(127);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::DECIMAL_CONST:
      case CactParser::OCTAL_CONST:
      case CactParser::HEXADECIMAL_CONST:
      case CactParser::FloatConst:
      case CactParser::EXPONENT:
      case CactParser::CharConst:
      case CactParser::PLUS:
      case CactParser::MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(113);
        number();
        break;
      }

      case CactParser::L_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(114);
        match(CactParser::L_BRACE);
        setState(123);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 2199081893888) != 0)) {
          setState(115);
          constInitVal();
          setState(120);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == CactParser::COMMA) {
            setState(116);
            match(CactParser::COMMA);
            setState(117);
            constInitVal();
            setState(122);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(125);
        match(CactParser::R_BRACE);
        break;
      }

      case CactParser::FALSE:
      case CactParser::TRUE: {
        enterOuterAlt(_localctx, 3);
        setState(126);
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
    setState(129);
    bType();
    setState(130);
    varDef();
    setState(135);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::COMMA) {
      setState(131);
      match(CactParser::COMMA);
      setState(132);
      varDef();
      setState(137);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(138);
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
    setState(140);
    match(CactParser::IDENT);
    setState(147);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::L_BRACKET) {
      setState(141);
      match(CactParser::L_BRACKET);
      setState(142);
      intConst();
      setState(143);
      match(CactParser::R_BRACKET);
      setState(149);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(152);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CactParser::ASSIGN) {
      setState(150);
      match(CactParser::ASSIGN);
      setState(151);
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
    setState(154);
    funcType();
    setState(155);
    match(CactParser::IDENT);
    setState(156);
    match(CactParser::L_PAREN);
    setState(158);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 124) != 0)) {
      setState(157);
      funcFParams();
    }
    setState(160);
    match(CactParser::R_PAREN);
    setState(161);
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
    setState(165);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::INT_KW:
      case CactParser::DOUBLE_KW:
      case CactParser::CHAR_KW:
      case CactParser::FLOAT_KW:
      case CactParser::BOOL_KW: {
        enterOuterAlt(_localctx, 1);
        setState(163);
        bType();
        break;
      }

      case CactParser::VOID_KW: {
        enterOuterAlt(_localctx, 2);
        setState(164);
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
    setState(167);
    funcFParam();
    setState(172);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::COMMA) {
      setState(168);
      match(CactParser::COMMA);
      setState(169);
      funcFParam();
      setState(174);
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
    setState(175);
    bType();
    setState(176);
    match(CactParser::IDENT);
    setState(191);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CactParser::L_BRACKET) {
      setState(177);
      match(CactParser::L_BRACKET);
      setState(179);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 51249152) != 0)) {
        setState(178);
        intConst();
      }
      setState(181);
      match(CactParser::R_BRACKET);
      setState(188);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CactParser::L_BRACKET) {
        setState(182);
        match(CactParser::L_BRACKET);
        setState(183);
        intConst();
        setState(184);
        match(CactParser::R_BRACKET);
        setState(190);
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
    setState(193);
    match(CactParser::L_BRACE);
    setState(197);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 73117649075582) != 0)) {
      setState(194);
      blockItem();
      setState(199);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(200);
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
    setState(204);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::CONST_KW:
      case CactParser::INT_KW:
      case CactParser::DOUBLE_KW:
      case CactParser::CHAR_KW:
      case CactParser::FLOAT_KW:
      case CactParser::BOOL_KW: {
        enterOuterAlt(_localctx, 1);
        setState(202);
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
      case CactParser::CharConst:
      case CactParser::PLUS:
      case CactParser::MINUS:
      case CactParser::NOT:
      case CactParser::L_PAREN:
      case CactParser::L_BRACE:
      case CactParser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);
        setState(203);
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

std::vector<CactParser::StmtContext *> CactParser::StmtContext::stmt() {
  return getRuleContexts<CactParser::StmtContext>();
}

CactParser::StmtContext* CactParser::StmtContext::stmt(size_t i) {
  return getRuleContext<CactParser::StmtContext>(i);
}

tree::TerminalNode* CactParser::StmtContext::ELSE_KW() {
  return getToken(CactParser::ELSE_KW, 0);
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
    setState(240);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(206);
      lVal();
      setState(207);
      match(CactParser::ASSIGN);
      setState(208);
      exp();
      setState(209);
      match(CactParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(211);
      block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(212);
      match(CactParser::IF_KW);
      setState(213);
      match(CactParser::L_PAREN);
      setState(214);
      cond();
      setState(215);
      match(CactParser::R_PAREN);
      setState(216);
      stmt();
      setState(219);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
      case 1: {
        setState(217);
        match(CactParser::ELSE_KW);
        setState(218);
        stmt();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(221);
      match(CactParser::WHILE_KW);
      setState(222);
      match(CactParser::L_PAREN);
      setState(223);
      cond();
      setState(224);
      match(CactParser::R_PAREN);
      setState(225);
      stmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(227);
      match(CactParser::BREAK_KW);
      setState(228);
      match(CactParser::SEMICOLON);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(229);
      match(CactParser::CONTINUE_KW);
      setState(230);
      match(CactParser::SEMICOLON);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(231);
      match(CactParser::RETURN_KW);
      setState(233);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 549881626624) != 0)) {
        setState(232);
        exp();
      }
      setState(235);
      match(CactParser::SEMICOLON);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(237);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 549881626624) != 0)) {
        setState(236);
        exp();
      }
      setState(239);
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
  enterRule(_localctx, 32, CactParser::RuleExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
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
  enterRule(_localctx, 34, CactParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
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
  enterRule(_localctx, 36, CactParser::RuleLVal);
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
    setState(246);
    match(CactParser::IDENT);
    setState(253);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::L_BRACKET) {
      setState(247);
      match(CactParser::L_BRACKET);
      setState(248);
      exp();
      setState(249);
      match(CactParser::R_BRACKET);
      setState(255);
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
  enterRule(_localctx, 38, CactParser::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(260);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::DECIMAL_CONST:
      case CactParser::OCTAL_CONST:
      case CactParser::HEXADECIMAL_CONST:
      case CactParser::PLUS:
      case CactParser::MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(256);
        intConst();
        break;
      }

      case CactParser::FloatConst: {
        enterOuterAlt(_localctx, 2);
        setState(257);
        match(CactParser::FloatConst);
        break;
      }

      case CactParser::EXPONENT: {
        enterOuterAlt(_localctx, 3);
        setState(258);
        match(CactParser::EXPONENT);
        break;
      }

      case CactParser::CharConst: {
        enterOuterAlt(_localctx, 4);
        setState(259);
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
  enterRule(_localctx, 40, CactParser::RuleFuncRParams);
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
    setState(262);
    exp();
    setState(267);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::COMMA) {
      setState(263);
      match(CactParser::COMMA);
      setState(264);
      exp();
      setState(269);
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

std::vector<CactParser::ExpContext *> CactParser::PrimaryExpContext::exp() {
  return getRuleContexts<CactParser::ExpContext>();
}

CactParser::ExpContext* CactParser::PrimaryExpContext::exp(size_t i) {
  return getRuleContext<CactParser::ExpContext>(i);
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
  enterRule(_localctx, 42, CactParser::RulePrimaryExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(286);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::L_PAREN: {
        enterOuterAlt(_localctx, 1);
        setState(270);
        match(CactParser::L_PAREN);
        setState(271);
        exp();
        setState(272);
        match(CactParser::R_PAREN);
        break;
      }

      case CactParser::IDENT: {
        enterOuterAlt(_localctx, 2);
        setState(274);
        match(CactParser::IDENT);
        setState(281);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CactParser::L_BRACKET) {
          setState(275);
          match(CactParser::L_BRACKET);
          setState(276);
          exp();
          setState(277);
          match(CactParser::R_BRACKET);
          setState(283);
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
      case CactParser::CharConst:
      case CactParser::PLUS:
      case CactParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(284);
        number();
        break;
      }

      case CactParser::FALSE:
      case CactParser::TRUE: {
        enterOuterAlt(_localctx, 4);
        setState(285);
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
  enterRule(_localctx, 44, CactParser::RuleUnaryExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(298);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(288);
      primaryExp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(289);
      unaryOp();
      setState(290);
      unaryExp();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(292);
      match(CactParser::IDENT);
      setState(293);
      match(CactParser::L_PAREN);
      setState(295);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 549881626624) != 0)) {
        setState(294);
        funcRParams();
      }
      setState(297);
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
  enterRule(_localctx, 46, CactParser::RuleUnaryOp);
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
    setState(300);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 117440512) != 0))) {
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
  enterRule(_localctx, 48, CactParser::RuleMulExp);
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
    setState(302);
    unaryExp();
    setState(308);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 939524096) != 0)) {
      setState(303);
      mulOp();
      setState(304);
      unaryExp();
      setState(310);
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
  enterRule(_localctx, 50, CactParser::RuleMulOp);
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
    setState(311);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 939524096) != 0))) {
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
  enterRule(_localctx, 52, CactParser::RuleAddExp);
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
    setState(313);
    mulExp();
    setState(319);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::PLUS

    || _la == CactParser::MINUS) {
      setState(314);
      addOp();
      setState(315);
      mulExp();
      setState(321);
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
  enterRule(_localctx, 54, CactParser::RuleAddOp);
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
    setState(322);
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
  enterRule(_localctx, 56, CactParser::RuleRelExp);
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
    setState(324);
    addExp();
    setState(328);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 128849018880) != 0)) {
      setState(325);
      relOp();
      setState(326);
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
  enterRule(_localctx, 58, CactParser::RuleRelOp);
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
    setState(330);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 128849018880) != 0))) {
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
  enterRule(_localctx, 60, CactParser::RuleEqExp);
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
    setState(332);
    relExp();
    setState(336);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CactParser::EQ

    || _la == CactParser::NEQ) {
      setState(333);
      eqOp();
      setState(334);
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
  enterRule(_localctx, 62, CactParser::RuleEqOp);
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
  enterRule(_localctx, 64, CactParser::RuleLAndExp);
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
    eqExp();
    setState(345);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::AND) {
      setState(341);
      match(CactParser::AND);
      setState(342);
      eqExp();
      setState(347);
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
  enterRule(_localctx, 66, CactParser::RuleLOrExp);
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
    setState(348);
    lAndExp();
    setState(353);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::OR) {
      setState(349);
      match(CactParser::OR);
      setState(350);
      lAndExp();
      setState(355);
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

tree::TerminalNode* CactParser::IntConstContext::PLUS() {
  return getToken(CactParser::PLUS, 0);
}

tree::TerminalNode* CactParser::IntConstContext::MINUS() {
  return getToken(CactParser::MINUS, 0);
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
  enterRule(_localctx, 68, CactParser::RuleIntConst);
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
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CactParser::PLUS

    || _la == CactParser::MINUS) {
      setState(356);
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
    setState(359);
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
  enterRule(_localctx, 70, CactParser::RuleBoolConst);
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
    setState(361);
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
