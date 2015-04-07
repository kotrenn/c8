#include "numberexp.h"

NumberExp::NumberExp(const Data &data)
	:Exp(),
	 m_data(data)
{
}

NumberExp::~NumberExp()
{
}

Data NumberExp::eval(VarTable *,
                     FuncTable *,
                     bool *)
{
	return m_data;
}
