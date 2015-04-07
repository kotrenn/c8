#include "functable.h"
#include "func.h"

FuncTable::FuncTable()
	:m_table()
{
}

FuncTable::~FuncTable()
{
	/*
	map<string, Func *>::iterator it;
	for (it = m_table.begin(); it != m_table.end(); it++)
		delete it->second;
	*/
}

bool FuncTable::contains(const string &name) const
{
	if (m_table.find(name) == m_table.end())
		return false;
	return true;
}

bool FuncTable::lookup(const string &name, Func **func) const
{
	if (m_table.find(name) == m_table.end())
		return false;
	*func = m_table.find(name)->second;
	return true;
}

void FuncTable::insert(const string &name, Func *func)
{
	m_table[name] = func;
}

