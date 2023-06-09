#include <iostream>
#include <cstdlib>
using namespace std;

//Tic-Tac-Toe tables
string table[3][3] = {{"1","2","3"},
                      {"4","5","6"},
                      {"7","8","9"}};
bool flag[3][3] = {{false,false,false},
                   {false,false,false},
                   {false,false,false}};
bool takenStatus = false;

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
        return 0;
    }
    return winStatus;
}
//Plays a turn
void playTurn(string player, int location){
    string taken = "This is taken.";
    switch(location){
        case 1:
            if(!flag[0][0]){
                table[0][0] = player;
            } else {
                cout<<taken;
                takenStatus = true;
            }
            break;
        case 2:
            if(!flag[0][1]){
                table[0][1] = player;
            } else {
                cout<<taken;
                takenStatus = true;
            }
            break;
        case 3:
            if(!flag[0][2]){
                table[0][2] = player;
            } else {
                cout<<taken;
                takenStatus = true;
            }
            break;
        case 4:
            if(!flag[1][0]){
                table[1][0] = player;
            } else {
                cout<<taken;
                takenStatus = true;
            }
            break;
        case 5:
            if(!flag[1][1]){
                table[1][1] = player;
            } else {
                cout<<taken;
                takenStatus = true;
            }
            break;
        case 6:
            if(!flag[1][2]){
                table[1][2] = player;
            } else {
                cout<<taken;
                takenStatus = true;
            }
            break;
        case 7:
            if(!flag[2][0]){
                table[2][0] = player;
            } else {
                cout<<taken;
                takenStatus = true;
            }
            break;
        case 8:
            if(!flag[2][1]){
                table[2][1] = player;
            } else {
                cout<<taken;
                takenStatus = true;
            }
            break;
        case 9:
            if(!flag[2][2]){
                table[2][2] = player;
            } else {
                cout<<taken;
                takenStatus = true;
            }
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
            while(location<1 || location>9 || takenStatus){
                cin>>location;
            }
            playTurn("X", location);
            winStatus = checkWinStatus();
        } else {
            int botLocation = rand()%9+1;
            while(takenStatus){
                botLocation = rand()%9+1;
                playTurn("O", botLocation);
            }
            cout<<"O takes "<<botLocation<<"."<<endl;
            winStatus = checkWinStatus();
        }
    }
    return 0;
}
