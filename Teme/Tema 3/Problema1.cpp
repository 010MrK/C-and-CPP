#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

void CitireCifre(int[]);

void VerificareNumerePrime(int[]);

void VerificareCeaMaiMicaSiMaiMareCifra(int[]);

void RasturnareNumere(int[]);

void DivizoriiUnuiNumar(int[]);

int main() {
    int x[200];
    int c[200];
    CitireCifre(x);
    VerificareNumerePrime(x);


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

void RasturnareNumere(int x[200]) {
    int nr, nrNou, pas;
    for (int i = 0; i < 200; i++) {
        nr = x[i];
        nrNou = 0;
        pas = 1;

        while (nr) {
            nrNou = (nrNou * 10) + (nr % 10);//8 ,
            nr = nr / 10;
            cout << "Inversare x[" << i << "] care este: " << nrNou << endl;
        }
        x[i] = nrNou;
        cout << "Afisare matrice inversata:" << endl;
        cout << i << " - " << nrNou << endl;
    }
}

void VerificareCeaMaiMicaSiMaiMareCifra(int x[200]) {
    int cifraMin = INT_MAX;
    int cifraMax = INT_MIN;
    int aux = 0;

    for (int i = 0; i < 200; i++) {
        while (x[i]) {
            aux = x[i] % 10;
            if (aux < cifraMin) {
                cifraMin = aux;
            } else if (aux > cifraMax) {
                cifraMax = aux;
            }
            x[i] = x[i] / 10;
        }
        cout << "Iteratia > " << i << " > Cifra min: " << cifraMin << " > Cifra max: " << cifraMax << endl;
    }

    cout << "Cifra min: " << cifraMin << endl;
    cout << "Cifra max: " << cifraMax << endl;
}

void VerificareNumerePrime(int x[200]) {
    bool flag = false;

    for (int i = 0; i < 200; i++) {
        for (int j = 2; j < x[i]; j++) {
            if (x[i] % j == 0) {
                flag = true;
                break;
            } else {
                flag = false;
            }
        }

        if (flag == false && x[i] > 1) {
            cout << x[i] << " is prime" << endl;
        } else {
            cout << x[i] << " number is not prime" << endl;
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
