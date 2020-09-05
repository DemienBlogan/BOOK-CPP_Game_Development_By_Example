#include <iostream>
#include <conio.h>

// Program prints out values to screen
int main()
{
	int a = 28;

	switch (a)
	{
	case 1:
		std::cout << "value of a is: " << a << std::endl;
		break;

	case 2:
		std::cout << "value of a is: " << a << std::endl;
		break;

	case 3:
		std::cout << "value of a is: " << a << std::endl;
		break;

	case 4:
		std::cout << "value of a is: " << a << std::endl;
		break;

	case 5:
		std::cout << "value of a is: " << a << std::endl;
		break;

	default:
		std::cout << "value a is out of range" << std::endl;
		break;
	}

	_getch();
	return 0;
}