#include "vardecl.h"

VarDecl::VarDecl(const DataType &type, const string &name)
	:m_type(type),
	 m_name(name)
{
}

VarDecl::~VarDecl()
{
}
