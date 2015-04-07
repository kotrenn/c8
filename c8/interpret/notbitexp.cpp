#include "notbitexp.h"

NotBitExp::NotBitExp(Exp *exp)
	:Exp(),
	 m_exp(exp)
{
}

NotBitExp::~NotBitExp()
{
	delete m_exp;
}

Data NotBitExp::eval(VarTable *vars,
                     FuncTable *funcs,
                     bool *retstat)
{
	Data ret = m_exp->eval(vars, funcs, retstat);
	if (ret.get_type().get_type() == "float")
	{
		printf("Error: bitwise operation on float\n");
		exit(1);
	}
	else
		ret.set_int(~ret.get_int());
	return ret;
}
