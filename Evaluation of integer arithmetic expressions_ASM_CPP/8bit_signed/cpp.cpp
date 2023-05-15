// lab 1, variant 18: (c * 149 + b * b) / (a + b - 117)
#include <iostream>

//signed 8bit integers
int8_t a, b, c;
int16_t num;
int8_t result, denom;

extern "C" {void calculate_asm(void);}

void f_c(void)
{
	int32_t tempnum, tempdenom, tempresult;
	std::cout << "in function f_c:\n";
	std::cout << "numerator = " << int(num = tempnum = c * int8_t(149) + b * b) << "\n";
	std::cout << "denominator = " << int(denom = tempdenom = a + b - 117) << "\n";
	std::cout << "result = " << int(result = tempresult = num / denom) << "\n";

	if (tempnum > 65535 || tempdenom > 255 || tempresult > 255) {
		std::cout << "invalid input. Aborting.\n";
		exit(1);
	}
}

void f_asm(void)
{
	std::cout << "in function f_asm:\n";
	calculate_asm();
	std::cout << "numerator = " << int(num) << "\n";
	std::cout << "denominator = " << int(denom) << "\n";
	std::cout << "result = " << int(result) << "\n";
}

int main(void)
{
	int tempa, tempb, tempc;
	std::cout << "Enter a b c: ";
	std::cin >> tempa >> tempb >> tempc;

	if (tempa > 255 || tempb > 255 || tempc > 255) {
		std::cout << "Invalid input\n";
		exit(1);
	}

	a = tempa; b = tempb; c = tempc;
	f_c();
	result = 0; num = 0; denom = 0;
	f_asm();
	return 0;
}
