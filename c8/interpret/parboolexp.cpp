#include "parboolexp.h"

ParBoolExp::ParBoolExp(BoolExp *bool_exp)
	:BoolExp(),
	 m_bool_exp(bool_exp)
{
}

ParBoolExp::~ParBoolExp()
{
	delete m_bool_exp;
}

bool ParBoolExp::eval(VarTable *vars,
                      FuncTable *funcs,
                      bool *retstat)
{
	return m_bool_exp->eval(vars, funcs, retstat);
}
