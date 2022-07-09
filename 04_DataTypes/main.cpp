#include <iostream>
#include <iomanip>

int main()
{
    //INTEGER NUMBERS
    //Braced initializers
    int elephantCount;  //possible garbage value
    int lionCount{};    //Initilazes to 0
    int dogCount{10};
    int catCount{15};
    int domesticatedAnimals {dogCount + catCount};

    //Functional initializers
    int appleCount(5);
    int orangeCount(15);
    int fruitCount(appleCount + orangeCount);
    //int functionalNarrowingConversion(2.9);

    //Assignment initializers
    int bikeCount = 2;
    int carCount = 5;
    int vehicleCount = bikeCount + carCount;
    //int assignmentNarrowingConversion = 2.9;

    // ints occupy 4 bytes use short and long keywords to modify if needed
    short int twoBytes;
    int fourBytes;
    long long int eightBytes;

    std::cout << " size: " << sizeof(twoBytes) << std::endl;
    std::cout << " size: " << sizeof(fourBytes) << std::endl;
    std::cout << " size: " << sizeof(eightBytes) << std::endl;


    int value1 {100};
    int value2 {-200};

    std::cout << value1 << " size: " << sizeof(value1) << std::endl;
    std::cout << value2 << " size: " << sizeof(value2) << std::endl;

    //unsigned int value3 {-500};
    signed int value4 {-500};

    std::cout << value4 << " size: " << sizeof(value4) << std::endl;

    //FRACTIONAL NUMBERS
    float number1 {1.12345678901234567890f};
    double number2 {1.12345678901234567890};
    long double number3 {1.12345678901234567890L};

    std::cout << number1 << " size: " << sizeof(number1) << std::endl;
    std::cout << number2 << " size: " << sizeof(number2) << std::endl;
    std::cout << number3 << " size: " << sizeof(number3) << std::endl;
    
    std::cout << std::setprecision(20);
    std::cout << number1 << " size: " << sizeof(number1) << std::endl;
    std::cout << number2 << " size: " << sizeof(number2) << std::endl;
    std::cout << number3 << " size: " << sizeof(number3) << std::endl;
    
    double bigNumber {.123456789e10};
    double smallNumber {123456789e-10};

    std::cout << bigNumber << std::endl;
    std::cout << smallNumber << std::endl;

    return 0;
}
