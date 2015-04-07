#include "binaryboolexp.h"

BinaryBoolExp::BinaryBoolExp(const string &op, Exp *lhs, Exp *rhs)
	:BoolExp(),
	 m_op(op),
	 m_lhs(lhs),
	 m_rhs(rhs)
{
}

BinaryBoolExp::~BinaryBoolExp()
{
	delete m_lhs;
	delete m_rhs;
}

bool BinaryBoolExp::eval(VarTable *vars,
                         FuncTable *funcs,
                         bool *retstat)
{
	Data lhs = m_lhs->eval(vars, funcs, retstat);
	Data rhs = m_rhs->eval(vars, funcs, retstat);
	bool ret = false;
	if (lhs.get_type().get_type() == "float" ||
	    rhs.get_type().get_type() == "float")
	{
		float lval = lhs.get_float();
		float rval = rhs.get_float();
		if (m_op == "==")
			ret = lval == rval;
		if (m_op == "!=")
			ret = lval != rval;
		if (m_op == "<=")
			ret = lval <= rval;
		if (m_op == ">=")
			ret = lval >= rval;
		if (m_op == "<")
			ret = lval < rval;
		if (m_op == ">")
			ret = lval > rval;
	}
	else
	{
		int lval = lhs.get_int();
		int rval = rhs.get_int();
		if (m_op == "==")
			ret = lval == rval;
		if (m_op == "!=")
			ret = lval != rval;
		if (m_op == "<=")
			ret = lval <= rval;
		if (m_op == ">=")
			ret = lval >= rval;
		if (m_op == "<")
			ret = lval < rval;
		if (m_op == ">")
			ret = lval > rval;
	}

	return ret;
}
