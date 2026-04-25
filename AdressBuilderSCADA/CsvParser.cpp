#include <cstdint>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <string>
#include "AddressAllocator.hpp"
#include "CsvParser.hpp"
#include "DataType.hpp"

std::ifstream OpenCsv(const std::string& path) {
	std::ifstream file(path);

	if (!file.is_open()) {
		throw std::runtime_error("Cannot open file: " + path);
	}

	return file; // You can't copy ifstream, invoke move, NRVO in auto file.
}

std::vector<std::vector<std::string>> ParseCsv(std::ifstream& file) {
	std::vector<std::vector<std::string>> rows;
	std::string line;

	while (std::getline(file, line)) {
		if (line.empty()) continue;

		std::vector<std::string> row;
		std::stringstream ss(line);
		std::string field;

		while (std::getline(ss, field, ',')) {
			row.push_back(field);
		}

		rows.push_back(std::move(row));
	}

	return rows;
}

std::vector<Variable> BuildVariables(const std::vector<std::vector<std::string>>& rows) {
	if (rows.empty()) {
		throw std::runtime_error("Empty CSV input!");
	}

	std::vector<Variable> vars;
	AddressAllocator allocator{};

	size_t startRow{ (rows[0][0] == "Name") ? size_t(1) : size_t(0)};

	for (size_t i = startRow; i < rows.size(); i++) {
		const auto& row = rows[i];

		if (row.size() < 2) {
			throw std::runtime_error("Invalid row format at line: " + std::to_string(i));
		}

		Variable v;
		v.name = row[0];
		v.dataType = StringToType(row[1]);
		v.modbusAddress = allocator.Allocate(v.dataType);
		v.description = (row.size() > 2) ? row[2] : "";

		vars.push_back(std::move(v));
	}

	return vars;
}

