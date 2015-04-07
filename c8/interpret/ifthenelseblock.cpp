#include "ifthenelseblock.h"

IfThenElseBlock::IfThenElseBlock(BoolExp *bool_exp,
                                 Block *then_block,
                                 Block *else_block)
	:Block(),
	 m_bool_exp(bool_exp),
	 m_then_block(then_block),
	 m_else_block(else_block)
{
}

IfThenElseBlock::~IfThenElseBlock()
{
	delete m_bool_exp;
	delete m_then_block;
	delete m_else_block;
}

Data IfThenElseBlock::eval(VarTable *vars,
                           FuncTable *funcs,
                           bool *retstat)
{
	bool cond = m_bool_exp->eval(vars, funcs, retstat);
	Data ret;
	VarTable new_vars(vars);
	if (cond)
		ret = m_then_block->eval(&new_vars, funcs, retstat);
	else
		ret = m_else_block->eval(&new_vars, funcs, retstat);
	return ret;
}
