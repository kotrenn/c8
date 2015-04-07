#ifndef __NOT_BIT_EXP_H
#define __NOT_BIT_EXP_H

#include "exp.h"

class NotBitExp : public Exp
{
public:
	NotBitExp(Exp *m_exp);
	~NotBitExp();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	Exp *m_exp;
};

#endif
