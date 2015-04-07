#ifndef __NUMBER_EXP_H
#define __NUMBER_EXP_H

#include "exp.h"

class NumberExp : public Exp
{
public:
	NumberExp(const Data &data);
	~NumberExp();

	Data eval(VarTable *vars,
	          FuncTable *funcs,
	          bool *retstat);
private:
	Data m_data;
};

#endif
