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
string winner;

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
    if(r==-1 || c==-1){
        cout<<"Out of bounds, try again."<<endl;
        return false;
    }
    if(flag[r][c]==true){
        cout<<"Taken, try again."<<endl;
    }
    return true;
}
bool isWon(){
    if(table[1][1]==table[0][0] && table[1][1]==table[2][2] && table[0][0]==table[2][2] && flag[1][1]==true){
        winner = table[1][1]; //1-5-9
    } else if(table[1][1]==table[0][2] && table[1][1]==table[2][0] && table[0][2]==table[2][0] && flag[1][1]==true){
        winner = table[1][1]; //3-5-7
    } else if(table[1][1]==table[1][0] && table[1][1]==table[1][2] && table[1][0]==table[1][2] && flag[1][1]==true){
        winner = table[1][1]; //4-5-6
    } else if(table[1][1]==table[0][1] && table[1][1]==table[2][1] && table[0][1]==table[2][1] && flag[1][1]==true){
        winner = table[1][1]; //2-5-8
    } else if(table[0][0]==table[0][1] && table[0][0]==table[0][2] && table[0][1]==table[0][2] && flag[0][0]==true){
        winner = table[0][0]; //1-2-3
    } else if(table[0][2]==table[1][2] && table[0][2]==table[2][2] && table[1][2]==table[2][2] && flag[0][2]==true){
        winner = table[0][2]; //3-6-9
    } else if(table[2][0]==table[2][1] && table[2][0]==table[2][2] && table[2][1]==table[2][2] && flag[2][0]==true){
        winner = table[2][0]; //7-8-9
    } else if(table[0][0]==table[1][0] && table[0][0]==table[2][0] && table[1][0]==table[2][0] && flag[0][0]==true){
        winner = table[0][0]; //1-4-7
    } else {
        return false;
    } return true;
}

void turn(string player, int location){
    flag[row(location)][col(location)] = true;
    table[row(location)][col(location)] = player;
}

int main(){
    srand(static_cast<unsigned int>(time(nullptr)));
    int location{};
    for(int i = 1; i<=9; i++){
        while(!isWon()){
            if(i%2!=0){
                cout<<"Your turn (X): ";
                cin>>location;
                while(!isValid(row(location), col(location))){
                    cin>>location;
                }
                turn("X", location);
            } else {
                int botLocation = rand()%9+1;
                while(!isValid(row(botLocation), col(botLocation))){
                    botLocation = rand()%9+1;
                }
                turn("O", botLocation);
                cout<<"O takes "<<botLocation<<"."<<endl;
            }
            if(isWon()){
                cout<<winner<<" has won!"<<endl;
            }
        }
    }
    return 0;
}
