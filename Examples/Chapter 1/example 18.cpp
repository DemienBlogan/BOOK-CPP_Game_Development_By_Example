#include <iostream>
#include <conio.h>

// Program prints out values to screen
int main()
{
	int age[5] = { 12, 6, 18, 7, 9 };

	std::cout << "Element at the 0th index " << age[0] << std::endl;
	std::cout << "Element at the 4th index " << age[4] << std::endl;

	_getch();
	return 0;
}