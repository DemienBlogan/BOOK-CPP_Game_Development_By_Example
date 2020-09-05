#include <iostream>
#include <conio.h>

class shape
{
protected:
	float a, b;

public:
	void setValues(float _length, float _width)
	{
		a = _length;
		b = _width;

		std::cout << "length is: " << a << " width is: " << b << std::endl;
	}

	void setValues(float _a)
	{
		a = _a;
	}

	void area()
	{
		std::cout << "Area is: " << a * b << std::endl;
	}
};

class triangle : public shape
{
public:
	void area()
	{
		std::cout << "Area of a Triagnle is: " << 0.5f * a * b << std::endl;
	}
};

class circle : public shape
{
public:
	void area()
	{
		std::cout << "Area of a Circle is: " << 3.14f * a * a << std::endl;
	}
};

int main()
{
	shape rectangle;
	rectangle.setValues(8.0f, 12.0f);
	rectangle.area();

	triangle tri;
	tri.setValues(3.0f, 23.0f);
	tri.area();

	circle c;
	c.setValues(5.0f);
	c.area();

	_getch();
	return 0;
}