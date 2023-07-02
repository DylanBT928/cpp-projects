#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
string deck[52] = {"Ace","1","2","3","4","5","6","7","8","9","Jack","Queen","King",
                   "Ace","1","2","3","4","5","6","7","8","9","Jack","Queen","King",
                   "Ace","1","2","3","4","5","6","7","8","9","Jack","Queen","King",
                   "Ace","1","2","3","4","5","6","7","8","9","Jack","Queen","King",};
int bookmark{0};
void shuffle(){
    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i = 0; i<52; i++){
        swap(deck[i], deck[rand()%52]);
    }
}
void draw(vector<string> hand){
    hand.push_back(deck[bookmark]);
    bookmark++;
}
bool isGameOver(){
    return bookmark>52;
}
int main(){
    //shuffle();
    vector<string> playerHand;
    vector<string> dealerHand;
    for(int i = 0; i<7; i++){
        draw(playerHand);
        draw(dealerHand);
    }
    while(!isGameOver){
        
    }
}
