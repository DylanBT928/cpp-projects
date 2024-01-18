#include <iostream>
#include <ctype.h>

std::string secretWord, hidden, usedLetters;
char letter;

//Converts the secret word into a blank
std::string hide (std::string secret)
{
    std::string hidden{""};
    for (int i = 0; i < secret.length(); i++)
        if (secret.at(i) == ' ')
            hidden += " ";
        else if (isalpha(secret.at(i)))
            hidden += "_";
        else
            hidden += secret.at(i);
    return hidden;
}

//Checks if the letter is in the word
bool isValid(char l)
{
    if (secretWord.find(l) != -1)
    {
        usedLetters += l;
        return true;
    }
    return false;
}

//Checks if the letter has already been guessed
bool isUsed(char l)
{
    return usedLetters.find(l) != -1;
}

//Reveals the letter(s) in the word
std::string reveal(char l)
{
    for (int i = 0; i < secretWord.length(); i++)
        if (secretWord.at(i) == l)
            hidden.at(i) = l;
    return hidden;
}

int main()
{
    //6 guesses (head, torso, two arms, two legs)
    int guesses = 6;

    std::cout << "Please enter a word: ";
    std::cin >> secretWord;

    //Converts inputted word/phrase into a blank word/phrase
    hidden = hide(secretWord);
    std::cout << hidden<<'\n';

    //Loops while there are guesses left and not won
    while (guesses > 0 && secretWord != hidden)
    {
        std::cout << "Guess a letter: ";
        std::cin >> letter;

        //If the letter is already used, it does not take a guess nor reveal anything
        if (isUsed(letter) || isUsed(toupper(letter)))
            std::cout<<"Letter is already used.\n";
        //If the letter is in the secret word, it is revealed
        else if (isValid(letter) || isValid(toupper(letter)))
        {
            reveal(letter);
            reveal(toupper(letter));
            std::cout<<hidden<<'\n';
        } 
        //If it is not used and not in the secret word, a guess is taken
        else 
        {
            guesses--;
            //Prints how many guesses the user has left
            std::cout << "You have " << guesses << " guesses left." << '\n';
        }
    }

    //States if user won or lost
    if (secretWord == hidden)
        std::cout << "Congratulations, you win!" << std::endl;
    else
        std::cout << "Sorry, you lost." << std::endl;
    
    return 0;
}
