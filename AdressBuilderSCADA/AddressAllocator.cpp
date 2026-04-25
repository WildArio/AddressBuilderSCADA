#include <cstdint>
#include <stdexcept>
#include "AddressAllocator.hpp"
#include "DataType.hpp"

std::uint16_t AddressAllocator::Allocate(DataType type) {
	switch (type)
	{
	case DataType::BOOL:
		return BASE_BOOL + AddressAllocator::boolOffset++;
	case DataType::INT:
		return BASE_INT + AddressAllocator::intOffset++;
	case DataType::UINT:
		return BASE_UINT + AddressAllocator::uintOffset++;
	case DataType::REAL:
		return BASE_REAL + AddressAllocator::realOffset++;
	case DataType::WORD:
		return BASE_WORD + AddressAllocator::wordOffset++;
	case DataType::DWORD:
		return BASE_DWORD + AddressAllocator::dwordOffset++;
	default:
		throw std::runtime_error("Wrong type: " + TypeToString(type));
	}
}