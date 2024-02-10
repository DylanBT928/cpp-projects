#include <iostream>

int main()
{
    int rows;

    std::cout << "Enter rows: ";
    std::cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = rows - i; j > 0; j--)
            std::cout << ' ';

        for (int k = i; k < i + (2 * i) - 1; k ++)
            std::cout << '*';

        std::cout << '\n';
    }

    return 0;
}
