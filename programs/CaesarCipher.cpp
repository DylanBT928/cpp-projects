#include <iostream>
#include <ctype.h>
using namespace std;

int main(){
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                         'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string message{}, newmsg{};
    int option{1}, shift{3};
    cout<<"(1) encrypt or (2) decrypt: ";
    cin>>option;
    cout<<"enter shift value: ";
    cin>>shift;
    cout<<"enter message: ";
    cin>>message;

    switch(option){
        case 1:
            //Encryption
            cout<<"encrypting...\n";
            for(int i = 0; i<message.length(); i++){
                int j = 0;
                while(message.at(i)!=alphabet[j] && j<26){
                    j++;
                }
                if(isalpha(message.at(i))){
                    if(j+shift<26){
                        newmsg+=alphabet[j+shift];
                    } else {
                        newmsg+=alphabet[j+shift-26];
                    }
                } else {
                    newmsg+=message[i];
                }
                j = 0;
            }
            cout<<newmsg;
            break;
        case 2:
            //Decryption
            cout<<"decrypting...\n";
            for(int i = 0; i<message.length(); i++){
                int j = 0;
                while(message.at(i)!=alphabet[j] && j<26){
                    j++;
                }
                if(isalpha(message.at(i))){
                    if(j-shift<26){
                        newmsg+=alphabet[j-shift];
                    } else {
                        newmsg+=alphabet[j-shift+26];
                    }
                } else {
                    newmsg+=message[i];
                }
                j = 0;
            }
            cout<<newmsg;
            break;
        default:
            cout<<"Invalid option."<<endl;
            break;
    }
    return 0;
}
