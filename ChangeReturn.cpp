#include <iostream>
using namespace std;
int main(){
    int cost;
    string price;
    int quarters, dimes, nickels, pennies;
    cout<<"Enter the cost in pennies: ";
    cin>>cost;
    //Finds how many of each coin can go into the cost
    quarters = cost/25;
    cost%=25;
    dimes = cost/10;
    cost%=10;
    nickels = cost/5;
    cost%=5;
    pennies = cost;
    //Returns amount of change
    cout<<"You need "<<quarters<<" quarters, "<<dimes<<" dimes, "<<nickels<<" nickels, and "<<pennies<<" pennies.";
    return 0;
}
