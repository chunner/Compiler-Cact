
    #include <vector>


// Generated from Cact.g4 by ANTLR 4.13.1


#include "CactListener.h"
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
      "program", "compUnit", "decl", "constDecl", "bType", "constDef", "constInitVal", 
      "varDecl", "varDef", "funcDef", "funcType", "funcFParams", "funcFParam", 
      "block", "blockItem", "stmt", "exp", "constExp", "cond", "lVal", "number", 
      "funcRParams", "primaryExp", "unaryExp", "unaryOp", "mulExp", "mulOp", 
      "addExp", "addOp", "relExp", "relOp", "eqExp", "eqOp", "lAndExp", 
      "lOrExp", "intConst"
    },
    std::vector<std::string>{
      "", "'const'", "'int'", "'double'", "'char'", "'float'", "'void'", 
      "'if'", "'else'", "'while'", "'break'", "'continue'", "'return'", 
      "", "", "", "", "", "", "", "'+'", "'-'", "'!'", "'*'", "'/'", "'%'", 
      "'='", "'=='", "'!='", "'>'", "'<'", "'>='", "'<='", "'&&'", "'||'", 
      "'('", "')'", "'{'", "'}'", "'['", "']'", "','", "';'", "'\"'"
    },
    std::vector<std::string>{
      "", "CONST_KW", "INT_KW", "DOUBLE_KW", "CHAR_KW", "FLOAT_KW", "VOID_KW", 
      "IF_KW", "ELSE_KW", "WHILE_KW", "BREAK_KW", "CONTINUE_KW", "RETURN_KW", 
      "IDENT", "DECIMAL_CONST", "OCTAL_CONST", "HEXADECIMAL_CONST", "FloatConst", 
      "CharConst", "STRING", "PLUS", "MINUS", "NOT", "MUL", "DIV", "MOD", 
      "ASSIGN", "EQ", "NEQ", "GT", "LT", "GE", "LE", "AND", "OR", "L_PAREN", 
      "R_PAREN", "L_BRACE", "R_BRACE", "L_BRACKET", "R_BRACKET", "COMMA", 
      "SEMICOLON", "DOUBLE_QUOTE", "WS", "LineComment", "BlockComment"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,46,353,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,1,0,1,0,1,1,1,1,4,1,77,8,1,11,1,12,1,78,1,2,1,2,3,2,83,8,2,1,3,1,3,
  	1,3,1,3,1,3,5,3,90,8,3,10,3,12,3,93,9,3,1,3,1,3,1,4,1,4,1,5,1,5,1,5,1,
  	5,1,5,5,5,104,8,5,10,5,12,5,107,9,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,5,
  	6,117,8,6,10,6,12,6,120,9,6,3,6,122,8,6,1,6,3,6,125,8,6,1,7,1,7,1,7,1,
  	7,5,7,131,8,7,10,7,12,7,134,9,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,5,8,143,8,
  	8,10,8,12,8,146,9,8,1,8,1,8,3,8,150,8,8,1,9,1,9,1,9,1,9,3,9,156,8,9,1,
  	9,1,9,1,9,1,10,1,10,3,10,163,8,10,1,11,1,11,1,11,5,11,168,8,11,10,11,
  	12,11,171,9,11,1,12,1,12,1,12,1,12,3,12,177,8,12,1,12,1,12,1,12,1,12,
  	1,12,5,12,184,8,12,10,12,12,12,187,9,12,3,12,189,8,12,1,13,1,13,5,13,
  	193,8,13,10,13,12,13,196,9,13,1,13,1,13,1,14,1,14,3,14,202,8,14,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,217,
  	8,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,
  	231,8,15,1,15,1,15,3,15,235,8,15,1,15,3,15,238,8,15,1,16,1,16,1,17,1,
  	17,1,18,1,18,1,19,1,19,1,19,1,19,1,19,5,19,251,8,19,10,19,12,19,254,9,
  	19,1,20,1,20,1,20,3,20,259,8,20,1,21,1,21,1,21,5,21,264,8,21,10,21,12,
  	21,267,9,21,1,22,1,22,1,22,1,22,1,22,1,22,3,22,275,8,22,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,3,23,284,8,23,1,23,3,23,287,8,23,1,24,1,24,1,25,1,
  	25,1,25,1,25,5,25,295,8,25,10,25,12,25,298,9,25,1,26,1,26,1,27,1,27,1,
  	27,1,27,5,27,306,8,27,10,27,12,27,309,9,27,1,28,1,28,1,29,1,29,1,29,1,
  	29,5,29,317,8,29,10,29,12,29,320,9,29,1,30,1,30,1,31,1,31,1,31,1,31,5,
  	31,328,8,31,10,31,12,31,331,9,31,1,32,1,32,1,33,1,33,1,33,5,33,338,8,
  	33,10,33,12,33,341,9,33,1,34,1,34,1,34,5,34,346,8,34,10,34,12,34,349,
  	9,34,1,35,1,35,1,35,0,0,36,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,0,7,1,0,2,
  	5,1,0,20,22,1,0,23,25,1,0,20,21,1,0,29,32,1,0,27,28,1,0,14,16,360,0,72,
  	1,0,0,0,2,76,1,0,0,0,4,82,1,0,0,0,6,84,1,0,0,0,8,96,1,0,0,0,10,98,1,0,
  	0,0,12,124,1,0,0,0,14,126,1,0,0,0,16,137,1,0,0,0,18,151,1,0,0,0,20,162,
  	1,0,0,0,22,164,1,0,0,0,24,172,1,0,0,0,26,190,1,0,0,0,28,201,1,0,0,0,30,
  	237,1,0,0,0,32,239,1,0,0,0,34,241,1,0,0,0,36,243,1,0,0,0,38,245,1,0,0,
  	0,40,258,1,0,0,0,42,260,1,0,0,0,44,274,1,0,0,0,46,286,1,0,0,0,48,288,
  	1,0,0,0,50,290,1,0,0,0,52,299,1,0,0,0,54,301,1,0,0,0,56,310,1,0,0,0,58,
  	312,1,0,0,0,60,321,1,0,0,0,62,323,1,0,0,0,64,332,1,0,0,0,66,334,1,0,0,
  	0,68,342,1,0,0,0,70,350,1,0,0,0,72,73,3,2,1,0,73,1,1,0,0,0,74,77,3,4,
  	2,0,75,77,3,18,9,0,76,74,1,0,0,0,76,75,1,0,0,0,77,78,1,0,0,0,78,76,1,
  	0,0,0,78,79,1,0,0,0,79,3,1,0,0,0,80,83,3,6,3,0,81,83,3,14,7,0,82,80,1,
  	0,0,0,82,81,1,0,0,0,83,5,1,0,0,0,84,85,5,1,0,0,85,86,3,8,4,0,86,91,3,
  	10,5,0,87,88,5,41,0,0,88,90,3,10,5,0,89,87,1,0,0,0,90,93,1,0,0,0,91,89,
  	1,0,0,0,91,92,1,0,0,0,92,94,1,0,0,0,93,91,1,0,0,0,94,95,5,42,0,0,95,7,
  	1,0,0,0,96,97,7,0,0,0,97,9,1,0,0,0,98,105,5,13,0,0,99,100,5,39,0,0,100,
  	101,3,70,35,0,101,102,5,40,0,0,102,104,1,0,0,0,103,99,1,0,0,0,104,107,
  	1,0,0,0,105,103,1,0,0,0,105,106,1,0,0,0,106,108,1,0,0,0,107,105,1,0,0,
  	0,108,109,5,26,0,0,109,110,3,12,6,0,110,11,1,0,0,0,111,125,3,34,17,0,
  	112,121,5,37,0,0,113,118,3,12,6,0,114,115,5,41,0,0,115,117,3,12,6,0,116,
  	114,1,0,0,0,117,120,1,0,0,0,118,116,1,0,0,0,118,119,1,0,0,0,119,122,1,
  	0,0,0,120,118,1,0,0,0,121,113,1,0,0,0,121,122,1,0,0,0,122,123,1,0,0,0,
  	123,125,5,38,0,0,124,111,1,0,0,0,124,112,1,0,0,0,125,13,1,0,0,0,126,127,
  	3,8,4,0,127,132,3,16,8,0,128,129,5,41,0,0,129,131,3,16,8,0,130,128,1,
  	0,0,0,131,134,1,0,0,0,132,130,1,0,0,0,132,133,1,0,0,0,133,135,1,0,0,0,
  	134,132,1,0,0,0,135,136,5,42,0,0,136,15,1,0,0,0,137,144,5,13,0,0,138,
  	139,5,39,0,0,139,140,3,70,35,0,140,141,5,40,0,0,141,143,1,0,0,0,142,138,
  	1,0,0,0,143,146,1,0,0,0,144,142,1,0,0,0,144,145,1,0,0,0,145,149,1,0,0,
  	0,146,144,1,0,0,0,147,148,5,26,0,0,148,150,3,12,6,0,149,147,1,0,0,0,149,
  	150,1,0,0,0,150,17,1,0,0,0,151,152,3,20,10,0,152,153,5,13,0,0,153,155,
  	5,35,0,0,154,156,3,22,11,0,155,154,1,0,0,0,155,156,1,0,0,0,156,157,1,
  	0,0,0,157,158,5,36,0,0,158,159,3,26,13,0,159,19,1,0,0,0,160,163,3,8,4,
  	0,161,163,5,6,0,0,162,160,1,0,0,0,162,161,1,0,0,0,163,21,1,0,0,0,164,
  	169,3,24,12,0,165,166,5,41,0,0,166,168,3,24,12,0,167,165,1,0,0,0,168,
  	171,1,0,0,0,169,167,1,0,0,0,169,170,1,0,0,0,170,23,1,0,0,0,171,169,1,
  	0,0,0,172,173,3,8,4,0,173,188,5,13,0,0,174,176,5,39,0,0,175,177,3,70,
  	35,0,176,175,1,0,0,0,176,177,1,0,0,0,177,178,1,0,0,0,178,185,5,40,0,0,
  	179,180,5,39,0,0,180,181,3,70,35,0,181,182,5,40,0,0,182,184,1,0,0,0,183,
  	179,1,0,0,0,184,187,1,0,0,0,185,183,1,0,0,0,185,186,1,0,0,0,186,189,1,
  	0,0,0,187,185,1,0,0,0,188,174,1,0,0,0,188,189,1,0,0,0,189,25,1,0,0,0,
  	190,194,5,37,0,0,191,193,3,28,14,0,192,191,1,0,0,0,193,196,1,0,0,0,194,
  	192,1,0,0,0,194,195,1,0,0,0,195,197,1,0,0,0,196,194,1,0,0,0,197,198,5,
  	38,0,0,198,27,1,0,0,0,199,202,3,4,2,0,200,202,3,30,15,0,201,199,1,0,0,
  	0,201,200,1,0,0,0,202,29,1,0,0,0,203,204,3,38,19,0,204,205,5,26,0,0,205,
  	206,3,32,16,0,206,207,5,42,0,0,207,238,1,0,0,0,208,238,3,26,13,0,209,
  	210,5,7,0,0,210,211,5,35,0,0,211,212,3,36,18,0,212,213,5,36,0,0,213,216,
  	3,30,15,0,214,215,5,8,0,0,215,217,3,30,15,0,216,214,1,0,0,0,216,217,1,
  	0,0,0,217,238,1,0,0,0,218,219,5,9,0,0,219,220,5,35,0,0,220,221,3,36,18,
  	0,221,222,5,36,0,0,222,223,3,30,15,0,223,238,1,0,0,0,224,225,5,10,0,0,
  	225,238,5,42,0,0,226,227,5,11,0,0,227,238,5,42,0,0,228,230,5,12,0,0,229,
  	231,3,32,16,0,230,229,1,0,0,0,230,231,1,0,0,0,231,232,1,0,0,0,232,238,
  	5,42,0,0,233,235,3,32,16,0,234,233,1,0,0,0,234,235,1,0,0,0,235,236,1,
  	0,0,0,236,238,5,42,0,0,237,203,1,0,0,0,237,208,1,0,0,0,237,209,1,0,0,
  	0,237,218,1,0,0,0,237,224,1,0,0,0,237,226,1,0,0,0,237,228,1,0,0,0,237,
  	234,1,0,0,0,238,31,1,0,0,0,239,240,3,54,27,0,240,33,1,0,0,0,241,242,3,
  	54,27,0,242,35,1,0,0,0,243,244,3,68,34,0,244,37,1,0,0,0,245,252,5,13,
  	0,0,246,247,5,39,0,0,247,248,3,32,16,0,248,249,5,40,0,0,249,251,1,0,0,
  	0,250,246,1,0,0,0,251,254,1,0,0,0,252,250,1,0,0,0,252,253,1,0,0,0,253,
  	39,1,0,0,0,254,252,1,0,0,0,255,259,3,70,35,0,256,259,5,17,0,0,257,259,
  	5,18,0,0,258,255,1,0,0,0,258,256,1,0,0,0,258,257,1,0,0,0,259,41,1,0,0,
  	0,260,265,3,32,16,0,261,262,5,41,0,0,262,264,3,32,16,0,263,261,1,0,0,
  	0,264,267,1,0,0,0,265,263,1,0,0,0,265,266,1,0,0,0,266,43,1,0,0,0,267,
  	265,1,0,0,0,268,269,5,35,0,0,269,270,3,32,16,0,270,271,5,36,0,0,271,275,
  	1,0,0,0,272,275,3,38,19,0,273,275,3,40,20,0,274,268,1,0,0,0,274,272,1,
  	0,0,0,274,273,1,0,0,0,275,45,1,0,0,0,276,287,3,44,22,0,277,278,3,48,24,
  	0,278,279,3,46,23,0,279,287,1,0,0,0,280,281,5,13,0,0,281,283,5,35,0,0,
  	282,284,3,42,21,0,283,282,1,0,0,0,283,284,1,0,0,0,284,285,1,0,0,0,285,
  	287,5,36,0,0,286,276,1,0,0,0,286,277,1,0,0,0,286,280,1,0,0,0,287,47,1,
  	0,0,0,288,289,7,1,0,0,289,49,1,0,0,0,290,296,3,46,23,0,291,292,3,52,26,
  	0,292,293,3,46,23,0,293,295,1,0,0,0,294,291,1,0,0,0,295,298,1,0,0,0,296,
  	294,1,0,0,0,296,297,1,0,0,0,297,51,1,0,0,0,298,296,1,0,0,0,299,300,7,
  	2,0,0,300,53,1,0,0,0,301,307,3,50,25,0,302,303,3,56,28,0,303,304,3,50,
  	25,0,304,306,1,0,0,0,305,302,1,0,0,0,306,309,1,0,0,0,307,305,1,0,0,0,
  	307,308,1,0,0,0,308,55,1,0,0,0,309,307,1,0,0,0,310,311,7,3,0,0,311,57,
  	1,0,0,0,312,318,3,54,27,0,313,314,3,60,30,0,314,315,3,54,27,0,315,317,
  	1,0,0,0,316,313,1,0,0,0,317,320,1,0,0,0,318,316,1,0,0,0,318,319,1,0,0,
  	0,319,59,1,0,0,0,320,318,1,0,0,0,321,322,7,4,0,0,322,61,1,0,0,0,323,329,
  	3,58,29,0,324,325,3,64,32,0,325,326,3,58,29,0,326,328,1,0,0,0,327,324,
  	1,0,0,0,328,331,1,0,0,0,329,327,1,0,0,0,329,330,1,0,0,0,330,63,1,0,0,
  	0,331,329,1,0,0,0,332,333,7,5,0,0,333,65,1,0,0,0,334,339,3,62,31,0,335,
  	336,5,33,0,0,336,338,3,62,31,0,337,335,1,0,0,0,338,341,1,0,0,0,339,337,
  	1,0,0,0,339,340,1,0,0,0,340,67,1,0,0,0,341,339,1,0,0,0,342,347,3,66,33,
  	0,343,344,5,34,0,0,344,346,3,66,33,0,345,343,1,0,0,0,346,349,1,0,0,0,
  	347,345,1,0,0,0,347,348,1,0,0,0,348,69,1,0,0,0,349,347,1,0,0,0,350,351,
  	7,6,0,0,351,71,1,0,0,0,35,76,78,82,91,105,118,121,124,132,144,149,155,
  	162,169,176,185,188,194,201,216,230,234,237,252,258,265,274,283,286,296,
  	307,318,329,339,347
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

void CactParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void CactParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
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

void CactParser::CompUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompUnit(this);
}

