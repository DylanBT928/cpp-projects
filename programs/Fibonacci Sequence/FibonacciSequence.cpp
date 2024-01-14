#include <iostream>

int main()
{
    //sequence starts with 0 and 1
    float x = 0;
    float y = 1;
    float z = x + y;
    int nth;

    std::cout << "nth digit: ";
    std::cin >> nth;

    switch (nth)
    {
        case 0: 
            std::cout << "Nothing is printed.";
            break;
        case 1:
            std::cout << "0";
            break;
        case 2:
            std::cout << "0, 1";
            break;
        default:
            std::cout << "0, 1";
            while (nth>2)
            {
                std::cout << ", " << z;
                x = y;
                y = z;
                z = x + y;
                nth--;
            }
            break;
    }

    return 0;
}
