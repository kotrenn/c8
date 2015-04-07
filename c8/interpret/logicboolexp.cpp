#include "logicboolexp.h"

LogicBoolExp::LogicBoolExp(const string &op, BoolExp *lhs, BoolExp *rhs)
	:BoolExp(),
	 m_op(op),
	 m_lhs(lhs),
	 m_rhs(rhs)
{
}

LogicBoolExp::~LogicBoolExp()
{
	delete m_lhs;
	delete m_rhs;
}

bool LogicBoolExp::eval(VarTable *vars,
                        FuncTable *funcs,
                        bool *retstat)
{
	bool lhs = m_lhs->eval(vars, funcs, retstat);
	bool rhs = m_rhs->eval(vars, funcs, retstat);
	bool ret = false;
	if (m_op == "&&")
		ret = lhs && rhs;
	else if (m_op == "||")
		ret = lhs || rhs;
	return ret;
}
