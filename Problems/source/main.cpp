// main.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "menu.h"

#include <cstdint>

namespace pe = ProjectEuler;

int main()
{
	uint64_t all{ 0 };

	uint64_t doProblem{ all };
	pe::PrintMode printMode{ pe::PrintMode::all };
	
	pe::Menu menu{doProblem, printMode};
	
	return menu.run();
}
