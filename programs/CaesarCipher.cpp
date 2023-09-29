#include <iostream>
#include <ctype.h>
using namespace std;

int main(){
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                         'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string option{}, message{}, newmsg{};
    int shift{3};
    cout<<"encrypt or decrypt: ";
    cin>>option;
    cout<<"enter shift value: ";
    cin>>shift;
    cout<<"enter message: ";
    cin>>message;

    if(option.compare("encrypt") == 0){
        //Encryption
    	cout<<"encrypting...\n";
        for(int i = 0; i<message.length(); i++){
            int j = 0;
            while(message.charAt(i)!=alphabet[j] && j<26){
                j++;
                newmsg+=alphabet[j];
            }
            if(!isalpha(message.charAt(i))){
                newmsg+=message[i];
            }
            j = 0;
        }


    } else if(option.compare("decrypt") == 0){
        //Decryption
        cout<<"decrypting...\n";



    } else {
        cout<<"Invalid option."<<endl;
    }






    return 0;
}
