#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    /*
    * The user has 4 tries to guess the number.
    * The secretNum is randomly generated from 1 to 10.
    * srand creates a seed for rand
    * rand creates a random number
    */
    srand(static_cast<unsigned int>(time(nullptr)));
    int guesses = 4, num;
    int secretNum = rand()%10+1;
    cout<<"Guess the number from 1-10 within 4 tries:"<<endl;
    //Keep on trying until there are no more tries or user guesses the right number.
    while(guesses>0){
        cin>>num;
        if(num>10 || num<1){
            //Does not use up a guess
            cout<<"Out of bounds. Try again."<<endl;
        } else if(num<secretNum){
            cout<<"The number is higher."<<endl;
            guesses--;
        } else if(num>secretNum){
            cout<<"The number is lower."<<endl;
            guesses--;
        } else{
            cout<<"Correct! You win."<<endl;
            guesses = 0;
        }
    }
    if(guesses==0 && num!=secretNum){
        cout<<"You lost."<<endl;
    }
    return 0;
}
