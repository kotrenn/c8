#include "blocklist.h"

BlockList::BlockList(Block *lhs, Block *rhs)
	:m_lhs(lhs),
	 m_rhs(rhs)
{
}

BlockList::~BlockList()
{
	delete m_lhs;
	delete m_rhs;
}

Data BlockList::eval(VarTable *vars,
                     FuncTable *funcs,
                     bool *retstat)
{
	Data ret;
	ret = m_lhs->eval(vars, funcs, retstat);
	if (*retstat)
		return ret;
	ret = m_rhs->eval(vars, funcs, retstat);
	return ret;
}
