#include <iostream>
#include <string>

int main()
{
    int num;
    std::string factors = "1";
    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    for (int i = 2; i <= num; i++)
        if (num % i == 0)
            factors += ", " + std::to_string(i);

    if (factors != ("1, " + std::to_string(num)))
        std::cout << "Factors: " << factors << std::endl;
    else
        std::cout << "Prime number (divisible only by 1 and itself)" << std::endl;

    return 0;
}
