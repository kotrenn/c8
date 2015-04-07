#include "parexp.h"

ParExp::ParExp(Exp *exp)
	:Exp(),
	 m_exp(exp)
{
}

ParExp::~ParExp()
{
	delete m_exp;
}

Data ParExp::eval(VarTable *vars,
                  FuncTable *funcs,
                  bool *retstat)
{
	return m_exp->eval(vars, funcs, retstat);
}
