#ifndef __FUNC_EXP_H
#define __FUNC_EXP_H

#include "exp.h"
#include "argval.h"

class FuncExp : public Exp
{
public:
	FuncExp(const string &name, ArgVal *argv);
	~FuncExp();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	string m_name;
	ArgVal *m_argv;
};

#endif
