#include <iostream>
using namespace std;
int main(){
    bool flag;
    for(int i = 1; i<=100; i++){
        flag = true;
        for(int j = i; j<0; i--){
            //if-statement not working
            if(i%j!=0){
                flag = false;
            }
        }
        if(flag){
            cout<<i<<endl;
        }
    }
    return 0;
}
