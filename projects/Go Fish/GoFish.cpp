#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
string deck[52] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King",
                   "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King",
                   "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King",
                   "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King",};
void shuffle(){
    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i = 0; i<52; i++){
        swap(deck[i], deck[rand()%52]);
    }
}
void draw(vector<string> hand, int num){
    hand.push_back(deck[num]);
}
void showHand(vector<string> hand){
    cout<<hand[0];
    for(int i = 1; i<hand.size(); i++){
        cout<<", "<<hand[i];
    }
    cout<<'\n';
}
int main(){
    vector<string> playerHand;
    vector<string> dealerHand;
    int bookmark{0};
    shuffle();
    for(int i = 0; i<7; i++){
        draw(playerHand,bookmark);
        draw(dealerHand,bookmark);
        bookmark+=2;
    }
    while(bookmark<=52){
        int guess{};
        showHand(playerHand);
        cout<<"Guess a card: ";
        cin>>guess;












        cout<<"The deck has "<<(52-bookmark)<<" cards left.\n";




        return 0;
    }
}
