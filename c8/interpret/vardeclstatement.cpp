#include "vardeclstatement.h"

VarDeclStatement::VarDeclStatement(VarDecl *var_decl)
	:Statement(),
	 m_var_decl(var_decl),
	 m_exp(NULL)
{
}

VarDeclStatement::VarDeclStatement(VarDecl *var_decl,
                                   Exp *exp)
	:Statement(),
	 m_var_decl(var_decl),
	 m_exp(exp)
{
}

VarDeclStatement::~VarDeclStatement()
{
	delete m_var_decl;
	if (m_exp == NULL)
		delete m_exp;
}

Data VarDeclStatement::eval(VarTable *vars,
                            FuncTable *funcs,
                            bool *retstat)
{
	Data val;
	if (m_exp != NULL)
		val = m_exp->eval(vars, funcs, retstat);
	string name = m_var_decl->get_name();
	DataType type = m_var_decl->get_type();

	if (type != val.get_type())
	{
		if (type.get_type() == "int")
		{
			printf("Error: converting from float to int\n");
			printf("type.get_type() = %s\n", type.get_type().c_str());
			printf("type.get_ref() = %d\n", type.get_ref());
			printf("val.get_type().get_type() = %s\n", val.get_type().get_type().c_str());
			printf("val.get_type().get_ref() = %d\n", val.get_type().get_ref());
			exit(1);
		}
		
		int ival = val.get_int();
		val.set_float((float)ival);
		val.set_type(DataType("float", 0));
	}

	vars->insert(name, val.get_type());
	vars->update(name, val);

	return val;
}
