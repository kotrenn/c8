#ifndef __STATEMENT_H
#define __STATEMENT_H

#include "block.h"

class Statement : public Block
{
public:
    Statement() : Block() {}
	virtual ~Statement() {}
	
	virtual Data eval(VarTable *vars,
	                  FuncTable *funcs,
	                  bool *retstat) = 0;
};

#endif
