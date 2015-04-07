#include "argdecl.h"

ArgDecl::ArgDecl(VarDecl *var_decl)
	:m_var_decl(var_decl)
{
}

ArgDecl::~ArgDecl()
{
	delete m_var_decl;
}

void ArgDecl::apply(VarTable *vars, vector<Data> &argv)
{
	if (is_tail() != (argv.size() == 1))
	{
		if (is_tail())
			printf("Error: too many arguments\n");
		else
			printf("Error: too few arguments\n");
		exit(1);
	}
	
	Data val = argv.back();
	argv.pop_back();
	DataType type1 = val.get_type();
	DataType type2 = m_var_decl->get_type();
	if (type1 != type2)
	{
		if (type1.get_type() == "float")
		{
			printf("Error: conversion from float to int\n");
			exit(1);
		}
		int ival = val.get_int();
		val.set_type(DataType("float"));
		val.set_float((float)ival);
	}

	string name = m_var_decl->get_name();
	vars->insert(name, val.get_type());
	vars->update(name, val);
}
