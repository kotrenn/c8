#include "minusexp.h"

MinusExp::MinusExp(Exp *exp)
	:Exp(),
	 m_exp(exp)
{
}

MinusExp::~MinusExp()
{
	delete m_exp;
}

Data MinusExp::eval(VarTable *vars,
                    FuncTable *funcs,
                    bool *retstat)
{
	Data ret = m_exp->eval(vars, funcs, retstat);
	if (ret.get_type().get_type() == "int")
		ret.set_int(ret.get_int() * -1);
	else
		ret.set_float(ret.get_float() * -1.0);
	return ret;
}
