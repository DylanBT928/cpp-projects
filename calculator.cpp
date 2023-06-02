#include <iostream>
#include <cmath>
using namespace std;
int main(){
    char op;
    double num1, num2;
    cout<<"Enter two numbers: "<<endl;
    cin>>num1>>num2;
    cout<<"Choose an operation: \"+, -, *, /, ^\""<<endl;
    cin>>op;
    switch(op){
        case '+':
            cout<<num1<<" + "<<num2<<" = "<<num1+num2;
            break;
        case '-':
            cout<<num1<<" - "<<num2<<" = "<<num1-num2;
            break;
        case '*':
            cout<<num1<<" * "<<num2<<" = "<<num1*num2;
            break;
        case '/':
            cout<<num1<<" / "<<num2<<" = "<<num1/num2;
            break;
        case '^':
            cout<<num1<<" ^ "<<num2<<" = "<<pow(num1,num2);
            break;
        default:
            cout<<"Unknown operator. Please try again.";
    }
    return 0;
}
