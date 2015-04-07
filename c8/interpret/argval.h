#ifndef __ARG_VAL_H
#define __ARG_VAL_H

#include "exp.h"
#include "vartable.h"
#include "functable.h"

class ArgVal
{
public:
	ArgVal(Exp *m_exp);
	virtual ~ArgVal();
	
	virtual void eval(VarTable *vars,
	                  FuncTable *funcs,
	                  bool *retstat,
	                  vector<Data> &argv);
	virtual bool is_tail() const { return true; }
private:
	Exp *m_exp;
};

#endif
