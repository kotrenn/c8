#ifndef __FOR_BLOCK_H
#define __FOR_BLOCK_H

#include "block.h"
#include "boolexp.h"
#include "exp.h"

class ForBlock : public Block
{
public:
	ForBlock(Exp *begin, BoolExp *cond, Exp *step, Block *block);
	~ForBlock();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	Exp *m_begin;
	BoolExp *m_cond;
	Exp *m_step;
	Block *m_block;
};

#endif
