#include <iostream>
#include "Log.h"

#define LOG(x) std::cout << x << std::endl

void incrementPtr(int* a)
{
	(*a)++;
}

void incrementRef(int& a)
{
	a++;
}

class Player
{
public:
	int locationX, locationY;
	int speed;

	void Move(int x, int y)
	{
		locationX += x * speed;
		locationY += y * speed;
	}
};

int main()
{
	/*
	char a = 65;
	int x = 5;
	//bool comparisonResult = x == 5;
	if (x == 6)
	{
		std::cout << a << std::endl;
		Log("Hello World!");
	}
	*/

	/*
	for (int i = 0; i < 5; i++)
	{
		Log("Hello World!");
	}
	*/

	/*
	Log("<=================================>");
	int i = 0;
	while (i < 5)
	{
		Log("Hello World!");
		i++;
	}
	*/

	/*
	int var = 8;
	int* ptr = &var;
	*ptr = 10;
	LOG(var);
	*/

	/*
	int a = 5;
	int b = 15;
	int& ref = a;
	ref = 2;

	int* ptr = &a;
	(* ptr)++;
	ptr = &b;
	(* ptr)--;
	

	incrementPtr(&a);
	incrementRef(a);

	LOG(a);
	LOG(b);
	*/

	Player player;
	player.locationX = 3;
	player.locationY = 4;
	player.speed = 5;

	player.Move(1, -1);

	LOG(player.locationX);
	LOG(player.locationY);

	std::cin.get();

	return 0;
}
