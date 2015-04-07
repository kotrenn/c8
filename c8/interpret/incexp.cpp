#include "incexp.h"

IncExp::IncExp(const string &op, const string &name, Exp *rhs)
	:Exp(),
	 m_op(op),
	 m_name(name),
	 m_rhs(rhs)
{
}

IncExp::~IncExp()
{
	delete m_rhs;
}

Data IncExp::eval(VarTable *vars,
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

	Data ret;
	if (lhs.get_type().get_type() == "int")
	{
		if (rhs.get_type().get_type() == "float")
		{
			printf("Error: assigning float to int %s\n", m_name.c_str());
			exit(1);
		}
		int lval = lhs.get_int();
		int rval = rhs.get_int();
		int val = 0;
		if (m_op == "+=")
			val = lval + rval;
		if (m_op == "-=")
			val = lval - rval;
		if (m_op == "*=")
			val = lval * rval;
		if (m_op == "/=")
		{
			if (rval == 0)
			{
				printf("Error: divide by zero\n");
				exit(1);
			}
			val = lval / rval;
		}
		if (m_op == "%=")
		{
			if (rval == 0)
			{
				printf("Error: modulo by zero\n");
				exit(1);
			}
			val = lval % rval;
		}
		ret.set_type(DataType("int", 0));
		ret.set_int(val);
	}
	else // lhs = float
	{
		float lval = lhs.get_float();
		float rval = rhs.get_float();
		float val = 0.0;
		if (m_op == "+=")
			val = lval + rval;
		if (m_op == "-=")
			val = lval - rval;
		if (m_op == "*=")
			val = lval * rval;
		if (m_op == "/=")
		{
			if (rval == 0)
			{
				printf("Error: divide by zero\n");
				exit(1);
			}
			val = lval / rval;
		}
		if (m_op == "%=")
		{
			printf("Error: cannot modulo a float\n");
			exit(1);
		}
		ret.set_type(DataType("float", 0));
		ret.set_float(val);
	}
	
	vars->update(m_name, ret);
	return ret;
}
