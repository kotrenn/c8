#ifndef __PAR_EXP_H
#define __PAR_EXP_H

#include "exp.h"

class ParExp : public Exp
{
public:
	ParExp(Exp *m_exp);
	~ParExp();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	Exp *m_exp;
};

#endif
