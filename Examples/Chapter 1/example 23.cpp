#include <iostream>
#include <conio.h>

// Program prints out values to screen
int main()
{
	int age = 10;
	int* location = &age;

	std::cout << location << std::endl;

	_getch();
	return 0;
}