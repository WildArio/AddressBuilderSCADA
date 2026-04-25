#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "DataType.hpp"

// parsed structure from csv
typedef struct {
	std::string name;
	DataType dataType;
	uint16_t modbusAddress;
	std::string description;
} Variable;

// open csv file to build ST and csv for scada
std::ifstream OpenCsv(const std::string& path);

// parce opened csv
std::vector<std::vector<std::string>> ParseCsv(std::ifstream& file);

// build structure from parsed data - refactor due to SRP.. meh later
std::vector<Variable> BuildVariables(const std::vector<std::vector<std::string>>& rows);
