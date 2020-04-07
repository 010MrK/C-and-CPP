#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

void FunctieAfisare(int[], int);
void CitireCifre(int[], int&);
void SumaElementelorUnuiVector(int[], int);         //P1
void CautareaElementuluiMinim(int[], int);          //P2
void OrdineaCrescatoareSauDesc(int[], int);         //P3

int main() {
    int x[200];
    int n;
    CitireCifre(x, n);
    // SumaElementelorUnuiVector(x, n);
    // CautareaElementuluiMinim(x, n);
    // OrdineaCrescatoareSauDesc(x, n);
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

void CitireCifre(int x[], int&n) {
    ifstream read("Input.txt");
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