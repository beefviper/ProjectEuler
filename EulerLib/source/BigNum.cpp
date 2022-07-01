/* BigNum.cpp             */
/* author  : beefviper    */
/* version : 0.1          */
/* date    : Jul 01, 2022 */

#include "BigNum.h"

#include <sstream>

// bignum from string
BigNum::BigNum(const std::string& input_number, uint64_t input_base)
{
	// iterators
	std::string::const_iterator num_iter = input_number.begin();
	std::string::const_iterator num_iter_end = input_number.end();

	// lambda helpers
	auto valid_iter_equals = [&num_iter, &num_iter_end](const char& character)
	{
		return (num_iter != num_iter_end) && (*num_iter == character);
	};

	auto valid_iter_not_equals = [&num_iter, &num_iter_end](const char& character)
	{
		return (num_iter != num_iter_end) && (*num_iter != character);
	};

	auto valid_iter_and_digit_for_base = [&num_iter, &num_iter_end, this](uint64_t in_base)
	{
		return (num_iter != num_iter_end) && (isValidDigitForBase(*num_iter, in_base));
	};

	// check for negative
	if (valid_iter_equals('-'))
	{
		sign = false;
		++num_iter;
	}

	// decode input_number with leading zero
	uint64_t decoded_base{ 0 };

	if (valid_iter_equals('0'))
	{
		num_iter++;

		// check for hex
		if (valid_iter_equals('x'))
		{
			decoded_base = 16;
			++num_iter;
		}
		// check for binary
		else if (valid_iter_equals('b'))
		{
			decoded_base = 2;
			++num_iter;
		}
		// check for base62
		else if (valid_iter_equals('s'))
		{
			decoded_base = 62;
			++num_iter;
		}
		// check for octal
		else if (valid_iter_and_digit_for_base(8))
		{
			decoded_base = 8;
			--num_iter;
		}
	}


	if (base == decoded_base)
	{
		if (valid_iter_not_equals('.'))
		{

		}

	}

}

// bignum from bignum
BigNum::BigNum(const BigNum& input_number)
{
	*this = input_number;
}

// equals
BigNum& BigNum::operator=(const BigNum& input_number)
{
	is_valid = input_number.is_valid;
	sign = input_number.sign;
	faction = input_number.faction;
	integer = input_number.integer;
	base = input_number.base;

	return *this;
}

// output
std::ostream& operator<<(std::ostream& output_stream, const BigNum& output_number)
{
	output_stream << (output_number.sign ? "" : "-");
	for (auto digit : output_number.integer)
	{
		output_stream << digit;
	}
	output_stream << "base" << output_number.base;

	return output_stream;
}
bool BigNum::isValidDigitForBase(const char& input_character, uint64_t input_base)
{
	char temp = ctoi(input_character);
	return (temp < input_base && temp != -1 && input_base != 0 && input_base != 1);
}

// is digit
bool BigNum::isValidDigit(const char& input_character)
{
	isValidDigitForBase(input_character, base);
}

// char to int
int BigNum::ctoi(const char& c) {
	int i = 0;
	if (c >= '0' && c <= '9') { return (i = c - 48); }
	else if (c >= 'A' && c <= 'Z') { return (i = c - 55); }
	else if (c >= 'a' && c <= 'z') { return (i = c - 61); }
	else { return -1; }
}

// int to char
char BigNum::itoc(const int& i) {
	char c = 0;
	if (i >= 0 && i <= 9) { return (c = 48 + i); }
	else if (i >= 10 && i <= 35) { return (c = 55 + i); }
	else if (i >= 36 && i <= 61) { return (c = 61 + i); }
	else { return c; }
}
