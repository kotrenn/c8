#include "derefexp.h"

DerefExp::DerefExp(Exp *exp)
	:Exp(),
	 m_exp(exp)
{
}

DerefExp::~DerefExp()
{
	delete m_exp;
}

Data DerefExp::eval(VarTable *vars,
                    FuncTable *funcs,
                    bool *retstat)
{
	Data val = m_exp->eval(vars, funcs, retstat);

	DataType ret_type(val.get_type());
	int ref = ret_type.get_ref();
	if (ref == 0)
	{
		printf("Error: dereferencing non-pointer %s\n",
		       ret_type.get_type().c_str());
		exit(1);
	}
	ret_type.set_ref(ref - 1);
	ret_type.set_type(val.get_type().get_type());

	DataRef data_ref = val.get_data_ref();
	Data ret;
	data_ref.get_vars()->lookup(data_ref.get_name(), ret);
	ret.set_data_ref(data_ref);
	return ret;
}
