#include "varexp.h"

VarExp::VarExp(const string &name)
	:Exp(),
	 m_name(name)
{
}

VarExp::~VarExp()
{
}

Data VarExp::eval(VarTable *vars,
                  FuncTable *,
                  bool *)
{
	Data ret;
	if (!vars->lookup(m_name, ret))
	{
		printf("Error: symbol %s not declared\n", m_name.c_str());
		exit(1);
	}
	DataRef data_ref(vars, m_name);
	ret.set_data_ref(data_ref);
	return ret;
}
