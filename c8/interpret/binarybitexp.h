#ifndef __BINARY_BIT_EXP_H
#define __BINARY_BIT_EXP_H

#include "exp.h"

class BinaryBitExp : public Exp
{
public:
	BinaryBitExp(const string &op, Exp *lhs, Exp *rhs);
	~BinaryBitExp();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	string m_op;
	Exp *m_lhs;
	Exp *m_rhs;
};

#endif
