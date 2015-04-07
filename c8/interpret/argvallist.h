#ifndef __ARG_VAL_LIST_H
#define __ARG_VAL_LIST_H

#include "argval.h"

class ArgValList : public ArgVal
{
public:
	ArgValList(ArgVal *lhs, Exp *exp);
	~ArgValList();

	void eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat,
	          vector<Data> &argv);
	bool is_tail() const { return false; }
	ArgVal *get_lhs() const { return m_lhs; }
private:
	ArgVal *m_lhs;
};

#endif
