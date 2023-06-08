#include <iostream>
#include <cmath>
using namespace std;
int main(){
    //Variables to allow the user to choose math operation and numbers
    char op;
    double num1, num2;
    cout<<"Enter two numbers: "<<endl;
    cin>>num1>>num2;
    cout<<"Choose an operation: \"+, -, *, /, ^\""<<endl;
    cin>>op;
    //Switch statement to choose which operation to use, depending on what user sets op equal to
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
            //Prints this if op is not equal to any of the previous cases
            cout<<"Unknown operator. Please try again.";
    }
    return 0;
}
