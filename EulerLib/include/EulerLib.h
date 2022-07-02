/* EulerLib.h             */
/* author  : beefviper    */
/* version : 0.1          */
/* date    : Jul 01, 2022 */

#pragma once

#include "BigNum.h"

#include <iostream>
#include <vector>
#include <cstdint>

struct SetOfBits;

int fib(int number);
std::string multipleLargeNumbers(std::string numOne, std::string numTwo);
std::string addLargeNumbers(std::string numberOne, std::string numberTwo);
std::vector<int> createNumber(std::string number);
std::vector<uint64_t> getFactors(uint64_t number);
std::vector<uint64_t> getProperDivisors(uint64_t number);
uint64_t sumOfVector(std::vector<uint64_t> numbers);
std::vector<std::string> loadNumbers(std::string fileName);
std::vector<uint64_t> primeFactors(uint64_t number);
bool isPalindrome(int number);
bool isDivisibleByRange(int begin, int end, int number);
int sumOfSquares(int number);
int squareOfSums(int number);
bool checkPrime(int n);
int getPrimeByIndex(int index);
int collatz(int number);
std::vector<bool> setBits(std::string bitString);
std::vector<bool> shiftBits(std::vector<bool> bits, int numberOfBits, int amountToShift);
SetOfBits recursiveShifts(SetOfBits solution);
std::string makeStringFromNumber(int number);
std::vector<std::string> loadTriangle(std::string fileName);

struct SetOfBits
{
	std::vector<bool> bits;
	int numberOfBits = 0;
	int amountToShift = 0;
};
