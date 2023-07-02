/* This program uses the Luhn algorithm (aka the Modulus 10 
 * algorithm) to determine whether the identification number 
 * provided by a user is accurate. The algorithm is most 
 * notably used in credit cards, IMEI, or SSN.
 */
#include <iostream>
using namespace std;
//Uses Luhn algorithm to validate number
bool isValid(long long num){
    int arr[(to_string(num).length())] = {};
    int sum{};
    for(int i = (sizeof(arr)/sizeof(int))-1; i>=0; i--){
        arr[i] = num%10;
        num/=10;
    }
    for(int j = 0; j<sizeof(arr)/sizeof(int); j+=2){
        arr[j]*=2;
        if(arr[j]>=10){
            arr[j] = arr[j]/10 + arr[j]%10;
        }
    }
    for(int k = 0; k<sizeof(arr)/sizeof(int); k++){
        sum+=arr[k];
    }
    return sum%10==0;
}
int main(){
    long long input{};
    cout<<"Enter number: ";
    cin>>input;
    if(isValid(input)){
        cout<<input<<" is valid."<<endl;
    } else {
        cout<<input<<" is not valid."<<endl;
    }
    return 0;
}
