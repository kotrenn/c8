#include "argdecllist.h"
#include "argvallist.h"

ArgDeclList::ArgDeclList(ArgDecl *lhs, VarDecl *var)
	:ArgDecl(var),
	 m_lhs(lhs)
{
}

ArgDeclList::~ArgDeclList()
{
	delete m_lhs;
}

void ArgDeclList::apply(VarTable *vars, vector<Data> &argv)
{
	ArgDecl::apply(vars, argv);
	m_lhs->apply(vars, argv);
}
