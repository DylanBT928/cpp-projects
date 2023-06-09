#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Tic-Tac-Toe tables
string table[3][3] = {{"1","2","3"},
                      {"4","5","6"},
                      {"7","8","9"}};
bool flag[3][3] = {{false,false,false},
                   {false,false,false},
                   {false,false,false}};
bool winStatus = false;

int row(int r){
    if(1<=r && r<=3){
        return 0;
    } else if(4<=r && r<=6){
        return 1;
    } else if(7<=r && r<=9){
        return 2;
    } else {
        cout<<"Invalid, try again."<<endl;
        return -1;
    }
}
int col(int c){
    if(c==1 || c==4 || c==7){
        return 0;
    } else if(c==2 || c==5 || c==8){
        return 1;
    } else if(c==3 || c==6 || c==9){
        return 2;
    } else {
        cout<<"Invalid, try again."<<endl;
        return -1;
    }
}
bool isValid(int r, int c){
    return (flag[r][c]==false);
}

bool isWon(){

}

void turn(){

}

int main(){
    
}
