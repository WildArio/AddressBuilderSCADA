#pragma once
#include <cstdint>
#include "DataType.hpp"

// moved globals to static member variable, also now i can use multiple AddressAllocators
class AddressAllocator {
	inline static std::uint16_t boolOffset{};
	inline static std::uint16_t intOffset{};
	inline static std::uint16_t uintOffset{};
	inline static std::uint16_t realOffset{};
	inline static std::uint16_t wordOffset{};
	inline static std::uint16_t dwordOffset{};

public:
	std::uint16_t Allocate(DataType type);

private:
	static constexpr std::uint16_t BASE_BOOL{ 15000 };
	static constexpr std::uint16_t BASE_INT{ 20000 };
	static constexpr std::uint16_t BASE_UINT{ 25000 };
	static constexpr std::uint16_t BASE_REAL{ 40000 };
	static constexpr std::uint16_t BASE_WORD{ 30000 };
	static constexpr std::uint16_t BASE_DWORD{ 35000 };
};