void CactParser::CompUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompUnit(this);
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
      ((1ULL << _la) & 126) != 0));
   
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

void CactParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void CactParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
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
    setState(82);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::CONST_KW: {
        enterOuterAlt(_localctx, 1);
        setState(80);
        constDecl();
        break;
      }

      case CactParser::INT_KW:
      case CactParser::DOUBLE_KW:
      case CactParser::CHAR_KW:
      case CactParser::FLOAT_KW: {
        enterOuterAlt(_localctx, 2);
        setState(81);
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

void CactParser::ConstDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDecl(this);
}

void CactParser::ConstDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDecl(this);
}


std::any CactParser::ConstDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitConstDecl(this);
  else
    return visitor->visitChildren(this);
}

CactParser::ConstDeclContext* CactParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, CactParser::RuleConstDecl);
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
    setState(84);
    match(CactParser::CONST_KW);
    setState(85);
    bType();
    setState(86);
    constDef();
    setState(91);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::COMMA) {
      setState(87);
      match(CactParser::COMMA);
      setState(88);
      constDef();
      setState(93);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(94);
    match(CactParser::SEMICOLON);
   
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


size_t CactParser::BTypeContext::getRuleIndex() const {
  return CactParser::RuleBType;
}

void CactParser::BTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBType(this);
}

