#include "addressexp.h"

AddressExp::AddressExp(Exp *exp)
	:Exp(),
	 m_exp(exp)
{
}

AddressExp::~AddressExp()
{
	delete m_exp;
}

Data AddressExp::eval(VarTable *vars,
                      FuncTable *funcs,
                      bool *retstat)
{
	Data val = m_exp->eval(vars, funcs, retstat);
	DataRef data_ref = val.get_data_ref();
	if (data_ref.get_vars() == NULL)
	{
		printf("Error: taking address of non-variable expression\n");
		exit(1);
	}
	
	DataType ret_type(val.get_type());
	int ref = ret_type.get_ref();
	ret_type.set_ref(ref + 1);
	int ret_val = (int)(&val);
	
	Data ret;
	ret.set_type(ret_type);
	ret.set_int(ret_val);
	return ret;
}
