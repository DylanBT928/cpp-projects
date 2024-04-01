#include <iostream>

int main()
{
    std::string input;
    int words;

    std::cout << "Enter a sentence: ";
    getline(std::cin, input);

    if (input.length() != 0)
        words = 1;
    else
        words = 0;

    for (char c : input)
        if (c == ' ')
            words++;

    if (words == 1)
        std::cout << "There is one word." << std::endl;
    else
        std::cout << "There are " << words << " words." << std::endl;

    return 0;
}
