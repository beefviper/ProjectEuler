// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

int main()
{
	std::string prefix = "..\\Debug\\Problem";
	std::string current = "0013";
	std::string command =  prefix + current;
	system(command.c_str());
	
	//system("PAUSE");
    return 0;
}

