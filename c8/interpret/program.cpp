#include "program.h"

Program::Program(Primary *lhs, Primary *rhs)
	:Primary(),
	 m_lhs(lhs),
	 m_rhs(rhs)
{
}

Program::~Program()
{
	delete m_lhs;
	delete m_rhs;
}

Data Program::eval(VarTable *vars,
                   FuncTable *funcs,
                   bool *retstat)
{
	Data ret;
	ret = m_lhs->eval(vars, funcs, retstat);
	ret = m_rhs->eval(vars, funcs, retstat);
	return ret;
}
