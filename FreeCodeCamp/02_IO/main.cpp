#include <iostream>
#include <string>

int main()
{
    /*
    std::cout << "Hello C++ 20" << std::endl;
    std::cerr << "ERROR: Something wrong happened.";
    std::clog << "LOG: Something happened.";
    */

    int age;
    std::string name;
    /*
    std::cout << " Enter Your age." << std::endl;
    std::cin >> age;
    std::cout << " Enter Your name." << std::endl;
    std::cin >> name;
    std::cout << "Hello " << name << ", your age is " << age << std::endl;
    */

    /*
    std::cout << " Enter Your friends age and name." << std::endl;
    std::cin >> age >> name;
    std::cout << "Hello " << name << ", your age is " << age << std::endl;
    */

    std::cout << " Enter Your name" << std::endl;
    std::getline(std::cin, name);
    std::cout << " Enter Your age" << std::endl;
    std::cin >> age;
    std::cout << "Hello " << name << ", your age is " << age << std::endl;

    return 0;
}
