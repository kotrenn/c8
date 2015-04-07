#ifndef __PROGRAM_H
#define __PROGRAM_H

#include "primary.h"

class Program : public Primary
{
public:
	Program(Primary *lhs, Primary *rhs);
	~Program();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	Primary *m_lhs;
	Primary *m_rhs;
};

#endif
