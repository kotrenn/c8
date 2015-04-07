#include "printfunc.h"

PrintFunc::PrintFunc()
	:Func(NULL, NULL, NULL)
{
}

PrintFunc::~PrintFunc()
{
}

Data PrintFunc::eval(VarTable *,
                     FuncTable *,
                     vector<Data> &argv)
{
	if (argv.size() > 1)
	{
		printf("Error: too many arguments to function print\n");
		exit(1);
	}
	if (argv.size() == 0)
	{
		printf("Error: no arguments to function print\n");
		exit(1);
	}
	
	Data val = argv[0];
	if (val.get_type().get_type() == "int")
		printf("%d\n", val.get_int());
	else
		printf("%.2f\n", val.get_float());
	
	return val;
}
