#include <iostream>

int main()
{
    int timeChoice;
    int hrs;
    int mins;
    int time;
    int addMins;
    int meridiemChoice;
    bool isValid = true;
    bool isAM = true;
    
    std::cout << "1. Standard time (12-hour)\n";
    std::cout << "2. Military time (24-hour)\n";
    std::cout << "Enter choice: ";
    std::cin >> timeChoice;

    switch (timeChoice)
    {
        case 1: 
            // Standard time (12-hour)
            std::cout << "Enter hour(s): ";
            std::cin >> hrs;
            if (hrs < 1 || hrs > 12)
            {
                isValid = false;
                break;
            }
            std::cout << "Enter min(s): ";
            std::cin >> mins;
            if (mins < 0 || mins > 59)
            {
                isValid = false;
                break;
            }
            std::cout << "1. AM\n";
            std::cout << "2. PM\n";
            std::cout << "Enter choice: ";
            std::cin >> meridiemChoice;
            if (meridiemChoice == 1)
                isAM = true;
            else if (meridiemChoice == 2)
                isAM = false;
            else
            {
                isValid = false;
                break;
            }
            if (mins < 10)
                if (isAM)
                    std::cout << "Time: " << hrs << ":0" << mins << " AM\n";
                else
                    std::cout << "Time: " << hrs << ":0" << mins << " PM\n";
            else
                if (isAM)
                    std::cout << "Time: " << hrs << ':' << mins << " AM\n";
                else
                    std::cout << "Time: " << hrs << ':' << mins << " PM\n";
            std::cout << "Add mins: ";
            std::cin >> addMins;
            addMins %= 1440;
            hrs += addMins / 60;
            addMins % 60;
            mins += addMins;
            if (mins > 59)
            {
                hrs += mins % 60;
                mins %= 60;
            }
            while (hrs > 12)
            {
                if (hrs > 12)
                {
                    if (isAM)
                        isAM = false;
                    else
                        isAM = true;
                    hrs -= 12;
                }
            }
            if (mins < 10)
                if (isAM)
                    std::cout << "Time: " << hrs << ":0" << mins << " AM\n";
                else
                    std::cout << "Time: " << hrs << ":0" << mins << " PM\n";
            else
                if (isAM)
                    std::cout << "Time: " << hrs << ':' << mins << " AM\n";
                else
                    std::cout << "Time: " << hrs << ':' << mins << " PM\n";
            break;
        case 2: 
            // Military time (24-hour)
            break;
        default:
            isValid = false;
            break;
    }

    if (isValid)
    {
        // Convert to other time format
    }
    else
        std::cout << "Invalid option." << std::endl;

    return 0;
}
