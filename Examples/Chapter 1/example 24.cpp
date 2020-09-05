#include <iostream>
#include <conio.h>

// Program prints out values to screen
int main()
{
	int age = 18;
	int* pointer;

	pointer = &age;

	*pointer = 12;

	std::cout << age << std::endl;

	_getch();
	return 0;
}