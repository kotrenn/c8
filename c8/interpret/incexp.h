#ifndef __INC_EXP_H
#define __INC_EXP_H

#include "exp.h"

class IncExp : public Exp
{
public:
	IncExp(const string &op, const string &name, Exp *rhs);
	~IncExp();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	string m_op;
	string m_name;
	Exp *m_rhs;
};

#endif
