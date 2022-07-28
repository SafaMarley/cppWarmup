#include <iostream>
//#include "Log.h"

#define LOG(x) std::cout << x << std::endl

/*
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
*/

/*
class Log
{
private:
	int level; // 0: info 1: warning 2: error
public:
	void SetLevel(int level)
	{
		this->level = level;
	}

	void Info(const char* message)
	{
		if (level > 0)
		{
			std::cout << "[Error] " << message << std::endl;
		}
	}

	void Warn(const char* message)
	{
		if (level > 1)
		{
			std::cout << "[Error] " << message << std::endl;
		}
	}

	void Error(const char* message)
	{
		if (level > 2)
		{
			std::cout << "[Error] " << message << std::endl;
		}
	}
};
*/

/*
struct Entity
{
	static int x, y;

	void PrintLog()
	{
		std::cout << x << ", " << y << std::endl;
	}
};

int Entity::x;
int Entity::y;
*/

/*
enum Example
{
	A = 0, B = 2, C = 4
};
*/

//int main()
//{
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

	/*
	Player player;
	player.locationX = 3;
	player.locationY = 4;
	player.speed = 5;

	player.Move(1, -1);

	LOG(player.locationX);
	LOG(player.locationY);
	*/

	/*
	Log log;
	log.SetLevel(4);
	log.Error("Hi");
	*/

	/*
	Entity e1;
	e1.x = 5;
	e1.y = 4;

	Entity e2;
	e2.x = 15;
	e2.y = 14;

	Entity::x = 1;
	Entity::y = 2;

	e1.PrintLog();
	e2.PrintLog();
	*/

//	Example value = A;
//
//	std::cin.get();
//
//	return 0;
//}

/*
class Entity
{
	float x, y;
public:
	Entity()
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}
	Entity(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	~Entity()	//Destructor being called after the object being destroyed
	{

	}

	//virtual void Print()
	//{
	//	std::cout << x << ", " << y << std::endl;
	//}
	
	virtual void Print() = 0;	//Pure virtual function
};

class Player:public Entity
{
	std::string name;
public:
	Player(const std::string name)
	{
		this->name = name;
	}
	
	void Print() override
	{
		std::cout << name << std::endl;
	}
};


int main()
{
	//Entity e(10.0f, 20.5f);
	//e.Print();

	Player p("safa");
	p.Print();

	std::cin.get();
	return 0;
}
*/

int main()
{
	int example[5];					//created in stack
	example[0] = 1;
	example[4] = 10;
	int* ptrArray = new int[5];		//created in heap

	int count = sizeof(example) / sizeof(int);

	std::cin.get();
}