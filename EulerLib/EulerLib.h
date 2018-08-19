#pragma once

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

int fib(int number);
std::string multipleLargeNumbers(std::string numOne, std::string numTwo);
std::string addLargeNumbers(std::string numberOne, std::string numberTwo);
std::vector<int> createNumber(std::string number);
std::vector<uint64_t> getFactors(uint64_t number);
std::vector<uint64_t> getProperDivisors(uint64_t number);
uint64_t sumOfVector(std::vector<uint64_t> numbers);
