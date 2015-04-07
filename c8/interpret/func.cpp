#include "func.h"

Func::Func(VarDecl *var_decl, ArgDecl *args, Block *block)
	:Primary(),
	 m_var_decl(var_decl),
	 m_args(args),
	 m_block(block)
{
}

Func::~Func()
{
	if (m_var_decl != NULL)
		delete m_var_decl;
	if (m_args != NULL)
		delete m_args;
	if (m_block != NULL)
		delete m_block;
}

Data Func::eval(VarTable *,
                FuncTable *funcs,
                bool *)
{
	string name = m_var_decl->get_name();
	funcs->insert(name, this);
	return Data();
}

Data Func::eval(VarTable *vars,
                FuncTable *funcs,
                vector<Data> &argv)
{
	VarTable new_vars(vars);
	m_args->apply(&new_vars, argv);
	bool retstat = false;
	Data ret = m_block->eval(&new_vars, funcs, &retstat);

	DataType type = m_var_decl->get_type();
	if (type != ret.get_type())
	{
		if (type.get_type() == "int")
		{
			printf("Error: function conversion from float to int\n");
			exit(1);
		}
		
		int ival = ret.get_int();
		ret.set_float((float)ival);
		ret.set_type(DataType("float", 0));
	}
	
	return ret;
}
