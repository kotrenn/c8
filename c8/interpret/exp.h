#ifndef __EXP_H
#define __EXP_H

#include "statement.h"

class Exp : public Statement
{
public:
    Exp() : Statement() {}
	virtual ~Exp() {}

	virtual Data eval(VarTable *vars,
	                  FuncTable *funcs,
	                  bool *retstat) = 0;
};

#endif
