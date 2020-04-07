#include <iostream>
using namespace std;

bool checkIfPalindrome(string);

int main() {
    
    cout << checkIfPalindrome("aabaa");
    
    return 0;
}

bool checkIfPalindrome (string str) {

    int i;                  //pozitie stanga caracter
    int j;                  // pozitie dreapta caracter
    int n = str.size();     //dimensiune cuvant
    bool flag;              //verificare palindrome

    for(i = 0, j = n - 1; i < j; i++, j--) {
        
        if(str[i] != str[j]) {
            flag = false;;
            break;
        }
        else {
            flag = true;
        } 
    }

    return flag;
}