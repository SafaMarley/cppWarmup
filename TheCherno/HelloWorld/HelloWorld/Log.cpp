#include <iostream>
/*
void Log(const char* message)
{
	std::cout << message << std::endl;
}
*/

/*
class Log
{
public:
	enum level
	{
		Error = 0, Warning, Info
	};
private:
	level currentLevel = Error;
public:
	void SetLevel(level level)
	{
		this->currentLevel = level;
	}

	void PrintInfo(const char* message)
	{
		if (currentLevel >= Info)
		{
			std::cout << "[Information] " << message << std::endl;
		}
	}

	void PrintWarn(const char* message)
	{
		if (currentLevel >= Warning)
		{
			std::cout << "[Warning] " << message << std::endl;
		}
	}

	void PrintError(const char* message)
	{
		if (currentLevel >= Error)
		{
			std::cout << "[Error] " << message << std::endl;
		}
	}
};

int main()
{
	Log log;
	log.SetLevel(Log::Warning);
	log.PrintInfo("Hi");
	log.PrintWarn("Hey");
	log.PrintError("Hello");
}
*/
