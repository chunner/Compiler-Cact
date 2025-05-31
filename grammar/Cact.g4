grammar Cact;

@header {
    #include <vector>
}

/****** parser ******/
program     : compUnit;
compUnit    : (decl | funcDef)+ EOF;
// Decl
decl        : constDecl | varDecl;
bType       : INT_KW | DOUBLE_KW | CHAR_KW | FLOAT_KW | BOOL_KW;

constDecl   : CONST_KW bType constDef (COMMA constDef)* SEMICOLON;// const int id1[1][2] = 1, id2 = 2, id3[1] = {1,2};
constDef    : IDENT (L_BRACKET intConst R_BRACKET)* ASSIGN constInitVal;
constInitVal: number
            | L_BRACE (constInitVal (COMMA constInitVal)* )? R_BRACE  // { 1,2,3 ,4 }
            | boolConst;

varDecl     : bType varDef (COMMA varDef)* SEMICOLON; // int id1[1][2] = 2, id2, id3[1] = {1,2};
varDef      : IDENT (L_BRACKET intConst R_BRACKET)* (ASSIGN constInitVal)?;

funcDef     : funcType IDENT L_PAREN (funcFParams)? R_PAREN block; // int id(int a, int b[][2][3]) {...}
funcType    : bType | VOID_KW;
funcFParams : funcFParam (COMMA funcFParam)*;
funcFParam  : bType IDENT (L_BRACKET intConst? R_BRACKET (L_BRACKET intConst R_BRACKET)*)?;
// sentence & expression
block       : L_BRACE (blockItem)* R_BRACE;
blockItem   : decl | stmt;

stmt        : lVal ASSIGN exp SEMICOLON   // id[1][2] = 1;
            | block                       // { ... }
            | IF_KW L_PAREN cond R_PAREN stmt (ELSE_KW stmt)?  // if (cond) stmt else stmt
            | WHILE_KW L_PAREN cond R_PAREN stmt // while(cond) stmt
            | BREAK_KW SEMICOLON                // break;
            | CONTINUE_KW SEMICOLON             // continue;
            | RETURN_KW exp? SEMICOLON          // return exp;
            | exp? SEMICOLON;                   //  exp;

exp         : addExp;     
cond        : lOrExp;
lVal        : IDENT (L_BRACKET exp R_BRACKET)*;
number      : intConst | FloatConst | EXPONENT | CharConst;
funcRParams : exp (COMMA exp)*;

// 8 primary level
primaryExp  : L_PAREN exp R_PAREN 
            | IDENT (L_BRACKET exp R_BRACKET)*
            | number
            | boolConst;

unaryExp    : primaryExp
            | unaryOp unaryExp
            | IDENT L_PAREN funcRParams? R_PAREN; // func(a, b, c)
unaryOp     : PLUS | MINUS | NOT;

mulExp      : unaryExp (mulOp unaryExp)*;
mulOp       : MUL | DIV | MOD;

addExp      : mulExp (addOp mulExp)*;   
addOp       : PLUS  | MINUS;

relExp      : addExp (relOp addExp)?;
relOp       : GT | LT | GE | LE;

eqExp       : relExp (eqOp relExp)?;
eqOp        : EQ | NEQ;

lAndExp     : eqExp (AND eqExp)*;

lOrExp      : lAndExp (OR lAndExp)*;


intConst    : DECIMAL_CONST | OCTAL_CONST | HEXADECIMAL_CONST;
boolConst   : TRUE | FALSE;






/************lexer***************/
// keywords
CONST_KW    : 'const';
INT_KW      : 'int';
DOUBLE_KW   : 'double';
CHAR_KW     : 'char';
FLOAT_KW    : 'float';
BOOL_KW     : 'bool';
VOID_KW     : 'void'; 
IF_KW       : 'if';
ELSE_KW     : 'else';
WHILE_KW    : 'while';
BREAK_KW    : 'break';
CONTINUE_KW : 'continue';
RETURN_KW   : 'return';
FALSE       : 'false';
TRUE        : 'true';
// identifiers
IDENT       : [a-zA-Z_][a-zA-Z_0-9]*;
// const
DECIMAL_CONST: [1-9][0-9]*;
OCTAL_CONST : '0' [0-7]*;
HEXADECIMAL_CONST: ('0x' | '0X') [0-9a-fA-F]+;
FloatConst  : [0-9]* '.' [0-9]+ [fF]? | [0-9]+ '.' [0-9]* [Ff]?;
EXPONENT    : (FloatConst|DECIMAL_CONST) [eE] [+\-]? [0-9]+ [fF]?;
CharConst   : '\'' REGULAR_CHAR '\'';

STRING      : DOUBLE_QUOTE REGULAR_CHAR*? DOUBLE_QUOTE;
fragment REGULAR_CHAR
   : (ESC | .)
   ;
fragment ESC
    : '\\n'
    | '\\t'
    | '\\\''
    | '\\"'
    | '\\\\'
    | '\\0'
    ;
PLUS        : '+';
MINUS       : '-';
NOT         : '!';
MUL         : '*';
DIV         : '/';
MOD         : '%';
ASSIGN      : '=';
EQ          : '==';
NEQ         : '!=';
GT          : '>';
LT          : '<';
GE          : '>=';
LE          : '<=';
AND        : '&&';
OR         : '||';
L_PAREN     : '(';
R_PAREN     : ')';
L_BRACE     : '{';
R_BRACE     : '}';
L_BRACKET   : '[';
R_BRACKET   : ']';
COMMA       : ',';
SEMICOLON   : ';';
DOUBLE_QUOTE: '"';



WS : [ \t\r\n]+ -> skip ; 
LineComment : '//' ~[\r\n]* -> skip;
BlockComment: '/*' .*? '*/' -> skip;