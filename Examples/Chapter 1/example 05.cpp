#include <iostream>
#include <conio.h>

// Program prints out value of a + b and x + y to screen
int main()
{
	int a = 8;
	int b = 12;
	std::cout << "Value of a + b is: " << a + b << std::endl;

	float x = 7.345f;
	float y = 12.8354;
	std::cout << "Value of x + y is: " << x + y << std::endl;

	_getch();
	return 0;
}