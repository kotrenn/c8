#ifndef __VAR_DECL_STATEMENT_H
#define __VAR_DECL_STATEMENT_H

#include "statement.h"
#include "vardecl.h"
#include "exp.h"

class VarDeclStatement : public Statement
{
public:
	VarDeclStatement(VarDecl *var_decl);
	VarDeclStatement(VarDecl *var_decl, Exp *exp);
	~VarDeclStatement();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	VarDecl *m_var_decl;
	Exp *m_exp;
};

#endif
