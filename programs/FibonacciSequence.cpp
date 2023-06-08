#include <iostream>
using namespace std;
int main(){
    //sequence starts with 0 and 1
    int x = 0;
    int y = 1;
    int z = x + y;
    int nth;
    cout<<"nth digit: ";
    cin>>nth;
    switch(nth){
        case 0: 
            cout<<"Nothing is printed.";
            break;
        case 1:
            cout<<"0";
            break;
        case 2:
            cout<<"0, 1";
            break;
        default:
            cout<<"0, 1";
            while(nth>2){
                cout<<", "<<z;
                x = y;
                y = z;
                z = x + y;
                nth--;
            }
            break;
    }
}
