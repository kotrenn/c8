#ifndef __BLOCK_H
#define __BLOCK_H

#include "primary.h"

class Block : public Primary
{
public:
    Block() : Primary() {}
	virtual ~Block() {}
	virtual Data eval(VarTable *vars,
	                  FuncTable *funcs,
	                  bool *retstat) = 0;
};

#endif
