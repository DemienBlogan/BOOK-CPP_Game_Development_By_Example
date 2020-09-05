#include <iostream>
#include <conio.h>

class shape
{
	int a, b;

public:
	shape(int _length, int _width)
	{
		a = _length;
		b = _width;

		std::cout << "length is: " << a << " width is: " << b << std::endl;
	}

	void area()
	{
		std::cout << "Area is: " << a * b << std::endl;
	}
};

int main()
{
	shape square(8, 8);
	square.area();

	shape rectangle(12, 20);
	rectangle.area();

	_getch();
	return 0;
}