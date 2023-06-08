#include <iostream>
using namespace std;
int main(){
    double cost;
    string price;
    int quarters, dimes, nickels, pennies;
    cout<<"Enter the cost: ";
    cin>>cost;
    //Finds how many of each coin can go into the cost
    quarters = cost/0.25;
    cost-=quarters*0.25;
    dimes = cost/0.10;
    cost-=dimes*0.10;
    nickels = cost/0.05;
    cost-=nickels*0.05;
    pennies = cost*100;
    //Returns amount of change
    cout<<"You need "<<quarters<<" quarters, "<<dimes<<" dimes, "<<nickels<<" nickels, and "<<pennies<<" pennies.";
    return 0;
}
