#ifndef __DATA_H
#define __DATA_H

#include "common.h"

class VarTable;

class DataType
{
public:
	DataType();
	DataType(const string &type);
	DataType(const string &type, int ref);

	void set_type(const string &type) { m_type = type; }
	void set_ref(int ref) { m_ref = ref; }
	string get_type() const { return m_type; }
	int get_ref() const { return m_ref; }

	bool operator==(const DataType &rhs) const;
	bool operator!=(const DataType &rhs) const;
private:
	string m_type;
	int m_ref;
};

//typedef string DataType;

class DataRef
{
public:
	DataRef();
	DataRef(VarTable *vars, const string &name);

	VarTable *get_vars() const { return m_vars; }
	string get_name() const { return m_name; }
private:
	VarTable *m_vars;
	string m_name;
};

typedef union
{
	int ival;
	float fval;
} DataVal;

class Data
{
public:
	Data();
	Data(const DataType &type, const DataVal &val);
	
	void set_type(const DataType &type) { m_type = type; }
	void set_int(int val) { m_val.ival = val; }
	void set_float(float val) { m_val.fval = val; }
	void set_data_ref(const DataRef &data_ref) { m_data_ref = data_ref; }
	DataType get_type() const { return m_type; }
	DataVal get_val() const { return m_val; }
	int get_int() const;
	float get_float() const;
	DataRef get_data_ref() const { return m_data_ref; }
private:
	DataType m_type;
	DataVal m_val;
	DataRef m_data_ref;
};

#endif
