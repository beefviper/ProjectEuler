// Problem0017.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
Problem 17: Number letter counts

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

Answer: 21124
*/

#include "pch.h"
#include <iostream>
#include <string>

std::string makeStringFromNumber(int number);

int main()
{
	int number = 1000;
	int total = 0;

	//std::string words = makeStringFromNumber(9999);

	for (int i = 1; i <= number; i++) {
		std::string words = makeStringFromNumber(i);
		std::cout << words << std::endl;
		total += words.length();
	}

	std::cout << "The total is " << total << "." << std::endl;

	system("PAUSE");
	return 0;
}

std::string makeStringFromNumber(int number) {
	std::string result;

	std::string textnum = std::to_string(number);

	for (unsigned int i = 0; i < textnum.length(); i++) {
		if (textnum.at(i) == '1') { result += "one"; }
		if (textnum.at(i) == '2') { result += "two"; }
		if (textnum.at(i) == '3') { result += "three"; }
		if (textnum.at(i) == '4') { result += "four"; }
		if (textnum.at(i) == '5') { result += "five"; }
		if (textnum.at(i) == '6') { result += "six"; }
		if (textnum.at(i) == '7') { result += "seven"; }
		if (textnum.at(i) == '8') { result += "eight"; }
		if (textnum.at(i) == '9') { result += "nine"; }

		if (textnum.length() - i == 4) {
			if (textnum.at(i + 1) == '0' && textnum.at(i + 2) == '0' && textnum.at(i + 3) == '0') {
				result += "thousand";
				return result;
			}
			else { result += "thousand"; }
		}
		
		else if (textnum.length() - i == 3) { 
			if (textnum.at(i + 1) == '0' && textnum.at(i + 2) == '0') { result += "hundred"; return result; }
			if (textnum.at(i) == '0') {	result += "and"; }
			else { result += "hundredand"; }
		}
		
		else if (textnum.length() - i == 2) {
			if (textnum.at(i) == 0 && textnum.at(i + 1) == 0) { return result; }

			if (textnum.at(i) == '0') {
				if (textnum.at(i + 1) == '1') { result += "one"; return result; }
				if (textnum.at(i + 1) == '2') { result += "two"; return result; }
				if (textnum.at(i + 1) == '3') { result += "three"; return result; }
				if (textnum.at(i + 1) == '4') { result += "four"; return result; }
				if (textnum.at(i + 1) == '5') { result += "five"; return result; }
				if (textnum.at(i + 1) == '6') { result += "six"; return result; }
				if (textnum.at(i + 1) == '7') { result += "seven"; return result; }
				if (textnum.at(i + 1) == '8') { result += "eight"; return result; }
				if (textnum.at(i + 1) == '9') { result += "nine"; return result; }
			}
			if (textnum.at(i) == '1') {
				if (textnum.at(i + 1) == '0') { result = result.substr(0, result.length() - 3); result += "ten"; return result; }
				if (textnum.at(i + 1) == '1') { result = result.substr(0, result.length() - 3); result += "eleven"; return result; }
				if (textnum.at(i + 1) == '2') { result = result.substr(0, result.length() - 3); result += "twelve"; return result; }
				if (textnum.at(i + 1) == '3') { result = result.substr(0, result.length() - 3); result += "thirteen"; return result; }
				if (textnum.at(i + 1) == '4') { result = result.substr(0, result.length() - 3); result += "fourteen"; return result; }
				if (textnum.at(i + 1) == '5') { result = result.substr(0, result.length() - 3); result += "fifteen"; return result; }
				if (textnum.at(i + 1) == '6') { result = result.substr(0, result.length() - 3); result += "sixteen"; return result; }
				if (textnum.at(i + 1) == '7') { result = result.substr(0, result.length() - 3); result += "seventeen"; return result; }
				if (textnum.at(i + 1) == '8') { result = result.substr(0, result.length() - 3); result += "eighteen"; return result; }
				if (textnum.at(i + 1) == '9') { result = result.substr(0, result.length() - 3); result += "nineteen"; return result; }
			}
			else if (textnum.at(i) == '2') { result = result.substr(0, result.length() - 3); result += "twen"; }
			else if (textnum.at(i) == '3') { result = result.substr(0, result.length() - 5); result += "thir"; }
			else if (textnum.at(i) == '4') { result = result.substr(0, result.length() - 4); result += "for"; }
			else if (textnum.at(i) == '5') { result = result.substr(0, result.length() - 4); result += "fif"; }
			else if (textnum.at(i) == '8') { result = result.substr(0, result.length() - 1); }

			if (textnum.at(i+1) == '0') {
				result += "ty";
			}
			else {
				result += "ty";
			}
		}
	}

	return result;
}
