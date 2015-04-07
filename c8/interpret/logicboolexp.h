#ifndef __LOGIC_BOOL_EXP_H
#define __LOGIC_BOOL_EXP_H

#include "boolexp.h"

class LogicBoolExp : public BoolExp
{
public:
	LogicBoolExp(const string &op, BoolExp *lhs, BoolExp *rhs);
	~LogicBoolExp();

	bool eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	string m_op;
	BoolExp *m_lhs;
	BoolExp *m_rhs;
};

#endif
