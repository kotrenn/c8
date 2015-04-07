#include "vartable.h"

VarTable::VarTable()
	:m_parent(NULL),
	 m_table()
{
}

VarTable::VarTable(VarTable *parent)
	:m_parent(parent),
	 m_table()
{
}

VarTable::~VarTable()
{
}

bool VarTable::contains(const string &name) const
{
	if (m_table.find(name) == m_table.end())
	{
		if (m_parent == NULL)
			return false;
		else
			return m_parent->contains(name);
	}
	else
		return true;
}

bool VarTable::lookup(const string &name, Data &data) const
{
	if (m_table.find(name) == m_table.end())
	{
		if (m_parent == NULL)
			return false;
		else
			return m_parent->lookup(name, data);
	}
	data = m_table.find(name)->second;
	return true;
}

void VarTable::insert(const string &name, const DataType &type)
{
	DataVal val;
	val.ival = 0;
	Data data(type, val);
	m_table[name] = data;
}

void VarTable::update(const string &name, const Data &data)
{
	if (m_table.find(name) == m_table.end())
	{
		if (m_parent == NULL)
		{
			printf("VarTable error: ");
			printf("Updating value of non-existent symbol %s\n",
			       name.c_str());
			exit(1);
		}
		else
			m_parent->update(name, data);
	}
	else
		m_table[name] = data;
}
