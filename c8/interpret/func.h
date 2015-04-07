#ifndef __FUNC_H
#define __FUNC_H

#include "primary.h"
#include "argdecl.h"
#include "block.h"

class Func : public Primary
{
public:
	Func(VarDecl *var_decl, ArgDecl *args, Block *block);
	virtual ~Func();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
	virtual Data eval(VarTable *vars,
	                  FuncTable *funcs,
	                  vector<Data> &argv);
private:
	VarDecl *m_var_decl;
	ArgDecl *m_args;
	Block *m_block;
};

#endif
