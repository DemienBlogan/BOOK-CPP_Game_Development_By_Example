#include <iostream>
#include <conio.h>

// Program prints out values to screen

enum Weekdays
{
	Monday = 0,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

int main()
{
	Weekdays today;

	today = Friday;

	if (today == Friday)
	{
		std::cout << "The weekend is here!!!" << std::endl;
	}

	_getch();
	return 0;
}