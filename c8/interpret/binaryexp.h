#ifndef __BINARY_EXP_H
#define __BINARY_EXP_H

#include "exp.h"

class BinaryExp : public Exp
{
public:
	BinaryExp(const string &op, Exp *lhs, Exp *rhs);
	~BinaryExp();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	string m_op;
	Exp *m_lhs;
	Exp *m_rhs;
};

#endif
