#include <iostream>

int main()
{
    double cost;
    std::string price;
    int quarters, dimes, nickels, pennies;

    std::cout << "Enter the cost: ";
    std::cin >> cost;

    //Finds how many of each coin can go into the cost
    quarters = cost / 0.25;
    cost -= quarters * 0.25;
    dimes = cost / 0.10;
    cost -= dimes * 0.10;
    nickels = cost / 0.05;
    cost -= nickels * 0.05;
    pennies = cost / 0.01;

    //Returns amount of change
    std::cout << "You need " << quarters << " quarters, ";
    std::cout << dimes << " dimes, ";
    std::cout << nickels << " nickels, and ";
    std:: cout << pennies << " pennies." << std::endl;
    
    return 0;
}
