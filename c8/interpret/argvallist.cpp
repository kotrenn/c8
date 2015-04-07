#include "argvallist.h"

ArgValList::ArgValList(ArgVal *lhs, Exp *exp)
	:ArgVal(exp),
	 m_lhs(lhs)
{
}

ArgValList::~ArgValList()
{
	delete m_lhs;
}

void ArgValList::eval(VarTable *vars,
                      FuncTable *funcs,
                      bool *retstat,
                      vector<Data> &argv)
{
	m_lhs->eval(vars, funcs, retstat, argv);
	ArgVal::eval(vars, funcs, retstat, argv);
}
