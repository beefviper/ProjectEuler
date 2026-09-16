// main.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "menu.h"

int main()
{
	uint64_t all{ 0 };

	uint64_t doProblem{ all };
	PrintMode printMode{ PrintMode::all };
	
	Menu menu{doProblem, printMode};
	
	return menu.run();
}
