// eulerlib.h
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace ProjectEuler {

struct SetOfBits;

uint64_t fib(uint64_t number);
std::string multipleLargeNumbers(std::string numOne, std::string numTwo);
std::string addLargeNumbers(std::string numberOne, std::string numberTwo);
std::vector<int> createNumber(std::string number);
std::vector<uint64_t> getFactors(uint64_t number);
std::vector<uint64_t> getProperDivisors(uint64_t number);
uint64_t sumOfVector(std::vector<uint64_t> numbers);
std::vector<std::string> loadNumbers(std::string fileName);
std::vector<uint64_t> primeFactors(uint64_t number);
bool isPalindrome(uint64_t number);
bool isDivisibleByRange(uint64_t begin, uint64_t end, uint64_t number);
uint64_t sumOfSquares(uint64_t number);
uint64_t squareOfSums(uint64_t number);
bool checkPrime(uint64_t n);
uint64_t getPrimeByIndex(uint64_t index);
uint64_t collatz(uint64_t number);
std::vector<bool> setBits(std::string bitString);
std::vector<bool> shiftBits(std::vector<bool> bits, uint64_t numberOfBits, uint64_t amountToShift);
SetOfBits recursiveShifts(SetOfBits solution);
std::string makeStringFromNumber(uint64_t number);
std::vector<std::string> loadTriangle(std::string fileName);

struct SetOfBits
{
	std::vector<bool> bits;
	uint64_t numberOfBits = 0;
	uint64_t amountToShift = 0;
};

} // namespace ProjectEuler