void CactParser::BTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBType(this);
}


std::any CactParser::BTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitBType(this);
  else
    return visitor->visitChildren(this);
}

CactParser::BTypeContext* CactParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 8, CactParser::RuleBType);
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
    setState(96);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 60) != 0))) {
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

void CactParser::ConstDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDef(this);
}

void CactParser::ConstDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDef(this);
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
    setState(98);
    match(CactParser::IDENT);
    setState(105);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::L_BRACKET) {
      setState(99);
      match(CactParser::L_BRACKET);
      setState(100);
      intConst();
      setState(101);
      match(CactParser::R_BRACKET);
      setState(107);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(108);
    match(CactParser::ASSIGN);
    setState(109);
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

CactParser::ConstExpContext* CactParser::ConstInitValContext::constExp() {
  return getRuleContext<CactParser::ConstExpContext>(0);
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


size_t CactParser::ConstInitValContext::getRuleIndex() const {
  return CactParser::RuleConstInitVal;
}

void CactParser::ConstInitValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstInitVal(this);
}

void CactParser::ConstInitValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstInitVal(this);
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
    setState(124);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::IDENT:
      case CactParser::DECIMAL_CONST:
      case CactParser::OCTAL_CONST:
      case CactParser::HEXADECIMAL_CONST:
      case CactParser::FloatConst:
      case CactParser::CharConst:
      case CactParser::PLUS:
      case CactParser::MINUS:
      case CactParser::NOT:
      case CactParser::L_PAREN: {
        enterOuterAlt(_localctx, 1);
        setState(111);
        constExp();
        break;
      }

      case CactParser::L_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(112);
        match(CactParser::L_BRACE);
        setState(121);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 171806547968) != 0)) {
          setState(113);
          constInitVal();
          setState(118);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == CactParser::COMMA) {
            setState(114);
            match(CactParser::COMMA);
            setState(115);
            constInitVal();
            setState(120);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(123);
        match(CactParser::R_BRACE);
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

void CactParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void CactParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
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
    setState(126);
    bType();
    setState(127);
    varDef();
    setState(132);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::COMMA) {
      setState(128);
      match(CactParser::COMMA);
      setState(129);
      varDef();
      setState(134);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(135);
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

void CactParser::VarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDef(this);
}

