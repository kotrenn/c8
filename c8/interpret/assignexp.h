#ifndef __ASSIGN_EXP_H
#define __ASSIGN_EXP_H

#include "exp.h"

class AssignExp : public Exp
{
public:
	AssignExp(const string &name, Exp *rhs);
	~AssignExp();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	string m_name;
	Exp *m_rhs;
};

#endif
