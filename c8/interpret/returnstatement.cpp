#include "returnstatement.h"

ReturnStatement::ReturnStatement(Exp *exp)
	:Statement(),
	 m_exp(exp)
{
}

ReturnStatement::~ReturnStatement()
{
	delete m_exp;
}

Data ReturnStatement::eval(VarTable *vars,
                           FuncTable *funcs,
                           bool *retstat)
{
	if (retstat == NULL)
	{
		printf("Error: return statement outside of function\n");
		exit(1);
	}
	*retstat = true;
	return m_exp->eval(vars, funcs, retstat);
}
