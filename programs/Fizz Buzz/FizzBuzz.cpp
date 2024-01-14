#include <iostream>

int main()
{
    //For-Loop counts from 1 to 100
    for (int i = 1; i <= 100; i++)
        if (i % 3 == 0 && i % 5 == 0)
            std::cout << "FizzBuzz" << std::endl; //Prints FizzBuzz if the number is divisible by 3 and 5
        else
            if (i % 3 == 0)
                std::cout << "Fizz" << std::endl; //Prints Fizz if the number is only divisible by 3
            else if (i % 5 == 0)
                std::cout << "Buzz" << std::endl; //Prints Buzz if the number is only divisible by 5
            else
                std::cout << i << std::endl; //Prints the number if the number is not divisible by 3 or 5

    return 0;
}
