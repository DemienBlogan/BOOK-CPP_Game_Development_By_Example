#include <iostream>
#include <conio.h>

// Program prints out values to screen
int main()
{
	int* p = nullptr;
	int age[5] = { 12, 6, 18, 7, 9 };
	
	p = age;
	std::cout << *p << std::endl;
	p++;
	std::cout << *p << std::endl;
	std::cout << *(p + 3) << std::endl;
	std::cout << *p << std::endl;

	_getch();
	return 0;
}