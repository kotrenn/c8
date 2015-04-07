#ifndef __IF_THEN_BLOCK_H
#define __IF_THEN_BLOCK_H

#include "block.h"
#include "boolexp.h"

class IfThenBlock : public Block
{
public:
	IfThenBlock(BoolExp *bexp, Block *then_block);
	~IfThenBlock();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	BoolExp *m_bool_exp;
	Block *m_then_block;
};

#endif