void CactParser::VarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDef(this);
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
    setState(137);
    match(CactParser::IDENT);
    setState(144);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::L_BRACKET) {
      setState(138);
      match(CactParser::L_BRACKET);
      setState(139);
      intConst();
      setState(140);
      match(CactParser::R_BRACKET);
      setState(146);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(149);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CactParser::ASSIGN) {
      setState(147);
      match(CactParser::ASSIGN);
      setState(148);
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

void CactParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void CactParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
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
    setState(151);
    funcType();
    setState(152);
    match(CactParser::IDENT);
    setState(153);
    match(CactParser::L_PAREN);
    setState(155);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 60) != 0)) {
      setState(154);
      funcFParams();
    }
    setState(157);
    match(CactParser::R_PAREN);
    setState(158);
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

void CactParser::FuncTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncType(this);
}

void CactParser::FuncTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncType(this);
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
    setState(162);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::INT_KW:
      case CactParser::DOUBLE_KW:
      case CactParser::CHAR_KW:
      case CactParser::FLOAT_KW: {
        enterOuterAlt(_localctx, 1);
        setState(160);
        bType();
        break;
      }

      case CactParser::VOID_KW: {
        enterOuterAlt(_localctx, 2);
        setState(161);
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

void CactParser::FuncFParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParams(this);
}

