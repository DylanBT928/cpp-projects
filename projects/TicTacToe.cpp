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
bool takenStatus = false;
bool gameOver = false;

//Continuously checks if game is won yet
bool checkWinStatus(){
    bool winStatus = false;
    takenStatus = false;
    string winner;
    if(flag[1][1]){
        if(table[1][1]==table[0][0] && table[1][1]==table[2][2] && table[0][0]==table[2][2]){
            winStatus = true; //1-5-9
            winner = table[1][1];
        } else if(table[1][1]==table[0][2] && table[1][1]==table[2][0] && table[0][2]==table[2][0]){
            winStatus = true; //3-5-7
            winner = table[1][1];
        } else if(table[1][1]==table[1][0] && table[1][1]==table[1][2] && table[1][0]==table[1][2]){
            winStatus = true; //4-5-6
            winner = table[1][1];
        } else if(table[1][1]==table[0][1] && table[1][1]==table[2][1] && table[0][1]==table[2][1]){
            winStatus = true; //2-5-8
            winner = table[1][1];
        } else {
            winStatus = false;
        }
    } else {
        if(table[0][0]==table[0][1] && table[0][0]==table[0][2] && table[0][1]==table[0][2]){
            winStatus = true; //1-2-3
            winner = table[0][0];
        } else if(table[0][2]==table[1][2] && table[0][2]==table[2][2] && table[1][2]==table[2][2]){
            winStatus = true; //3-6-9
            winner = table[0][2];
        } else if(table[2][0]==table[2][1] && table[2][0]==table[2][2] && table[2][1]==table[2][2]){
            winStatus = true; //7-8-9
            winner = table[2][0];
        } else if(table[0][0]==table[1][0] && table[0][0]==table[2][0] && table[1][0]==table[2][0]){
            winStatus = true; //1-4-7
            winner = table[0][0];
        } else {
            winStatus = false;
        }
    }
    if(winStatus){
        cout<<"The winner is "<<winner<<"!"<<endl;
        gameOver;
        exit(0);
    }
    return winStatus;
}
//Checks if the location is not taken
bool valid(int location){
    switch(location){
        case 1:
            return flag[0][0];
            break;
        case 2:
            return flag[0][1];
            break;
        case 3:
            return flag[0][2];
            break;
        case 4:
            return flag[1][0];
            break;
        case 5:
            return flag[1][1];
            break;
        case 6:
            return flag[1][2];
            break;
        case 7:
            return flag[2][0];
            break;
        case 8:
            return flag[2][1];
            break;
        case 9:
            return flag[2][2];
            break;
    }
}
//Player takes the location
void turn(string player, int location){
    switch(location){
        case 1:
            flag[0][0] = true;
            table[0][0] = player;
            break;
        case 2:
            flag[0][1] = true;
            table[0][1] = player;
            break;
        case 3:
            flag[0][2] = true;
            table[0][2] = player;
            break;
        case 4:
            flag[1][0] = true;
            table[1][0] = player;
            break;
        case 5:
            flag[1][1] = true;
            table[1][1] = player;
            break;
        case 6:
            flag[1][2] = true;
            table[1][2] = player;
            break;
        case 7:
            flag[2][0] = true;
            table[2][0] = player;
            break;
        case 8:
            flag[2][1] = true;
            table[2][1] = player;
            break;
        case 9:
            flag[2][2] = true;
            table[2][2] = player;
            break;
    }
}
int main(){
    bool winStatus = false;
    for(int i = 1; i<=9; i++){
        int location;
        if(i%2!=0){
            cout<<"Your turn (X): ";
            cin>>location;
            while(location<1 || location>9){
                cin>>location;
                while(valid(location)){
                    cin>>location;
                }
                turn("X",location);
            }
            winStatus = checkWinStatus();
        } else {
            srand(static_cast<unsigned int>(time(nullptr)));
            int botLocation = rand()%9+1;
            while(valid(botLocation)){
                botLocation = rand()%9+1;
            }
            turn("O", botLocation);
            cout<<"O takes "<<botLocation<<"."<<endl;
            winStatus = checkWinStatus();
        }
    }
    return 0;
}
