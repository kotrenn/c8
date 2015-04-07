#ifndef __ADDRESS_EXP_H
#define __ADDRESS_EXP_H

#include "exp.h"

class AddressExp : public Exp
{
public:
	AddressExp(Exp *exp);
	~AddressExp();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	Exp *m_exp;
};

#endif
