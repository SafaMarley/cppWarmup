#include <iostream>

int SumOf2(int a, int b)
{
    return a + b;
}

int MultiplicationOf2(int a, int b)
{
    return a * b;
}

int main()
{
    std::cout << SumOf2(5, 8) << std::endl;

    int firstNum = 5;
    int secondNum = 8;
    std::cout << SumOf2(firstNum, secondNum) << std::endl;
    
    int sum = SumOf2(firstNum, secondNum);
    std::cout << sum << std::endl;

    int multiplication = MultiplicationOf2(5, 8);
    std::cout << multiplication << std::endl;

    return 0;
}
