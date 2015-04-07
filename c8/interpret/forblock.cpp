#include "forblock.h"

ForBlock::ForBlock(Exp *begin,
                   BoolExp *cond,
                   Exp *step,
                   Block *block)
	:Block(),
	 m_begin(begin),
	 m_cond(cond),
	 m_step(step),
	 m_block(block)
{
}

ForBlock::~ForBlock()
{
	delete m_begin;
	delete m_cond;
	delete m_step;
	delete m_block;
}

Data ForBlock::eval(VarTable *vars,
                    FuncTable *funcs,
                    bool *retstat)
{
	Data ret;
	for (m_begin->eval(vars, funcs, retstat);
	     m_cond->eval(vars, funcs, retstat) && !(*retstat);
	     m_step->eval(vars, funcs, retstat))
	{
		VarTable new_vars(vars);
		ret = m_block->eval(&new_vars, funcs, retstat);
	}
	return ret;
}
