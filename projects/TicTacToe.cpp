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

//Continuously checks if game is won yet
bool checkWinStatus(){
    bool winStatus;
    string winner;
    if(flag[1][1]){
        if(flag[1][1]==flag[0][0] && flag[1][1]==flag[2][2] && flag[0][0]==flag[2][2]){
            winStatus = true; //1-5-9
            winner = table[1][1];
        } else if(flag[1][1]==flag[0][2] && flag[1][1]==flag[2][0] && flag[0][2]==flag[2][0]){
            winStatus = true; //3-5-7
            winner = table[1][1];
        } else if(flag[1][1]==flag[1][0] && flag[1][1]==flag[1][2] && flag[1][0]==flag[1][2]){
            winStatus = true; //4-5-6
            winner = table[1][1];
        } else if(flag[1][1]==flag[0][1] && flag[1][1]==flag[2][1] && flag[0][1]==flag[2][1]){
            winStatus = true; //2-5-8
            winner = table[1][1];
        } else {
            winStatus = false;
        }
    } else {
        if(flag[0][0]==flag[0][1] && flag[0][0]==flag[0][2] && flag[0][1]==flag[0][2]){
            winStatus = true; //1-2-3
            winner = table[0][0];
        } else if(flag[0][2]==flag[1][2] && flag[0][2]==flag[2][2] && flag[1][2]==flag[2][2]){
            winStatus = true; //3-6-9
            winner = table[0][2];
        } else if(flag[2][0]==flag[2][1] && flag[2][0]==flag[2][2] && flag[2][1]==flag[2][2]){
            winStatus = true; //7-8-9
            winner = table[2][0];
        } else if(flag[0][0]==flag[1][0] && flag[0][0]==flag[2][0] && flag[1][0]==flag[2][0]){
            winStatus = true; //1-4-7
            winner = table[0][0];
        } else {
            winStatus = false;
        }
    }
    if(winStatus){
        cout<<"The winner is "<<winner<<"!"<<endl;
    }
    return winStatus;
}
//Checks if the game has ended and no one has won
bool gameOver(){
    for(int r = 0; r<sizeof(flag); r++){
        for(int c = 0; c<sizeof(flag[r]); c++){
            if(!flag[r][c]){
                return false;
            }
        }
    }
    return true;
}
//Plays a turn
void playTurn(string player, int location){
    switch(location){
        case 1:
            if(!flag[0][0]){
                table[0][0] = player;
            }
            break;
        case 2:
            if(!flag[0][1]){
                table[0][1] = player;
            }
            break;
        case 3:
            if(!flag[0][2]){
                table[0][2] = player;
            }
            break;
        case 4:
            if(!flag[1][0]){
                table[1][0] = player;
            }
            break;
        case 5:
            if(!flag[1][1]){
                table[1][1] = player;
            }
            break;
        case 6:
            if(!flag[1][2]){
                table[1][2] = player;
            }
            break;
        case 7:
            if(!flag[2][0]){
                table[2][0] = player;
            }
            break;
        case 8:
            if(!flag[2][1]){
                table[2][1] = player;
            }
            break;
        case 9:
            if(!flag[2][2]){
                table[2][2] = player;
            }
            break;
        default:
            gameOver();
            break;
    }
}
int main(){
    bool winStatus = false;
    while(!winStatus){
        bool turnOver = false;
        winStatus = checkWinStatus();
        /*
            reserved to print table
        */
        while(!turnOver && !gameOver){
            int location;
            cout<<"Your turn (X): ";
            cin>>location;
            while(location<1 || location>9){
                cin>>location;
            }
            playTurn("X", location);
            turnOver;
            if(!gameOver){
                playTurn("O",rand()%9+1);
            }
        }
    }
    return 0;
}
