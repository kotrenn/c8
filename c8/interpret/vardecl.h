#ifndef __VAR_DECL_H
#define __VAR_DECL_H

#include "data.h"

class VarDecl
{
public:
	VarDecl(const DataType &type, const string &name);
	~VarDecl();

	DataType get_type() const { return m_type; }
	string get_name() const { return m_name; }
private:
	DataType m_type;
	string m_name;
};

#endif
