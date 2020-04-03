#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

void CitireCifre(int[]);
void TreimeNrProdusParitate(int[]);

int main() {
    int x[200];
    int c[200];
    CitireCifre(x);
    TreimeNrProdusParitate(x);
}

void TreimeNrProdusParitate(int x[200]) {
    unsigned long int prodPare = 1;
    unsigned long int prodImpare = 1;

    for (int i = (200 / 3); i <= ((200 /3) * 2); i++) {
        if (i % 2 == 0 && x[i] % 2 == 0) {
            prodPare = prodPare * x[i];
            cout << i << " - " << x[i] << " ProdPare: " << prodPare << endl;
        }

        if (i % 2 != 0 && x[i] % 2 != 0) {
            prodImpare = prodImpare * x[i];
            cout << i << " - " << x[i] << " ProdImpare: " << prodImpare << endl;
        }
    }
    cout << prodPare << " - " << prodImpare << endl;
}

void CitireCifre(int x[200]) {
    ifstream read("Input.txt");
    for (int i = 0; i < 200; i++) {
        read >> x[i];
        cout << i << " - " << x[i] << endl;
    }
}