void CactParser::FuncFParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParams(this);
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
    setState(164);
    funcFParam();
    setState(169);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::COMMA) {
      setState(165);
      match(CactParser::COMMA);
      setState(166);
      funcFParam();
      setState(171);
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

void CactParser::FuncFParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParam(this);
}

void CactParser::FuncFParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParam(this);
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
    setState(172);
    bType();
    setState(173);
    match(CactParser::IDENT);
    setState(188);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CactParser::L_BRACKET) {
      setState(174);
      match(CactParser::L_BRACKET);
      setState(176);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 114688) != 0)) {
        setState(175);
        intConst();
      }
      setState(178);
      match(CactParser::R_BRACKET);
      setState(185);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CactParser::L_BRACKET) {
        setState(179);
        match(CactParser::L_BRACKET);
        setState(180);
        intConst();
        setState(181);
        match(CactParser::R_BRACKET);
        setState(187);
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

void CactParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void CactParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
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
    setState(190);
    match(CactParser::L_BRACE);
    setState(194);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4569853066942) != 0)) {
      setState(191);
      blockItem();
      setState(196);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(197);
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

void CactParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void CactParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
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
    setState(201);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::CONST_KW:
      case CactParser::INT_KW:
      case CactParser::DOUBLE_KW:
      case CactParser::CHAR_KW:
      case CactParser::FLOAT_KW: {
        enterOuterAlt(_localctx, 1);
        setState(199);
        decl();
        break;
      }

      case CactParser::IF_KW:
      case CactParser::WHILE_KW:
      case CactParser::BREAK_KW:
      case CactParser::CONTINUE_KW:
      case CactParser::RETURN_KW:
      case CactParser::IDENT:
      case CactParser::DECIMAL_CONST:
      case CactParser::OCTAL_CONST:
      case CactParser::HEXADECIMAL_CONST:
      case CactParser::FloatConst:
      case CactParser::CharConst:
      case CactParser::PLUS:
      case CactParser::MINUS:
      case CactParser::NOT:
      case CactParser::L_PAREN:
      case CactParser::L_BRACE:
      case CactParser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);
        setState(200);
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

void CactParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void CactParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
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
    setState(237);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(203);
      lVal();
      setState(204);
      match(CactParser::ASSIGN);
      setState(205);
      exp();
      setState(206);
      match(CactParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(208);
      block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(209);
      match(CactParser::IF_KW);
      setState(210);
      match(CactParser::L_PAREN);
      setState(211);
      cond();
      setState(212);
      match(CactParser::R_PAREN);
      setState(213);
      stmt();
      setState(216);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
      case 1: {
        setState(214);
        match(CactParser::ELSE_KW);
        setState(215);
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
      setState(218);
      match(CactParser::WHILE_KW);
      setState(219);
      match(CactParser::L_PAREN);
      setState(220);
      cond();
      setState(221);
      match(CactParser::R_PAREN);
      setState(222);
      stmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(224);
      match(CactParser::BREAK_KW);
      setState(225);
      match(CactParser::SEMICOLON);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(226);
      match(CactParser::CONTINUE_KW);
      setState(227);
      match(CactParser::SEMICOLON);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(228);
      match(CactParser::RETURN_KW);
      setState(230);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 34367594496) != 0)) {
        setState(229);
        exp();
      }
      setState(232);
      match(CactParser::SEMICOLON);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(234);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 34367594496) != 0)) {
        setState(233);
        exp();
      }
      setState(236);
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

void CactParser::ExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp(this);
}

void CactParser::ExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp(this);
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
    setState(239);
    addExp();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

CactParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CactParser::AddExpContext* CactParser::ConstExpContext::addExp() {
  return getRuleContext<CactParser::AddExpContext>(0);
}


size_t CactParser::ConstExpContext::getRuleIndex() const {
  return CactParser::RuleConstExp;
}

void CactParser::ConstExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExp(this);
}

void CactParser::ConstExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExp(this);
}


std::any CactParser::ConstExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitConstExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::ConstExpContext* CactParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 34, CactParser::RuleConstExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
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

void CactParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void CactParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}


std::any CactParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

CactParser::CondContext* CactParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 36, CactParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
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

void CactParser::LValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLVal(this);
}

void CactParser::LValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLVal(this);
}


std::any CactParser::LValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitLVal(this);
  else
    return visitor->visitChildren(this);
}

CactParser::LValContext* CactParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 38, CactParser::RuleLVal);
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
    setState(245);
    match(CactParser::IDENT);
    setState(252);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::L_BRACKET) {
      setState(246);
      match(CactParser::L_BRACKET);
      setState(247);
      exp();
      setState(248);
      match(CactParser::R_BRACKET);
      setState(254);
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

tree::TerminalNode* CactParser::NumberContext::CharConst() {
  return getToken(CactParser::CharConst, 0);
}


size_t CactParser::NumberContext::getRuleIndex() const {
  return CactParser::RuleNumber;
}

void CactParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void CactParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


std::any CactParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

CactParser::NumberContext* CactParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 40, CactParser::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(258);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::DECIMAL_CONST:
      case CactParser::OCTAL_CONST:
      case CactParser::HEXADECIMAL_CONST: {
        enterOuterAlt(_localctx, 1);
        setState(255);
        intConst();
        break;
      }

      case CactParser::FloatConst: {
        enterOuterAlt(_localctx, 2);
        setState(256);
        match(CactParser::FloatConst);
        break;
      }

      case CactParser::CharConst: {
        enterOuterAlt(_localctx, 3);
        setState(257);
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

void CactParser::FuncRParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncRParams(this);
}

void CactParser::FuncRParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncRParams(this);
}


