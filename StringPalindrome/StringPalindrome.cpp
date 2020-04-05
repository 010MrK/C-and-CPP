#include <iostream>
using namespace std;

bool checkPalindrome(string);

int main() {

    cout << checkPalindrome("aabcbaa");

    return 0;
}

bool checkPalindrome(string str) {
    bool flag;
    int i, j;
    int n = str.size();

    for(i = 0, j = n - 1; i < j; i++, j--) {

        if(str[i] != str[j]) {
            flag = false;
        } else {
            flag = true;
        }

    }
    return flag;
}