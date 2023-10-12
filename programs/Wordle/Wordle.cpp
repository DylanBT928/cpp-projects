#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <Windows.h>

const int LENGTH = 5;

std::vector<std::string> readSolutions(int length){
    std::string line;
    std::vector<std::string> vec;
    std::ifstream fin;
    fin.open("./programs/Wordle/Solutions.txt");
    while(getline(fin, line)){
        if(line.length() == length){
        vec.push_back(line);
        }
    }
    fin.close();
    return vec;
}

std::vector<std::string> readGuesses(int length){
    std::string line;
    std::vector<std::string> vec;
    std::ifstream fin;
    fin.open("./programs/Wordle/Guesses.txt");
    while(getline(fin, line)){
        if(line.length() == length){
        vec.push_back(line);
        }
    }
    fin.close();
    return vec;
}

std::string chooseRandomWord(std::vector<std::string> vec){
    auto iterator = vec.begin();
    int randomNum = rand()%vec.size();
    advance(iterator, randomNum);
    return iterator[0];
}

char getNthLetter(int n){
    return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n-1];
}

int getNumFromChar(char x){
    return ((int)x)-64;
}

std::string checkWord(std::string text, std::string correct, int len){
    std::string out;
    for(int i = 0; i<len; i++){
        char text_char = text[i];
        char correct_char = text[i];
  
    //continue here
  
  
  
  
    }
    return out;
}






int main(){
  
  
    std::vector<std::string> allSolutions =  readSolutions(LENGTH);
  
    return 0;
}
