#include "whileblock.h"

WhileBlock::WhileBlock(BoolExp *cond, Block *block)
	:Block(),
	 m_cond(cond),
	 m_block(block)
{
}

WhileBlock::~WhileBlock()
{
	delete m_cond;
	delete m_block;
}

Data WhileBlock::eval(VarTable *vars,
                      FuncTable *funcs,
                      bool *retstat)
{
	Data ret;
	while (m_cond->eval(vars, funcs, retstat) && !(*retstat))
	{
		VarTable new_vars(vars);
		ret = m_block->eval(&new_vars, funcs, retstat);
	}
	return ret;
}
