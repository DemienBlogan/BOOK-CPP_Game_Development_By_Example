#include <iostream>
#include <conio.h>

// Program prints out values to screen

void add(int a, int b)
{
	int c = a + b;

	std::cout << "Sum of " << a << " and " << b << " is " << c << std::endl;
}

int multiply(int a, int b)
{
	return a * b;
}

float multiply(float a, float b)
{
	return a * b;
}

int main()
{
	int x = 28;
	int y = 12;

	add(x, y);

	int c = multiply(12, 32);
	std::cout << "Value returned by multiply function is: " << c << std::endl;

	float d = multiply(8.352f, -12.365f);
	std::cout << "Value returned by multiply function is: " << d << std::endl;

	_getch();
	return 0;
}