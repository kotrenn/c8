#ifndef __PAR_BOOL_EXP_H
#define __PAR_BOOL_EXP_H

#include "boolexp.h"

class ParBoolExp : public BoolExp
{
public:
	ParBoolExp(BoolExp *bool_exp);
	~ParBoolExp();

	bool eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	BoolExp *m_bool_exp;
};

#endif
