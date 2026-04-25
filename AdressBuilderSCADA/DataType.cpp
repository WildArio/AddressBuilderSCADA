#include <string>
#include "DataType.hpp"

DataType StringToType(const std::string& type) {
	if (type == "BOOL") return DataType::BOOL;
	if (type == "INT") return DataType::INT;
	if (type == "UINT") return DataType::UINT;
	if (type == "REAL") return DataType::REAL;
	if (type == "WORD") return DataType::WORD;
	if (type == "DWORD") return DataType::DWORD;

	throw std::runtime_error("Wrong or empty data type! " + type);
}

std::string TypeToString(DataType type) {
	switch (type)
	{
	case DataType::BOOL:
		return "BOOL";
	case DataType::INT:
		return "INT";
	case DataType::UINT:
		return "UINT";
	case DataType::REAL:
		return "REAL";
	case DataType::WORD:
		return "WORD";
	case DataType::DWORD:
		return "DWORD";
	default:
		return "UNKNOWN: " + static_cast<int>(type);
	}
}
