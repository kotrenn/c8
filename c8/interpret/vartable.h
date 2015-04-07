#ifndef __VAR_TABLE_H
#define __VAR_TABLE_H

#include "common.h"
#include "data.h"

class VarTable
{
public:
	VarTable();
	VarTable(VarTable *parent);
	~VarTable();

	bool contains(const string &name) const;
	bool lookup(const string &name, Data &data) const;
	void insert(const string &name, const DataType &type);
	void update(const string &name, const Data &data);
private:
	VarTable *m_parent;
	map<string, Data> m_table;
};

#endif
