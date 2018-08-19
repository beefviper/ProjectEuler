// ScratchPad2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::string fileName = "test.txt";

	std::ofstream outputFile(fileName);
	
	if (!outputFile.is_open()) {
		std::cout << "Failed to open file." << std::endl;
	}
	else {
		outputFile << "test" << "test" << std::endl;
	}

	outputFile.close();

	std::string numbersFileName = "numbers.txt";
	std::ifstream numbersFile(numbersFileName);
	std::vector<std::string> numbers;
	std::string number;

	if (numbersFile.is_open()) {
		while (std::getline(numbersFile, number)) {
			if (number.size() > 0) {
				numbers.push_back(number);
			}
		}
	}
	else {
		std::cout << "Failed to open file." << std::endl;
	}

	numbersFile.close();

	std::cout << "Size of numbers vector is " << numbers.size() << "." << std::endl;

	system("PAUSE");
	return 0;
}

