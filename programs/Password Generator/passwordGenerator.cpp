#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

bool hasUpper{false};
bool hasLower{false};
bool hasNumber{false};
bool hasSpecial{false};
std::string input{};
int type{};
int length{};

char upperLetters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char lowerLetters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char numbers[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
char special[32] = {'!','\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', ':', 
                   ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`', '{', '|', '}', '~'};

std::string generatePassword(std::string input){
    int srand(static_cast<unsigned int>(time(nullptr))); //rand()%26
    std::string password{};
    for(int i = 0; i < length; i++){
        if(input == "0001"){
            password += special[rand()%32];
        } else if(input == "0010"){
            password += numbers[rand()%32];
        } else if(input == "0011"){
            password += numbers[rand()%32];
            password += special[rand()%32];
        } else if(input == "0100"){
            password += lowerLetters[rand()%32];
        } else if(input == "0101"){
            password += lowerLetters[rand()%32];
            password += special[rand()%32];
        } else if(input == "0110"){
            password += lowerLetters[rand()%32];
            password += numbers[rand()%32];
        } else if(input == "0111"){
            password += lowerLetters[rand()%32];
            password += numbers[rand()%32];
            password += special[rand()%32];
        } else if(input == "1000"){
            password += upperLetters[rand()%32];
        } else if(input == "1001"){
            password += upperLetters[rand()%32];
            password += special[rand()%32];
        } else if(input == "1010"){
            password += upperLetters[rand()%32];
            password += numbers[rand()%32];
        } else if(input == "1011"){
            password += upperLetters[rand()%32];
            password += numbers[rand()%32];
            password += special[rand()%32];
        } else if(input == "1100"){
            password += upperLetters[rand()%32];
            password += lowerLetters[rand()%32];
        } else if(input == "1101"){
            password += upperLetters[rand()%32];
            password += lowerLetters[rand()%32];
            password += special[rand()%32];
        } else if(input == "1110"){
            password += upperLetters[rand()%32];
            password += lowerLetters[rand()%32];
            password += numbers[rand()%32];
        } else {
            password += upperLetters[rand()%32];
            password += lowerLetters[rand()%32];
            password += numbers[rand()%32];
            password += special[rand()%32];
        }
    }
    return password;
}

void setRequirements(char upper, char lower, char number, char special){
    if(upper == '1'){
        hasUpper = true;
    } if(lower == '1'){
        hasLower = true;
    } if(number == '1'){
        hasNumber = true;
    } if(special == '1'){
        hasSpecial = true;
    }
}

int main(){
    std::cout<<"-----------------------------\n";
    std::cout<<"      Password Generator      \n";
    std::cout<<"------------------------------\n\n";
    std::cout<<"(0/1) A - Z\n";
    std::cout<<"(0/1) a - z\n";
    std::cout<<"(0/1) 0 - 9\n";
    std::cout<<"(0/1) ! \" # $ % & \' ( ) * + , - . / : ; < = > ? @ [ \\ ] ^ _ ` { | } ~ \nOptions: ";
    std::cin>>input;
    std::cout<<"Length: ";
    std::cin>>length;

    if(input.length() == 4 && input != "0000"){
        setRequirements(input[0], input[1], input[2], input[3]);
        std::cout<<"Password: "<<generatePassword(input);
    } else {
        std::cout<<"Invalid parameters.";
    }

    return 0;
}