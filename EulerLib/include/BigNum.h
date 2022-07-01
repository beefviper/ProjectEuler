/* BigNum.h               */
/* author  : beefviper    */
/* version : 0.1          */
/* date    : Jul 01, 2022 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

using Number = std::vector<int64_t>;

class BigNum
{
public:
	BigNum() = default;
	BigNum(const std::string& input_number, uint64_t input_base = 10);
	BigNum(const BigNum& input_number);

	BigNum& operator=(const BigNum& input_number);

	friend std::ostream& operator<<(std::ostream& output_stream, const BigNum& output_number);

private:
	bool is_valid{ false };
	bool sign{ true };
	Number integer;
	Number faction;
	uint64_t base{ 10 };

	bool isValidDigit(const char& input_character);
	bool isValidDigitForBase(const char& input_character, uint64_t input_base);

	int ctoi(const char& c);
	char itoc(const int& i);

};
