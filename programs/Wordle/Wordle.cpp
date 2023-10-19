#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>

const int WORD_LENGTH{5};
const int NOT_MATCH{0};
const int PARTIAL_MATCH{1};
const int MATCH{2};
const int NUMBER_OF_TRIES{6};

void toUpperCase(std::string &input){
    std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c){return std::toupper(c);});
}

std::string getRandomWord(){
    //TODO: API or .txt files to get word
    return "ready";
}

bool isValid(std::string word){
    //TODO: API or .txt files to validate word
    return word.length() == WORD_LENGTH && word.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos;
}

void markMatches(std::vector<std::vector<int>> &matches, int tryIndex, std::string target, std::string guess){
    for(int i = 0; i < guess.length(); i++){
        matches[tryIndex][i] = NOT_MATCH;
    }

    for(int i = 0; i < guess.length(); i++){
        for(int j = 0; j < target.length(); j++){
            if(guess[i] == target[j]){
                if(i == j){
                    matches[tryIndex][i] = MATCH;
                    break;
                } else {
                    matches[tryIndex][i] = PARTIAL_MATCH;
                }
            }
        }
    }
}

bool isAllMatched(std::string target, std::string guess){
    for(int i = 0; i < target.length(); i++){
        if(target[i] != guess[i]){
            return false;
        }
    }
    return true;
}

void printWordle(std::vector<std::vector<int>> matches, std::vector<std::string> guesses, int tryIndex){
    system("cls");
    std::cout<<"================================================================="<<std::endl;
    std::cout<<"|                                                               |"<<std::endl;
    std::cout<<"|   $$\\      $$\\                           $$\\ $$\\              |"<<std::endl;
    std::cout<<"|   $$ | $\\  $$ |                          $$ |$$ |             |"<<std::endl;
    std::cout<<"|   $$ |$$$\\ $$ | $$$$$$\\   $$$$$$\\   $$$$$$$ |$$ | $$$$$$\\     |"<<std::endl;
    std::cout<<"|   $$ $$ $$\\$$ |$$  __$$\\ $$  __$$\\ $$  __$$ |$$ |$$  __$$\\    |"<<std::endl;
    std::cout<<"|   $$$$  _$$$$ |$$ /  $$ |$$ |  \\__|$$ /  $$ |$$ |$$$$$$$$ |   |"<<std::endl;
    std::cout<<"|   $$$  / \\$$$ |$$ |  $$ |$$ |      $$ |  $$ |$$ |$$   ____|   |"<<std::endl;
    std::cout<<"|   $$  /   \\$$ |\\$$$$$$  |$$ |      \\$$$$$$$ |$$ |\\$$$$$$$\\    |"<<std::endl;
    std::cout<<"|   \\__/     \\__| \\______/ \\__|       \\_______|\\__| \\_______|   |"<<std::endl;
    std::cout<<"|                                                               |"<<std::endl;
    std::cout<<"================================================================="<<std::endl;

    for(int i = 0; i <= tryIndex && i < guesses.size(); i++){
        std::string separator{"-"};
        std::string padding{"|"};
        std::string text{"|"};

        for(int j = 0; j < guesses[i].length(); j++){
            separator += "------";
            padding += "     |";
            char value = std::toupper(guesses[i][j]);
            text += "  ";
            if(matches[i][j] == PARTIAL_MATCH){
                text += "\033[33m";
            } else if(matches[i][j] == MATCH){
                text += "\033[32m";
            }

            text += value;

            if(matches[i][j] == PARTIAL_MATCH || matches[i][j] == MATCH){
                text += "\033[0m";
            }

            text += "  |";
        }

        if(i == 0){
            std::cout<<separator<<std::endl;
        }

        std::cout<<padding<<std::endl;
        std::cout<<text<<std::endl;
        std::cout<<padding<<std::endl;
        std::cout<<separator<<std::endl;
    }
}

int main(){
    std::vector<std::string> tries(NUMBER_OF_TRIES);
    std::vector<std::vector<int>> matches(NUMBER_OF_TRIES, std::vector<int>(WORD_LENGTH));
    std::string targetWord = getRandomWord();
    toUpperCase(targetWord);
    std::string input{};
    int currentGuesses = 0;

    printWordle(matches, tries, -1);

    while(currentGuesses < NUMBER_OF_TRIES){
        do{
            std::cout<<"Please enter your guess (word length must be " + std::to_string(WORD_LENGTH) + ") or type Q/q to quit: ";
            std::getline(std::cin, input);
            toUpperCase(input);
        } while(input != "Q" && !isValid(input));

        if(input == "Q"){
            std::cout<<"Quit game."<<std::endl;
            break;
        }

        tries[currentGuesses] = input;
        markMatches(matches, currentGuesses, targetWord, input);
        printWordle(matches, tries, currentGuesses);

        if(isAllMatched(targetWord, input)){
            std::cout<<"You win!"<<std::endl;
            break;
        }
        
        currentGuesses++;
    }

    return 0;
}
