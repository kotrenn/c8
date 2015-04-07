#ifndef __BOOL_EXP_H
#define __BOOL_EXP_H

#include "vartable.h"
#include "functable.h"

class BoolExp
{
public:
	BoolExp() {}
	virtual ~BoolExp() {}
	
	virtual bool eval(VarTable *vars,
	                  FuncTable *funcs,
	                  bool *retstat) = 0;
private:
};

#endif
