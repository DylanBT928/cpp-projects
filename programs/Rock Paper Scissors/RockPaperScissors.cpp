#include <iostream>
#include <ctime>
using namespace std;

int playerTwo()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int oppTurn = rand()%3+1; //Random integer 1-3

    switch (oppTurn)
    {
        case 1:
            cout << "Player 2 chose rock." << endl;
            break;
        case 2:
            cout << "Player 2 chose paper." << endl;
            break;
        case 3:
            cout << "Player 2 chose scissors." << endl;
            break;
        default:
            cout << "Player two is invalid." << endl;
            break;
    }

    return oppTurn;
}

int winner(int p1, int p2)
{
    if(p1 == p2)
        return 0;

    switch(p1)
    {
        /* 1: rock (beats scissors, loses paper)
         * 2: paper (beats rock, loses scissors)
         * 3: scissors (beats paper, loses rock)
         */
        case 1:
            if (p2 == 3)
                return 1;
            return 2;
            break;
        case 2:
            if (p2 == 1)
                return 1;
            return 2;
            break;
        case 3:
            if (p2 == 2)
                return 1;
            return 2;
            break;
        default:
            return -1;
            break;
    }
}

int main()
{
    int rounds = 3;
    int playerOne;
    cout << "How many rounds? ";
    cin >> rounds;
    for (int i = 0; i < rounds; i++)
    {
        cout << "(1)Rock, (2)Paper, (3)Scissors: ";
        cin >> playerOne;
        int game = winner(playerOne, playerTwo());
        if (game == 1)
            cout<<"You won."<<endl;
        else if (game == 2)
            cout << "You lost." << endl;
        else if (game == 0)
            cout << "Tied game." << endl;
        else
            cout << "Invalid game." << endl;
    }

    return 0;
}
