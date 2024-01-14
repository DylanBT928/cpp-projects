#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int guesses = 10, num;
    int secretNum = rand()%100+1;

    std::cout << "Guess the number from 1-100 within 10 tries:" << std::endl;

    //Keep on trying until there are no more tries or user guesses the right number.
    while (guesses > 0)
    {
        std::cin >> num;
        std::cout << "Guesses: " << guesses << std::endl;
        if (num > 100 || num < 1)
            //Does not use up a guess
            std::cout << "Out of bounds. Try again." << std::endl;
        else if (num < secretNum)
        {
            std::cout << "The number is higher." << std::endl;
            guesses--;
        } 
        else if (num > secretNum)
        {
            std::cout << "The number is lower." << std::endl;
            guesses--;
        } 
        else
        {
            std::cout << "Correct! You win." << std::endl;
            guesses = 0;
        }
    }
    
    if (guesses == 0 && num != secretNum)
        std::cout << "You lost." << std::endl;

    return 0;
}
