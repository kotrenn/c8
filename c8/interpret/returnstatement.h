#ifndef __RETURN_STATEMENT_H
#define __RETURN_STATEMENT_H

#include "statement.h"
#include "exp.h"

class ReturnStatement : public Statement
{
public:
	ReturnStatement(Exp *exp);
	~ReturnStatement();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	Exp *m_exp;
};

#endif
