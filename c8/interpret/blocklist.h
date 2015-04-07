#ifndef __BLOCK_LIST_H
#define __BLOCK_LIST_H

#include "block.h"

class BlockList : public Block
{
public:
	BlockList(Block *lhs, Block *rhs);
	~BlockList();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	Block *m_lhs;
	Block *m_rhs;
};

#endif
