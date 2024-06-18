#include <iostream>

int main()
{
    int timeChoice;       // Standard or military
    int hrs;              // Hours for standard
    int mins;             // Minutes for standard
    int time;             // Time for military
    int addMins;          // Add amount of minutes
    int meridiemChoice;   // AM or PM
    int convertChoice;    // Do or do not convert
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
            std::cout << "Enter time: ";
            std::cin >> time;
            if (time < 0 || time > 2359)
            {
                isValid = false;
                break;
            }
            if (time < 10)
                std::cout << "Time: 000" << time << '\n';
            else if (time < 100)
                std::cout << "Time: 00" << time << '\n';
            else if (time < 1000)
                std::cout << "Time: 0" << time << '\n';
            else
                std::cout << "Time: " << time << '\n';
            std::cout << "Add mins: ";
            std::cin >> addMins;
            addMins %= 2359;
            time += addMins;
            if (time > 2359)
                time -= 2400;
            if (time < 10)
                std::cout << "Time: 000" << time << '\n';
            else if (time < 100)
                std::cout << "Time: 00" << time << '\n';
            else if (time < 1000)
                std::cout << "Time: 0" << time << '\n';
            else
                std::cout << "Time: " << time << '\n';
            break;
        default:
            isValid = false;
            break;
    }

    if (isValid)
    {
        // Convert to other time format
        std::cout << "Would you like to convert time formats?\n";
        std::cout << "1. Yes\n";
        std::cout << "2. No\n";
        std::cout << "Enter choice: ";
        std::cin >> convertChoice;
        if (convertChoice == 1)
        {
            if (timeChoice == 1)
            {
                // Standard to military
                if (isAM == false)
                {
                    hrs += 12;
                }
                if (hrs < 10)
                    if (mins < 10)
                        std::cout << "Converted Time: 0" << hrs << '0' << mins << std::endl;
                    else
                        std::cout << "Converted Time: 0" << hrs << mins << std::endl;
                else
                    if (mins < 10)
                        std::cout << "Converted Time: " << hrs << '0' << mins << std::endl;
                    else
                        std::cout << "Converted Time: " << hrs << mins << std::endl;
            }
            else
            {
                // Military to standard
                



            }
        }
        else if (convertChoice == 2)
            return 0;
        else
            isValid = false;
    }
    if (!isValid)
        std::cout << "Invalid option." << std::endl;

    return 0;
}
