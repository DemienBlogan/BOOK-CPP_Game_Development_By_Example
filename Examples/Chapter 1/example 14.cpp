#include <iostream>
#include <conio.h>

// Program prints out values to screen
int main()
{
	for (int n = 0; n < 10; n++)
	{
		if (n == 5)
		{
			std::cout << "break" << std::endl;
			break;
		}

		std::cout << "value of n is: " << n << std::endl;
	}

	_getch();
	return 0;
}