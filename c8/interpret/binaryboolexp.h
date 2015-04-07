#ifndef __BINARY_BOOL_EXP_H
#define __BINARY_BOOL_EXP_H

#include "boolexp.h"
#include "exp.h"

class BinaryBoolExp : public BoolExp
{
public:
	BinaryBoolExp(const string &op, Exp *lhs, Exp *rhs);
	~BinaryBoolExp();

	bool eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	string m_op;
	Exp *m_lhs;
	Exp *m_rhs;
};

#endif
