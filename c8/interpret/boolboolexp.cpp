#include "boolboolexp.h"

BoolBoolExp::BoolBoolExp(Exp *exp)
	:BoolExp(),
	 m_exp(exp)
{
}

BoolBoolExp::~BoolBoolExp()
{
	delete m_exp;
}

bool BoolBoolExp::eval(VarTable *vars,
                       FuncTable *funcs,
                       bool *retstat)
{
	Data val = m_exp->eval(vars, funcs, retstat);
	bool ret;
	if (val.get_type().get_type() == "int")
		ret = val.get_int();
	else
		ret = val.get_float();
	return ret;
}
