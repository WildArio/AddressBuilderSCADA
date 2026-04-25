#include <string>
#include "AddressGenerator.hpp"
#include "CsvParser.hpp"
#include "DataType.hpp"
#include "StGenerator.hpp"

std::string GenerateStLine(const Variable& variable) {
	
	std::string rvalue{ "RegHoldingBuf" };
	std::string address{ std::to_string(variable.modbusAddress) };
	
	return std::string(rvalue + "[" + address + "]" + " := " + variable.name + ";");
}

