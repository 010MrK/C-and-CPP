#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

void CitireCifre(int[]);

void DivizoriiUnuiNumar(int[]);

int main() {
    int x[200];
    int c[200];
    CitireCifre(x);
    DivizoriiUnuiNumar(x);
}

void DivizoriiUnuiNumar(int x[200]) {
    int k , contor = 0, nrAux = 0;
    cout << "Introduceti k: "; cin >> k;

    for (int i = 0; i < 200; i++) {
        nrAux = x[i];
        contor = 0;

        for (int j = 1; j <= nrAux; j++) {
            if (nrAux % j == 0) {
                contor++;
            }
        }
        if (contor == k) {
            cout << "x[" << i  << "] are: " << contor << " divizori" << endl;
        }
    }
}

void CitireCifre(int x[200]) {
    ifstream read("Input.txt");
    for (int i = 0; i < 200; i++) {
        read >> x[i];
        cout << i << " - " << x[i] << endl;
    }
}
