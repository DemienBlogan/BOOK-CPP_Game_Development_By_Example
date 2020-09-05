#include <iostream>
#include <conio.h>

// Program prints out values to screen
int main()
{
	int a = 36;
	int b = 5;

	std::cout << "Value of a + b is: " << a + b << std::endl;
	std::cout << "Value of a - b is: " << a - b << std::endl;
	std::cout << "Value of a * b is: " << a * b << std::endl;
	std::cout << "Value of a / b is: " << a / b << std::endl;
	std::cout << "Value of a % b is: " << a % b << std::endl;

	_getch();
	return 0;
}