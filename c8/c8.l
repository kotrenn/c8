%{
//#include "c8.tab.h"
%}

%%

[ \t]+ ;
\n { line_num++; }
; { return SEMICOLON; }
, { return COMMA; }
if { return IF; }
else { return ELSE; }
fi { return FI; }
while { return WHILE; }
elihw { return ELIHW; }
for { return FOR; }
rof { return ROF; }
fun { return FUN; }
nuf { return NUF; }
return { return RETURN; }
int { return TYPE_I; }
float { return TYPE_F; }
\== { return BOOL_EQ; }
\!= { return BOOL_NEQ; }
\<= { return BOOL_LEQ; }
\>= { return BOOL_GEQ; }
\< { return BOOL_L; }
\> { return BOOL_G; }
\|\| { return OR; }
&& { return AND; }
\= { return ASSIGN; }
\+= { return SADD; }
\-= { return SSUB; }
\*= { return SMUL; }
\/= { return SDIV; }
\%= { return SMOD; }
\+ { return ADD; }
\- { return SUB; }
\* { return MUL; }
\/ { return DIV; }
\% { return MOD; }
\( { return LPAREN; }
\) { return RPAREN; }
\& { return BIT_AND; }
\| { return BIT_OR; }
\^ { return BIT_XOR; }
\~ { return BIT_NOT; }
-?[0-9]+\.[0-9]+ { yylval.fval = atof(yytext); return CONST_F; }
-?[0-9]+ { yylval.ival = atoi(yytext); return CONST_I; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.sval = strdup(yytext); return VAR; }
.

%%