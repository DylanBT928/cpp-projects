#include <iostream>
#include <string>
using namespace std;
int main(){
    int num{};
    string factors{"1"};
    cout<<"Enter a positive integer: ";
    cin>>num;
    for(int i = 2; i<=num; i++){
        if(num%i==0){
            factors+=", "+to_string(i);
        }
    }
    if(factors!=("1, "+to_string(num))){
        cout<<"Factors: "<<factors<<endl;
    } else {
        cout<<"Prime number (divisible only by 1 and itself)"<<endl;
    }
    return 0;
}
