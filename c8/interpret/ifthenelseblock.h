#ifndef __IF_THEN_ELSE_BLOCK_H
#define __IF_THEN_ELSE_BLOCK_H

#include "block.h"
#include "boolexp.h"

class IfThenElseBlock : public Block
{
public:
	IfThenElseBlock(BoolExp *bool_exp,
	                Block *then_block,
	                Block *else_block);
	~IfThenElseBlock();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	BoolExp *m_bool_exp;
	Block *m_then_block;
	Block *m_else_block;
};

#endif
