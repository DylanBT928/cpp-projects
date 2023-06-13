#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
string secretWord{}, hidden, usedLetters{};
char letter{};

//Converts the secret word into a blank
string hide(string secret){
    string hidden{""};
    for(int i = 0; i<secret.length(); i++){
        if(secret.at(i)==' '){
            hidden+=" ";
        } else if(isalpha(secret.at(i))){
            hidden+="_";
        } else {
            hidden+=secret.at(i);
        }
    }
    return hidden;
}

//Checks if the letter is in the word
bool isValid(char l){
    if(secretWord.find(l)!=-1){
        usedLetters+=l;
        return true;
    }
    return false;
}

//Checks if the letter has already been guessed
bool isUsed(char l){
    return usedLetters.find(l)!=-1;
}

//Reveals the letter(s) in the word
string reveal(char l){
    for(int i = 0; i<secretWord.length(); i++){
        if(secretWord.at(i)==l){
            hidden.at(i)=l;
        }
    }
    return hidden;
}


int main(){
    int guesses = 6;
    cout<<"Please enter a word: ";
    cin>>secretWord;
    hidden = hide(secretWord);
    cout<<hidden<<'\n';
    while(guesses>0 && secretWord!=hidden){
        cout<<"Guess a letter: ";
        cin>>letter;
        if(isUsed(letter)){
            cout<<"Letter is already used.\n";
        } else if(isValid(letter)){
            cout<<reveal(letter)<<'\n';
        } else {
            guesses--;
            cout<<"You have "<<guesses<<" guesses left."<<'\n';
        }
    }
    if(secretWord==hidden){
        cout<<"Congratulations, you win!"<<endl;
    } else {
        cout<<"Sorry, you lost."<<endl;
    }
    return 0;
}
