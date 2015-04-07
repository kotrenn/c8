#include "ifthenblock.h"

IfThenBlock::IfThenBlock(BoolExp *bool_exp, Block *then_block)
	:Block(),
	 m_bool_exp(bool_exp),
	 m_then_block(then_block)
{
}

IfThenBlock::~IfThenBlock()
{
	delete m_bool_exp;
	delete m_then_block;
}

Data IfThenBlock::eval(VarTable *vars,
                       FuncTable *funcs,
                       bool *retstat)
{
	bool cond = m_bool_exp->eval(vars, funcs, retstat);
	Data ret;
	if (cond)
	{
		VarTable new_vars(vars);
		ret = m_then_block->eval(&new_vars, funcs, retstat);
	}
	return ret;
}
