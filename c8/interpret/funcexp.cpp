#include "funcexp.h"

#include "func.h"

FuncExp::FuncExp(const string &name, ArgVal *argv)
	:Exp(),
	 m_name(name),
	 m_argv(argv)
{
}

FuncExp::~FuncExp()
{
	delete m_argv;
}

Data FuncExp::eval(VarTable *vars,
                   FuncTable *funcs,
                   bool *retstat)
{
	vector<Data> vals;
	m_argv->eval(vars, funcs, retstat, vals);
	Func *func;
	if (!funcs->lookup(m_name, &func))
	{
		printf("Error: no function named %s\n", m_name.c_str());
		exit(1);
	}
	return func->eval(vars, funcs, vals);
}
