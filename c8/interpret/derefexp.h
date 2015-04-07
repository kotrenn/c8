#ifndef __DEREF_EXP_H
#define __DEREF_EXP_H

#include "exp.h"

class DerefExp : public Exp
{
public:
	DerefExp(Exp *exp);
	~DerefExp();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	Exp *m_exp;
};

#endif