std::any CactParser::FuncRParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitFuncRParams(this);
  else
    return visitor->visitChildren(this);
}

CactParser::FuncRParamsContext* CactParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 42, CactParser::RuleFuncRParams);
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
    setState(260);
    exp();
    setState(265);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::COMMA) {
      setState(261);
      match(CactParser::COMMA);
      setState(262);
      exp();
      setState(267);
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

CactParser::ExpContext* CactParser::PrimaryExpContext::exp() {
  return getRuleContext<CactParser::ExpContext>(0);
}

tree::TerminalNode* CactParser::PrimaryExpContext::R_PAREN() {
  return getToken(CactParser::R_PAREN, 0);
}

CactParser::LValContext* CactParser::PrimaryExpContext::lVal() {
  return getRuleContext<CactParser::LValContext>(0);
}

CactParser::NumberContext* CactParser::PrimaryExpContext::number() {
  return getRuleContext<CactParser::NumberContext>(0);
}


size_t CactParser::PrimaryExpContext::getRuleIndex() const {
  return CactParser::RulePrimaryExp;
}

void CactParser::PrimaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExp(this);
}

void CactParser::PrimaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExp(this);
}


std::any CactParser::PrimaryExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitPrimaryExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::PrimaryExpContext* CactParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 44, CactParser::RulePrimaryExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(274);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CactParser::L_PAREN: {
        enterOuterAlt(_localctx, 1);
        setState(268);
        match(CactParser::L_PAREN);
        setState(269);
        exp();
        setState(270);
        match(CactParser::R_PAREN);
        break;
      }

      case CactParser::IDENT: {
        enterOuterAlt(_localctx, 2);
        setState(272);
        lVal();
        break;
      }

      case CactParser::DECIMAL_CONST:
      case CactParser::OCTAL_CONST:
      case CactParser::HEXADECIMAL_CONST:
      case CactParser::FloatConst:
      case CactParser::CharConst: {
        enterOuterAlt(_localctx, 3);
        setState(273);
        number();
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

void CactParser::UnaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExp(this);
}

void CactParser::UnaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExp(this);
}


std::any CactParser::UnaryExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitUnaryExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::UnaryExpContext* CactParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 46, CactParser::RuleUnaryExp);
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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(276);
      primaryExp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(277);
      unaryOp();
      setState(278);
      unaryExp();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(280);
      match(CactParser::IDENT);
      setState(281);
      match(CactParser::L_PAREN);
      setState(283);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 34367594496) != 0)) {
        setState(282);
        funcRParams();
      }
      setState(285);
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

void CactParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}

void CactParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}


std::any CactParser::UnaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitUnaryOp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::UnaryOpContext* CactParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 48, CactParser::RuleUnaryOp);
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
    setState(288);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7340032) != 0))) {
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

void CactParser::MulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExp(this);
}

void CactParser::MulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExp(this);
}


std::any CactParser::MulExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitMulExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::MulExpContext* CactParser::mulExp() {
  MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, getState());
  enterRule(_localctx, 50, CactParser::RuleMulExp);
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
    setState(290);
    unaryExp();
    setState(296);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 58720256) != 0)) {
      setState(291);
      mulOp();
      setState(292);
      unaryExp();
      setState(298);
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

void CactParser::MulOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulOp(this);
}

void CactParser::MulOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulOp(this);
}


std::any CactParser::MulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitMulOp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::MulOpContext* CactParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 52, CactParser::RuleMulOp);
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
    setState(299);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 58720256) != 0))) {
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

void CactParser::AddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExp(this);
}

void CactParser::AddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExp(this);
}


