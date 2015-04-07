#include "assignexp.h"

AssignExp::AssignExp(const string &name, Exp *rhs)
	:Exp(),
	 m_name(name),
	 m_rhs(rhs)
{
}

AssignExp::~AssignExp()
{
	delete m_rhs;
}

Data AssignExp::eval(VarTable *vars,
                     FuncTable *funcs,
                     bool *retstat)
{
	Data rhs = m_rhs->eval(vars, funcs, retstat);
	Data lhs;
	if (!vars->lookup(m_name, lhs))
	{
		printf("Error: symbol %s not declared\n", m_name.c_str());
		exit(1);
	}

	if (lhs.get_type().get_type() == "int" &&
	    rhs.get_type().get_type() == "float")
	{
		printf("Error: assigning float to int %s\n", m_name.c_str());
		exit(1);
	}

	if (lhs.get_type().get_ref() > 0)
	{
	}
	else
		vars->update(m_name, rhs);
	return rhs;
}
