#include <iostream>
#include <conio.h>

// Program prints out values to screen
int main()
{
	int age[5] = { 12, 6, 18, 7, 9 };

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Element at the " << i << "th index " << age[i] << std::endl;
	}

	_getch();
	return 0;
}