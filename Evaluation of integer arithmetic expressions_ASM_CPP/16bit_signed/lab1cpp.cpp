// lab 1, variant 18: (c * 149 + b * b) / (a + b - 117)
#include <iostream>

//signed 16bit integers
int16_t a, b, c;
int16_t result, num, denum;

extern "C" {void calculate_asm(void);}

void f_c(void)
{
	std::cout << "in function f_c:\n";
	std::cout << "numerator = " << (num = c * 149 + b * b) << "\n";
	std::cout << "denominator = " << (denum = a + b - 117) << "\n";
	std::cout << "result = " << (result = num / denum) << "\n";		
}

void f_asm(void)
{
	std::cout << "in function f_asm:\n";
	calculate_asm();
	std::cout << "numerator = " << num << "\n";
	std::cout << "denominator = " << denum << "\n";
	std::cout << "result = " << result << "\n";
}

int main(void)
{
	std::cout << "Enter a b c: ";
	std::cin >> a >> b >> c;
	f_c();
	result = 0; num = 0; denum = 0;
	f_asm();
	return 0;
}
