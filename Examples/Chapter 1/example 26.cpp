#include <iostream>
#include <conio.h>

struct student
{
	int age;
	float height;
};

int main()
{
	student section[3];

	section[0].age = 17;
	section[0].height = 39.45f;	

	section[1].age = 12;
	section[1].height = 29.45f;

	section[2].age = 8;
	section[2].height = 13.45f;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "student " << i << " age: " << section[i].age;
		std::cout << " height: " << section[i].height << std::endl;
	}

	_getch();
	return 0;
}