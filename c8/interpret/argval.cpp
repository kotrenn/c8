#include "argval.h"

ArgVal::ArgVal(Exp *exp)
	:m_exp(exp)
{
}

ArgVal::~ArgVal()
{
	delete m_exp;
}

void ArgVal::eval(VarTable *vars,
                  FuncTable *funcs,
                  bool *retstat,
                  vector<Data> &argv)
{
	argv.push_back(m_exp->eval(vars, funcs, retstat));
}
