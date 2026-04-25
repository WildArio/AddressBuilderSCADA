#pragma once
#include "CsvParser.hpp"

// Внимание: generate_address использует глобальное состояние.
// Не вызывать более одного раза за сессию.
int generate_address(DataType type);