#ifndef __FUNC_TABLE_H
#define __FUNC_TABLE_H

#include "common.h"

class Func;

class FuncTable
{
public:
	FuncTable();
	~FuncTable();

	bool contains(const string &name) const;
	bool lookup(const string &name, Func **func) const;
	void insert(const string &name, Func *func);
private:
	map<string, Func *> m_table;
};

#endif
