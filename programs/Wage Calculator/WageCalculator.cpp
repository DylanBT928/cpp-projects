#include <iostream>

double wagePerHour;
double wagePerMin;
int minsWorked;

double minuteWage(double hourlyWage)
{
    return hourlyWage /= 60.0;
}

int main()
{
    std::cout << "What is your hourly wage?\n";
    std::cout << "Wage per hour: $";
    std::cin >> wagePerHour;
    wagePerMin = minuteWage(wagePerHour);
    std::cout << "Wage per minute: $" << wagePerMin << '\n';
    std::cout << "How many minutes have you worked? ";
    std::cin >> minsWorked;
    std::cout << "You should be paid $" << (minsWorked * wagePerMin);

    return 0;
}
