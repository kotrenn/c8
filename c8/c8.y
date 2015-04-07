%{

#define YYDEBUG 1

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>

#include "interpret/interpret.h"

int yylex(void);
int yyerror(Primary **start_primary, char *s);

int line_num = 1;

%}

%parse-param {Primary **start_primary}

%start program

%union {
    int ival;
    float fval;
    char *sval;
	Data *val_data;
	DataType *val_data_type;
	Primary *val_primary;
	Func *val_func;
	Block *val_block;
	Statement *val_statement;
	Exp *val_exp;
	BoolExp *val_bool_exp;
	ArgDecl *val_args;
	ArgVal *val_argv;
	VarDecl *val_var_decl;
}

//%option noyywrap
%error-verbose

%token SEMICOLON
%token COMMA
%token IF ELSE FI
%token FOR ROF
%token WHILE ELIHW
%token FUN NUF
%token RETURN
%token TYPE_I TYPE_F
%token <ival> CONST_I
%token <fval> CONST_F
%token <sval> VAR

%right SADD SSUB SMUL SDIV SMOD ASSIGN
%left BOOL_EQ BOOL_NEQ BOOL_GEQ BOOL_LEQ BOOL_G BOOL_L
%left OR
%left AND
%left BIT_OR
%left BIT_XOR
%left BIT_AND
%left ADD SUB
%left MUL DIV MOD
%nonassoc UMINUS UMUL UAND
%right BIT_NOT
%left LPAREN RPAREN

%type <val_primary> program
%type <val_primary> primary
%type <val_func> func
%type <val_block> blocklist
%type <val_block> block
%type <val_block> ifblock
%type <val_block> forblock
%type <val_block> whileblock
%type <val_statement> statement
%type <val_exp> exp
%type <val_bool_exp> boolexp
%type <val_data> number
%type <val_data_type> vartype
%type <val_args> args
%type <val_argv> argv
%type <val_var_decl> vardecl
%type <ival> pointers

%%

program
    : program primary
    {
	    $$ = new Program($1, $2);
	    *start_primary = $$;
    }
    | primary { $$ = $1; *start_primary = $$; }
    ;

primary
    : func { $$ = $1; }
    | block { $$ = $1; }
    ;

func
    : FUN vardecl LPAREN args RPAREN blocklist NUF
    { $$ = new Func($2, $4, $6); }
    ;

blocklist
    : blocklist block { $$ = new BlockList($1, $2); }
    | block { $$ = $1; }
    ;

block
    : statement { $$ = $1; }
    | ifblock { $$ = $1; }
    | forblock { $$ = $1; }
    | whileblock { $$ = $1; }
    ;

statement
    : exp SEMICOLON { $$ = $1; }
    | vardecl ASSIGN exp SEMICOLON { $$ = new VarDeclStatement($1, $3); }
    | vardecl SEMICOLON { $$ = new VarDeclStatement($1); }
    | RETURN exp SEMICOLON { $$ = new ReturnStatement($2); }
    ;

exp
    : SUB exp %prec UMINUS { $$ = new MinusExp($2); }
    | MUL exp %prec UMUL { $$ = new DerefExp($2); }
    | BIT_AND exp %prec UAND { $$ = new AddressExp($2); }
    | exp ADD exp { $$ = new BinaryExp("+", $1, $3); }
    | exp SUB exp { $$ = new BinaryExp("-", $1, $3); }
    | exp MUL exp { $$ = new BinaryExp("*", $1, $3); }
    | exp DIV exp { $$ = new BinaryExp("/", $1, $3); }
    | exp MOD exp { $$ = new BinaryExp("%", $1, $3); }
    | exp BIT_AND exp { $$ = new BinaryBitExp("&", $1, $3); }
    | exp BIT_OR exp { $$ = new BinaryBitExp("|", $1, $3); }
    | exp BIT_XOR exp { $$ = new BinaryBitExp("^", $1, $3); }
    | BIT_NOT exp { $$ = new NotBitExp($2); }
    | VAR SADD exp { $$ = new IncExp("+=", $1, $3); }
    | VAR SSUB exp { $$ = new IncExp("-=", $1, $3); }
    | VAR SMUL exp { $$ = new IncExp("*=", $1, $3); }
    | VAR SDIV exp { $$ = new IncExp("/=", $1, $3); }
    | VAR SMOD exp { $$ = new IncExp("%=", $1, $3); }
    | VAR LPAREN argv RPAREN { $$ = new FuncExp($1, $3); }
    | LPAREN exp RPAREN { $$ = new ParExp($2); }
//    | varref ASSIGN exp { $$ = new AssignExp($1, $3); }
    | VAR ASSIGN exp { $$ = new AssignExp($1, $3); }
    | VAR { $$ = new VarExp($1); }
    | number
    {
	    $$ = new NumberExp(*($1));
	    delete $1;
    }
    ;

/*
varref
    : MUL varref %prec UMUL { new DerefExp($2); }
    | VAR { $$ = new VarExp($1); }
    ;
*/

boolexp
    : boolexp AND boolexp { $$ = new LogicBoolExp("&&", $1, $3); }
    | boolexp OR boolexp { $$ = new LogicBoolExp("||", $1, $3); }
    | exp BOOL_EQ exp { $$ = new BinaryBoolExp("==", $1, $3); }
    | exp BOOL_NEQ exp { $$ = new BinaryBoolExp("!=", $1, $3); }
    | exp BOOL_LEQ exp { $$ = new BinaryBoolExp("<=", $1, $3); }
    | exp BOOL_GEQ exp { $$ = new BinaryBoolExp(">=", $1, $3); }
    | exp BOOL_L exp { $$ = new BinaryBoolExp("<", $1, $3); }
    | exp BOOL_G exp { $$ = new BinaryBoolExp(">", $1, $3); }
    | LPAREN boolexp RPAREN { $$ = new ParBoolExp($2); }
    | exp { $$ = new BoolBoolExp($1); }
    ;

ifblock
    : IF LPAREN boolexp RPAREN blocklist ELSE blocklist FI
    { $$ = new IfThenElseBlock($3, $5, $7); }
    | IF LPAREN boolexp RPAREN blocklist FI
    { $$ = new IfThenBlock($3, $5); }
    ;

forblock
    : FOR LPAREN exp SEMICOLON boolexp SEMICOLON exp RPAREN blocklist ROF
    { $$ = new ForBlock($3, $5, $7, $9); }
    ;

whileblock
    : WHILE LPAREN boolexp RPAREN blocklist ELIHW
    { $$ = new WhileBlock($3, $5); }
    ;

args
    : args COMMA vardecl { $$ = new ArgDeclList($1, $3); }
    | vardecl { $$ = new ArgDecl($1); }
    ;

argv
    : argv COMMA exp { $$ = new ArgValList($1, $3); }
    | exp { $$ = new ArgVal($1); }
    ;

vardecl
    : vartype VAR
    {
	    $$ = new VarDecl(*($1), $2);
	    delete $1;
    }
    ;

vartype
    : TYPE_I pointers { $$ = new DataType("int", $2); }
    | TYPE_I { $$ = new DataType("int"); }
    | TYPE_F pointers { $$ = new DataType("float", $2); }
    | TYPE_F { $$ = new DataType("float"); }
    ;

pointers
    : pointers MUL { $$ = $1 + 1; }
    | MUL { $$ = 1; }
    ;

number
    : CONST_I
    {
	    DataVal val;
	    val.ival = $1;
	    $$ = new Data(DataType("int"), val);
    }
    | CONST_F
    {
	    DataVal val;
	    val.fval = $1;
	    $$ = new Data(DataType("float"), val);
    }
    ;
