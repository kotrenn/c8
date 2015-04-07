#ifndef __WHILE_BLOCK_H
#define __WHILE_BLOCK_H

#include "block.h"
#include "boolexp.h"

class WhileBlock : public Block
{
public:
	WhileBlock(BoolExp *cond, Block *block);
	~WhileBlock();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	BoolExp *m_cond;
	Block *m_block;
};

#endif
