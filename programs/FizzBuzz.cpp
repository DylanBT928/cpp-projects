#include <iostream>
using namespace std;
int main(){
    //For-Loop counts from 1 to 100
    for(int i = 1; i<=100; i++){
        if(i%3==0 && i%5==0){
            cout<<"FizzBuzz"<<endl; //Prints FizzBuzz if the number is divisible by 3 and 5
        } else {
            if(i%3==0){
                cout<<"Fizz"<<endl; //Prints Fizz if the number is only divisible by 3
            } else if (i%5==0){
                cout<<"Buzz"<<endl; //Prints Buzz if the number is only divisible by 5
            } else {
                cout<<i<<endl; //Prints the number if the number is not divisible by 3 or 5
            }
        }
    }
    return 0;
}
