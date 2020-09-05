#include <iostream>
#include <conio.h>

// Program prints out values to screen
int main()
{
	for (int n = 0; n < 10; n += 2)
		std::cout << "value of n is: " << n << std::endl;

	_getch();
	return 0;
}