#include "binarybitexp.h"

BinaryBitExp::BinaryBitExp(const string &op, Exp *lhs, Exp *rhs)
	:m_op(op),
	 m_lhs(lhs),
	 m_rhs(rhs)
{
}

BinaryBitExp::~BinaryBitExp()
{
	delete m_lhs;
	delete m_rhs;
}

Data BinaryBitExp::eval(VarTable *vars,
                        FuncTable *funcs,
                        bool *retstat)
{
	Data lhs = m_lhs->eval(vars, funcs, retstat);
	Data rhs = m_rhs->eval(vars, funcs, retstat);
	Data ret;
	if (lhs.get_type().get_type() == "float" ||
	    rhs.get_type().get_type() == "float")
	{
		printf("Error: bitwise operation on float\n");
		exit(1);
	}
	else // ints
	{
		int lval = lhs.get_int();
		int rval = rhs.get_int();
		int val = 0;
		if (m_op == "&")
			val = lval & rval;
		if (m_op == "|")
			val = lval | rval;
		if (m_op == "^")
			val = lval ^ rval;
		ret.set_type(DataType("int", 0));
		ret.set_int(val);
		/*
		printf("lval = %d\n", lval);
		printf("rval = %d\n", rval);
		printf("lval %s rval = %d\n", m_op.c_str(), val);
		*/
	}
	return ret;
}
