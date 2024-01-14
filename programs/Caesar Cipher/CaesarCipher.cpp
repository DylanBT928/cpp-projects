#include <iostream>
#include <ctype.h>

int main()
{
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                         'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    std::string message, newmsg;
    int option = 1, shift = 3;

    std::cout << "(1) encrypt or (2) decrypt: ";
    std::cin >> option;
    std::cout << "enter shift value: ";
    std::cin >> shift;
    std::cout << "enter message: ";
    std::cin >> message;

    switch (option)
    {
        case 1:
            //Encryption
            std::cout << "encrypting...\n";
            for (int i = 0; i < message.length(); i++)
            {
                int j = 0;
                while (message.at(i) != alphabet[j] && j<26)
                {
                    j++;
                }
                if (isalpha(message.at(i)))
                    if (j + shift < 26)
                        newmsg += alphabet[j + shift];
                    else
                        newmsg += alphabet[j + shift - 26];
                else
                    newmsg += message[i];
                j = 0;
            }
            std::cout << newmsg;
            break;
        case 2:
            //Decryption
            std::cout<<"decrypting...\n";
            for (int i = 0; i < message.length(); i++)
            {
                int j = 0;
                while (message.at(i) != alphabet[j] && j < 26)
                {
                    j++;
                }
                if (isalpha(message.at(i)))
                    if(j - shift < 26)
                        newmsg += alphabet[j - shift];
                    else
                        newmsg += alphabet[j - shift + 26];
                else
                    newmsg += message[i];
                j = 0;
            }
            std::cout << newmsg;
            break;
        default:
            std::cout << "Invalid option." << std::endl;
            break;
    }
    
    return 0;
}
