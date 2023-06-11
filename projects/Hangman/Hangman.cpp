#include <iostream>
using namespace std;
string secretWord{}, hidden{}, usedLetters{};
char letter{};

//Converts the secret word into a blank
string hide(string secret){

}

//Checks if the letter is in the word
bool isValid(char l){
    
}

//Reveals the letter(s) in the word
string reveal(char l){

}

int main(){
    int guesses = 6;
    cout<<"Please enter a word: ";
    cin>>secretWord;
    hidden = hide(secretWord);
    while(guesses>0 && secretWord!=hidden){
        cout<<"Guess a letter: ";
        cin>>letter;
        if(isValid(letter)){
            cout<<reveal(letter)<<'\n';
        } else {
            guesses--;
        }
    }
    if(secretWord==hidden){
        cout<<"Congratulations, you win!"<<endl;
    } else {
        cout<<"Sorry, you lost."<<endl;
    }
    return 0;
}
