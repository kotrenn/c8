#ifndef __PRINT_FUNC_H
#define __PRINT_FUNC_H

#include "func.h"

class PrintFunc : public Func
{
public:
	PrintFunc();
	~PrintFunc();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          vector<Data> &argv);
private:
};

#endif
