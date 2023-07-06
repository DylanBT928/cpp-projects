#include <iostream>
#include <vector>
#include <ctime>
#include <string>
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
    for(int i = 0; i<hand.size(); i++){
        cout<<hand[i]<<" ";
    }
    cout<<'\n';
}
int isValid(vector<string> hand, string card){
    for(int i = 0; i<52; i++){
        if(hand[i]==card){
            return i;
        }
    }
    return -1;
}
bool isBook(vector<string> hand, string card){
    int count{};
    int book[4]{};
    bool flag{false};
    for(int i = 0; i<hand.size(); i++){
        if(hand[i]==card){
            book[count] = i;
            count++;
        }
    }
    for(int j = 0; j<4; j++){
        hand.erase(hand.begin()+book[j]);
    }
    return count == 4;
}
int main(){
    vector<string> playerHand;
    vector<string> dealerHand;
    int playerPairs{};
    int dealerPairs{};
    int bookmark{};
    shuffle();
    for(int i = 0; i<7; i++){
        draw(playerHand,bookmark);
        draw(dealerHand,bookmark);
        bookmark+=2;
    }
    while(bookmark<=52){
        string guess{};
        showHand(playerHand);
        cout<<"Guess a card: "; //case-sensitive
        cin>>guess;
        //player's turn
        while(isValid(dealerHand, guess)!=-1 && bookmark<=52){
            if(isBook(playerHand, guess)){
                playerPairs++;
            }
            draw(playerHand, isValid(dealerHand, guess));
            cout<<"Guess another card: ";
            cin>>guess;
        }
        if(isValid(dealerHand, guess)==-1){
            cout<<"Dealer does not have a "<<guess<<".\n";
        }
        //dealer turn
        if(bookmark<=52){
            /*
             *
             * Unfinished
             * 
             */
        }
        cout<<"Your pairs: "<<playerPairs<<"\tBot's pairs: "<<dealerPairs<<'\n';
        cout<<"The deck has "<<(52-bookmark)<<" cards left.\n";
    }
    cout<<"Game over."<<endl;
    return 0;
}
