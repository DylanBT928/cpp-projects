#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;
string deck[52] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King",
                   "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King",
                   "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King",
                   "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King",};
string oneOfEachCard[13] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
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
        string playerGuess{};
        showHand(playerHand);
        cout<<"Guess a card: "; //case-sensitive
        cin>>playerGuess;
        //player's turn
        while(isValid(dealerHand, playerGuess)!=-1 && bookmark<=52){
            draw(playerHand, isValid(dealerHand, playerGuess));
            if(isBook(playerHand, playerGuess)){
                playerPairs++;
            }
            cout<<"Guess another card: ";
            cin>>playerGuess;
        }
        if(isValid(dealerHand, playerGuess)==-1){
            cout<<"Dealer does not have a "<<playerGuess<<".\n";
        }
        //dealer turn
        if(bookmark<=52){
            string dealerGuess{oneOfEachCard[rand()%13+1]};
            while(isValid(playerHand, dealerGuess)!=-1 && bookmark<=52){
                draw(dealerHand, isValid(playerHand, dealerGuess));
                if(isBook(dealerHand, dealerGuess)){
                    dealerPairs++;
                }
            }
        }
        cout<<"Your pairs: "<<playerPairs<<"\tBot's pairs: "<<dealerPairs<<'\n';
        cout<<"The deck has "<<(52-bookmark)<<" cards left.\n";
    }
    cout<<"Game over."<<endl;
    return 0;
}
