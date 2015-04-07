#ifndef __PRIMARY_H
#define __PRIMARY_H

#include "data.h"
#include "vartable.h"
#include "functable.h"

class Primary
{
public:
	Primary() {}
	virtual ~Primary() {}

	virtual Data eval(VarTable *vars,
	                  FuncTable *funcs,
	                  bool *retstat) = 0;
};

#endif
