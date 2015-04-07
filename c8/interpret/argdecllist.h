#ifndef __ARG_DECL_LIST_H
#define __ARG_DECL_LIST_H

#include "argdecl.h"

class ArgDeclList : public ArgDecl
{
public:
	ArgDeclList(ArgDecl *lhs, VarDecl *var);
	~ArgDeclList();

	void apply(VarTable *vars, vector<Data> &argv);
	bool is_tail() const { return false; }
private:
	ArgDecl *m_lhs;
};

#endif