std::any CactParser::AddExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitAddExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::AddExpContext* CactParser::addExp() {
  AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, getState());
  enterRule(_localctx, 54, CactParser::RuleAddExp);
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
    setState(301);
    mulExp();
    setState(307);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::PLUS

    || _la == CactParser::MINUS) {
      setState(302);
      addOp();
      setState(303);
      mulExp();
      setState(309);
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

void CactParser::AddOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddOp(this);
}

void CactParser::AddOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddOp(this);
}


std::any CactParser::AddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitAddOp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::AddOpContext* CactParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 56, CactParser::RuleAddOp);
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
    setState(310);
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

std::vector<CactParser::RelOpContext *> CactParser::RelExpContext::relOp() {
  return getRuleContexts<CactParser::RelOpContext>();
}

CactParser::RelOpContext* CactParser::RelExpContext::relOp(size_t i) {
  return getRuleContext<CactParser::RelOpContext>(i);
}


size_t CactParser::RelExpContext::getRuleIndex() const {
  return CactParser::RuleRelExp;
}

void CactParser::RelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExp(this);
}

void CactParser::RelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExp(this);
}


std::any CactParser::RelExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitRelExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::RelExpContext* CactParser::relExp() {
  RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, getState());
  enterRule(_localctx, 58, CactParser::RuleRelExp);
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
    setState(312);
    addExp();
    setState(318);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8053063680) != 0)) {
      setState(313);
      relOp();
      setState(314);
      addExp();
      setState(320);
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

void CactParser::RelOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelOp(this);
}

void CactParser::RelOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelOp(this);
}


std::any CactParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::RelOpContext* CactParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 60, CactParser::RuleRelOp);
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
    setState(321);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8053063680) != 0))) {
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

std::vector<CactParser::EqOpContext *> CactParser::EqExpContext::eqOp() {
  return getRuleContexts<CactParser::EqOpContext>();
}

CactParser::EqOpContext* CactParser::EqExpContext::eqOp(size_t i) {
  return getRuleContext<CactParser::EqOpContext>(i);
}


size_t CactParser::EqExpContext::getRuleIndex() const {
  return CactParser::RuleEqExp;
}

void CactParser::EqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExp(this);
}

void CactParser::EqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExp(this);
}


std::any CactParser::EqExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitEqExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::EqExpContext* CactParser::eqExp() {
  EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, getState());
  enterRule(_localctx, 62, CactParser::RuleEqExp);
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
    setState(323);
    relExp();
    setState(329);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::EQ

    || _la == CactParser::NEQ) {
      setState(324);
      eqOp();
      setState(325);
      relExp();
      setState(331);
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

void CactParser::EqOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqOp(this);
}

void CactParser::EqOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqOp(this);
}


std::any CactParser::EqOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitEqOp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::EqOpContext* CactParser::eqOp() {
  EqOpContext *_localctx = _tracker.createInstance<EqOpContext>(_ctx, getState());
  enterRule(_localctx, 64, CactParser::RuleEqOp);
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

void CactParser::LAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLAndExp(this);
}

void CactParser::LAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLAndExp(this);
}


std::any CactParser::LAndExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitLAndExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::LAndExpContext* CactParser::lAndExp() {
  LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, getState());
  enterRule(_localctx, 66, CactParser::RuleLAndExp);
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
    setState(334);
    eqExp();
    setState(339);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::AND) {
      setState(335);
      match(CactParser::AND);
      setState(336);
      eqExp();
      setState(341);
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

void CactParser::LOrExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLOrExp(this);
}

void CactParser::LOrExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLOrExp(this);
}


std::any CactParser::LOrExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitLOrExp(this);
  else
    return visitor->visitChildren(this);
}

CactParser::LOrExpContext* CactParser::lOrExp() {
  LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, getState());
  enterRule(_localctx, 68, CactParser::RuleLOrExp);
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
    setState(342);
    lAndExp();
    setState(347);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CactParser::OR) {
      setState(343);
      match(CactParser::OR);
      setState(344);
      lAndExp();
      setState(349);
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

void CactParser::IntConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntConst(this);
}

void CactParser::IntConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CactListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntConst(this);
}


std::any CactParser::IntConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CactVisitor*>(visitor))
    return parserVisitor->visitIntConst(this);
  else
    return visitor->visitChildren(this);
}

CactParser::IntConstContext* CactParser::intConst() {
  IntConstContext *_localctx = _tracker.createInstance<IntConstContext>(_ctx, getState());
  enterRule(_localctx, 70, CactParser::RuleIntConst);
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
    setState(350);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 114688) != 0))) {
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
