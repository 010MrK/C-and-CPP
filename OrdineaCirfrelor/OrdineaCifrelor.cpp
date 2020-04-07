#include <iostream>
using namespace std;

int main() {
    int n;
    bool flag = true;

    cout << "Introduceti nr: ";
    cin >> n;

    while (n > 9) {
        if (n / 10 % 10 > n % 10) {
            flag = false;
        }
        n = n / 10;
    }

    if (flag == true) {
            cout << "Cifrele sunt in ordine crescatoare.";
    } else {
        cout << "Cifrele nu sunt in ordine crescatoare";
    }
}