#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
string deck[52] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King",
                   "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King",
                   "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King",
                   "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King",};
int bookmark{0};
void shuffle(){
    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i = 0; i<52; i++){
        swap(deck[i], deck[rand()%52]);
    }
}
void draw(vector<string> hand, int card){
    hand.push_back(deck[card]);
    bookmark++;
}
void showHand(vector<string> hand){
    cout<<hand[0];
    for(int i = 1; i<hand.size(); i++){
        cout<<", "<<hand[i];
    }
    cout<<'\n';
}
bool isGameOver(){
    return bookmark>52;
}
int main(){
    vector<string> playerHand;
    vector<string> dealerHand;
    shuffle();
    for(int i = 0; i<14; i+=2){
        draw(playerHand,i);
        draw(dealerHand,i++);
    }
    while(!isGameOver){
        int guess{};
        showHand(playerHand);
        cout<<"Guess a card: ";
        cin>>guess;












        cout<<"The deck has "<<(52-bookmark)<<" cards left.\n";




        return 0;
    }
}
