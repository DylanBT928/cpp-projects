#include <iostream>
#include <ctime>
using namespace std;
string deck[52] = {"Ace","1","2","3","4","5","6","7","8","9","Jack","Queen","King",
                   "Ace","1","2","3","4","5","6","7","8","9","Jack","Queen","King",
                   "Ace","1","2","3","4","5","6","7","8","9","Jack","Queen","King",
                   "Ace","1","2","3","4","5","6","7","8","9","Jack","Queen","King",};
void shuffle(){
    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i = 0; i<52; i++){
        swap(deck[i], deck[rand()%52]);
    }
}
int main(){
    shuffle();
}
