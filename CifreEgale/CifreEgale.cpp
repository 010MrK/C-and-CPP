#include <iostream>
using namespace std;

int main() {
    int n, c;
    bool flag = true;

    cout << "Introduceti numarul: ";
    cin >> n;

    c = n % 10;
    n = n / 10;

    while (n != 0) {
        if (n % 10 != c) {
            flag = false;
        }
        n = n / 10;
    }

    if (flag == true) {
        cout << "Cifrele sunt egale!";
    } else {
        cout << "Cifrele nu sunt egale!";
    }
}