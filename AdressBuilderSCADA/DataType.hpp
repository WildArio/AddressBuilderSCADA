#pragma once
#include <iostream>

// variable type
enum class DataType { BOOL, INT, UINT, REAL, WORD, DWORD };

// out stream
inline std::ostream& operator<<(std::ostream& os, const DataType& dt) {
    switch (dt) {
    case DataType::BOOL:   os << "BOOL"; break;
    case DataType::INT:    os << "INT"; break;
    case DataType::UINT:   os << "UINT"; break;
    case DataType::REAL:   os << "REAL"; break;
    case DataType::WORD:   os << "WORD"; break;
    case DataType::DWORD:  os << "DWORD"; break;
    default:               os << "UNKNOWN";
    }

    return os;
}

DataType StringToType(const std::string& type);

std::string TypeToString(DataType type);