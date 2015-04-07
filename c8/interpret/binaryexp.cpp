#include "binaryexp.h"

BinaryExp::BinaryExp(const string &op, Exp *lhs, Exp *rhs)
	:m_op(op),
	 m_lhs(lhs),
	 m_rhs(rhs)
{
}

BinaryExp::~BinaryExp()
{
	delete m_lhs;
	delete m_rhs;
}

Data BinaryExp::eval(VarTable *vars,
                     FuncTable *funcs,
                     bool *retstat)
{
	//printf("BinaryExp::eval(\"%s\")\n", m_op.c_str());
	Data lhs = m_lhs->eval(vars, funcs, retstat);
	Data rhs = m_rhs->eval(vars, funcs, retstat);
	Data ret;
	if (lhs.get_type().get_type() == "float" ||
	    rhs.get_type().get_type() == "float")
	{
		float lval = lhs.get_float();
		float rval = rhs.get_float();
		float val = 0.0;
		if (m_op == "+")
			val = lval + rval;
		if (m_op == "-")
			val = lval - rval;
		if (m_op == "*")
			val = lval * rval;
		if (m_op == "/")
		{
			if (rval == 0)
			{
				printf("Error: divide by zero\n");
				exit(1);
			}
			val = lval / rval;
		}
		if (m_op == "%")
		{
			printf("Error: cannod modulo a float\n");
			exit(1);
		}
		ret.set_type(DataType("float", 0));
		ret.set_float(val);
	}
	else // ints
	{
		int lval = lhs.get_int();
		int rval = rhs.get_int();
		int val = 0;
		if (m_op == "+")
			val = lval + rval;
		if (m_op == "-")
			val = lval - rval;
		if (m_op == "*")
			val = lval * rval;
		if (m_op == "/")
		{
			if (rval == 0)
			{
				printf("Error: divide by zero\n");
				exit(1);
			}
			val = lval / rval;
		}
		if (m_op == "%")
		{
			if (rval == 0)
			{
				printf("Error: modulo by zero\n");
				printf("%d %% %d\n", lval, rval);
				exit(1);
			}
			val = lval % rval;
		}
		ret.set_type(DataType("int", 0));
		ret.set_int(val);
	}
	return ret;
}
