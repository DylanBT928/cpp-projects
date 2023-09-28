#include <iostream>
#include <cstring>

int main(){
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                         'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    std::string option{};
    std::cout<<"encrypt or decrypt?\n";
    std::cin>>option;

    if(option.compare("encrypt") == 0){
        //Encryption




    } else if(option.compare("decrypt") == 0){
        //Decryption




    } else {
        std::cout<<"Invalid option."<<std::endl;
    }






    return 0;
}