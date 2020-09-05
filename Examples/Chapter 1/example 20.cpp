#include <iostream>
#include <conio.h>

// Program prints out values to screen
int main()
{
	int matrix[4][4] =
	{
		{ 2, 8, 10, -5 },
		{ 15, 21, 22, 32 },
		{ 3, 0, 19, 5 },
		{ 5, 7, -23, 18 }
	};

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			std::cout << matrix[x][y] << " ";
		}
		std::cout << std::endl;
	}

	_getch();
	return 0;
}