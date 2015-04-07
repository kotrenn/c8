#ifndef __ARG_DECL_H
#define __ARG_DECL_H

#include "common.h"
#include "vardecl.h"
#include "vartable.h"
#include "argval.h"

class ArgDecl
{
public:
	ArgDecl(VarDecl *var);
	virtual ~ArgDecl();

	virtual void apply(VarTable *vars, vector<Data> &argv);
	virtual bool is_tail() const { return true; }
private:
	VarDecl *m_var_decl;
};

#endif
