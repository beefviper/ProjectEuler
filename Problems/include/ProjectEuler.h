/* ProjectEuler.h         */
/* author  : beefviper    */
/* version : 0.1          */
/* date    : Jul 01, 2022 */

#pragma once

#include "EulerLib.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cstdint>

struct Problem
{
	uint64_t number{ 0 };
	uint64_t (*solution)() { nullptr };
	uint64_t answer{ 0 };
};

void createProblems(std::vector<Problem>& problems);

uint64_t problem1();
uint64_t problem2();
uint64_t problem3();
uint64_t problem4();
uint64_t problem5();
uint64_t problem6();
uint64_t problem7();
uint64_t problem8();
uint64_t problem9();
uint64_t problem10();
uint64_t problem11();
uint64_t problem12();
uint64_t problem13();
uint64_t problem14();
uint64_t problem15();
uint64_t problem16();
uint64_t problem17();
uint64_t problem18();
uint64_t problem20();
uint64_t problem21();
uint64_t problem22();
uint64_t problem23();
uint64_t problem25();
