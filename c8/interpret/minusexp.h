#ifndef __MINUS_EXP_H
#define __MINUS_EXP_H

#include "exp.h"

class MinusExp : public Exp
{
public:
	MinusExp(Exp *exp);
	~MinusExp();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	Exp *m_exp;
};

#endif
