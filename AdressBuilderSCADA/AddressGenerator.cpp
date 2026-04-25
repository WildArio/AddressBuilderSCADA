#include "AddressGenerator.hpp"
#include "DataType.hpp"

const static int BOOL_ADDRESS{10000};
const static int INT_ADDRESS{15000};
const static int UINT_ADDRESS{20000};
const static int REAL_ADDRESS{30000};
const static int WORD_ADDRESS{40000};
const static int DWORD_ADDRESS{45000};

static int BOOL_OFFSET{};
static int INT_OFFSET{};
static int UINT_OFFSET{};
static int REAL_OFFSET{};
static int WORD_OFFSET{};
static int DWORD_OFFSET{};

int generate_address(DataType type) {

	switch(type) {
    case DataType::BOOL:   return BOOL_ADDRESS + BOOL_OFFSET++;
    case DataType::INT:    return INT_ADDRESS + INT_OFFSET++;
    case DataType::UINT:   return UINT_ADDRESS + UINT_OFFSET++;
    case DataType::REAL:   throw("error real is 2 word size"); return REAL_ADDRESS + REAL_OFFSET++;
    case DataType::WORD:   return WORD_ADDRESS + WORD_OFFSET++;
    case DataType::DWORD:  throw("error dword is 2 word size");  return DWORD_ADDRESS + DWORD_OFFSET++;
    default:               return 0;
    }
	return 0;
}