#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

void FunctieAfisare(int[], int);
void CitireCifreInputUnu(int[], int&);
void CitireCifreInputDoi(int[], int&);
void SumaElementelorUnuiVector(int[], int);         //P1
void CautareaElementuluiMinim(int[], int);          //P2
void OrdineaCrescatoareSauDesc(int[], int);         //P3
void OrdonareCrescatoareSortareLiniara(int[], int); //P4
void OrdonareCrescatoareSortareBubble(int[], int); //P5

int main() {
    int x[200];
    int y[200];
    int nX;
    int nY;
    CitireCifreInputUnu(x, nX);
    CitireCifreInputDoi(y, nY);
    // SumaElementelorUnuiVector(x, n);
    // CautareaElementuluiMinim(x, n);
    // OrdineaCrescatoareSauDesc(x, n);
    // OrdonareCrescatoareSortareLiniara(x, n);
    // OrdonareCrescatoareSortareBubble(x, n);
}

void OrdonareCrescatoareSortareBubble(int x[], int n) {
    int flag = 0;
    do
    {
        flag = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (x[i] > x[i + 1])
            {
                swap(x[i], x[i + 1]);
                flag = 1;
            }

        }

    } while (flag == 1);
    FunctieAfisare(x, n);
}

void OrdonareCrescatoareSortareLiniara(int x[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (x[i] > x[j]) {
                swap(x[i], x[j]);
            }
        }
    }
    FunctieAfisare(x, n);
}

void OrdineaCrescatoareSauDesc(int x[], int n) {
    bool ordineC = false;// = true;
    bool ordineD = false;
    for (int i = 0; i < n - 1; i++) {
        if (x[i] < x[i + 1])
            ordineC = true;
        else {
            ordineC = false;
            break;
        }
    }

    if (ordineC == false) {
        for (int i = 0; i < n - 1; i++) {
            if (x[i] > x[i + 1])
                ordineD = true;
            else {
                ordineD = false;
                break;
            }
        }
    }

    if (ordineC == false && ordineD == false) {
        cout << " Numerele nu sunt in ordine" << endl;
    }
    else if (ordineC == true)
        cout << "Numerele sunt in ordine crescatoare" << endl;
    else if (ordineD == true)
        cout << "Numerele sunt in ordine descrescatoare" << endl;
}



void CautareaElementuluiMinim(int x[], int n) {
    int elementulMinim = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (x[i] < elementulMinim)
            elementulMinim = x[i];
    }
    cout << "Elementul minim din vector este: " << elementulMinim;
}

void SumaElementelorUnuiVector(int x[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma = suma + x[i];
    }
    cout << "Suma elementelor din vector este: " << suma;
}

void CitireCifreInputUnu(int x[], int&n) {
    ifstream read("Input.txt");
    read >> n;
    for (int i = 0; i < n; i++) {
        read >> x[i];
    }
    FunctieAfisare(x, n);
}

void CitireCifreInputDoi(int x[], int&n) {
    ifstream read("Input2.txt");
    read >> n;
    for (int i = 0; i < n; i++) {
        read >> x[i];
    }
    FunctieAfisare(x, n);
}

void FunctieAfisare(int x[], int d) {
    cout << endl;
    for (int i = 0; i < d; i++)
        cout << x[i] << "\t";
    cout << endl;
}