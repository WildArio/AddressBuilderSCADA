#include <cstdint>
#include <stdexcept>
#include "AddressAllocator.hpp"
#include "DataType.hpp"

std::uint16_t AddressAllocator::Allocate(DataType type) {
	switch (type)
	{
	case DataType::BOOL:
		return BASE_BOOL + boolOffset++;
	case DataType::INT:
		return BASE_INT + intOffset++;
	case DataType::UINT:
		return BASE_UINT + uintOffset++;
	case DataType::REAL: {
		std::uint16_t addr = BASE_REAL + realOffset;
		realOffset += 2;
		return addr;
	}
	case DataType::WORD:
		return BASE_WORD + wordOffset++;
	case DataType::DWORD: {
		std::uint16_t addr = BASE_REAL + dwordOffset;
		dwordOffset += 2;
		return addr;
	}
	default:
		throw std::runtime_error("Wrong type: " + TypeToString(type));
	}
}