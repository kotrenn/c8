#include "data.h"

DataType::DataType()
	:m_type("int"),
	 m_ref(0)
{
}

DataType::DataType(const string &type)
	:m_type(type),
	 m_ref(0)
{
	printf("DataType::DataType(\"%s\")\n", type.c_str());
}

DataType::DataType(const string &type, int ref)
	:m_type(type),
	 m_ref(ref)
{
	printf("DataType::DataType(\"%s\", %d)\n", type.c_str(), ref);
}

bool DataType::operator==(const DataType &rhs) const
{
	return m_type == rhs.m_type && m_ref == rhs.m_ref;
}

bool DataType::operator!=(const DataType &rhs) const
{
	return m_type != rhs.m_type || m_ref != rhs.m_ref;
}



DataRef::DataRef()
	:m_vars(NULL),
	 m_name("")
{
}

DataRef::DataRef(VarTable *vars, const string &name)
	:m_vars(vars),
	 m_name(name)
{
}



Data::Data()
	:m_type(DataType("int", 0)),
	 m_val(),
	 m_data_ref()
{
}

Data::Data(const DataType &type, const DataVal &val)
	:m_type(type),
	 m_val(val),
	 m_data_ref()
{
}

int Data::get_int() const
{
	if (m_type.get_type() == "int")
		return m_val.ival;
	else
	{
		if (m_type.get_ref() > 0)
			return m_val.ival;
		else
		{
			printf("Error: typecast from float to int\n");
			exit(1);
			return -1;
		}
	}
}

float Data::get_float() const
{
	if (m_type.get_type() == "int")
		return (float)m_val.ival;
	else
		return m_val.fval;
}
