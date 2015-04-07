#include "c8.tab.c"
#include "lex.yy.c"
#define YYERROR_VERBOSE

int yywrap()
{
	return 1;
}

int yyerror(Primary **start_primary, char *s)
{
	printf("Error: %s\n", s);
	printf("For input \"%s\"\n", yytext);
	printf("On line %d\n", line_num);
	return -1;
}

int main(int argc, char **argv)
{
	//yydebug = 1;

	// Open up source code and send it to our parser/analyzer
	FILE *inFP;
	if (argc == 2)
	{
		if ((inFP = fopen(argv[1], "r")) == NULL)
		{
			fprintf(stderr,
			        "Error: could not open %s for reading\n",
			        argv[1]);
			exit(1);
		}
		yyin = inFP;
	}
	
	// Root node for our parse tree
	Primary *start_primary = NULL;
	
	// Build up the parse tree
	int status = yyparse(&start_primary);
	if (status)
	{
		printf("Parse error\n");
		exit(1);
	}

	// Global variables and functions
	VarTable vars;
	FuncTable funcs;

	// Insert built-in language functions
	funcs.insert("print", new PrintFunc());

	// Run the expression tree
	bool retstat = false;
	start_primary->eval(&vars, &funcs, &retstat);

	// Clean up
	delete start_primary;
	
	// Exit
	return 0;
}
