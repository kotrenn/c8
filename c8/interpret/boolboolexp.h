#ifndef __BOOL_BOOL_EXP_H
#define __BOOL_BOOL_EXP_H

#include "boolexp.h"
#include "exp.h"

class BoolBoolExp : public BoolExp
{
public:
	BoolBoolExp(Exp *exp);
	~BoolBoolExp();

	bool eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	Exp *m_exp;
};

#endif
