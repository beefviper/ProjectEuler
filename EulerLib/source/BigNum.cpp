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

	// lambda helper
	auto valid_iter_equals = [&num_iter, &num_iter_end](const char& character)
	{
		return (num_iter != num_iter_end) && (*num_iter == character);
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
		++num_iter;

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
		else if ((num_iter != num_iter_end) && (isValidDigitForBase(*num_iter, 8)))
		{
			decoded_base = 8;
			--num_iter;
		}
		// decode base error
		else
		{
			decoded_base = 0;
			--num_iter;
		}
	}

	// assign base
	if (decoded_base != 0)
	{
		base = decoded_base;
	}
	else
	{
		base = input_base;
	}

	// read in integer digits
	if (base != 0)
	{
		while (!valid_iter_equals('.') && isValidDigit(*num_iter))
		{
			integer.push_back(ctoi(*num_iter));
			++num_iter;
		}

		// read in fraction digits
		if (valid_iter_equals('.'))
		{
			++num_iter;
			while (num_iter != input_number.end() && isValidDigit(*num_iter))
			{
				fraction.push_back(ctoi(*num_iter));
				++num_iter;
			}
		}
	}

	// pad integer if needed
	if (integer.empty())
	{
		integer.push_back(0);
	}

	//pad fraction if needed
	if (fraction.empty())
	{
		fraction.push_back(0);
	}

	// set if valid
	if (num_iter == input_number.end())
	{
		is_valid = true;
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
	fraction = input_number.fraction;
	integer = input_number.integer;
	base = input_number.base;

	return *this;
}

// output
std::ostream& operator<<(std::ostream& output_stream, const BigNum& output_number)
{
	if (output_number.is_valid)
	{
		output_stream << (output_number.sign ? "" : "-");
		for (auto digit : output_number.integer)
		{
			output_stream << itoc(digit);
		}
		if ((output_number.fraction.size() > 0) ||
			(output_number.fraction.size() == 0 && output_number.fraction.at(0) != 0))
		{
			output_stream << ".";
			for (auto digit : output_number.fraction)
			{
				output_stream << itoc(digit);
			}
		}
		output_stream << "base" << output_number.base;
	}
	else
	{
		output_stream << "NaN";
	}

	return output_stream;
}
bool BigNum::isValidDigitForBase(const char& input_character, uint64_t input_base)
{
	char temp = ctoi(input_character);
	return (temp < input_base&& temp != -1 && input_base != 0 && input_base != 1);
}

// is digit
bool BigNum::isValidDigit(const char& input_character)
{
	return isValidDigitForBase(input_character, base);
}

// char to int
int ctoi(const char& c)
{
	int i = 0;
	if (c >= '0' && c <= '9')
	{
		return (i = c - 48);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (i = c - 55);
	}
	else if (c >= 'a' && c <= 'z'){
		return (i = c - 61);
	}
	else
	{
		return -1;
	}
}

// int to char
char itoc(const uint64_t& i)
{
	char c = 0;
	if (i >= 0 && i <= 9)
	{
		return (c = 48 + i);
	}
	else if (i >= 10 && i <= 35){
		return (c = 55 + i);
	}
	else if (i >= 36 && i <= 61)
	{
		return (c = 61 + i);
	}
	else{
		return c;
	}
}
