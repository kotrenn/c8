#ifndef __VAR_EXP_H
#define __VAR_EXP_H

#include "exp.h"

class VarExp : public Exp
{
public:
	VarExp(const string &name);
	~VarExp();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	string m_name;
};

#endif
