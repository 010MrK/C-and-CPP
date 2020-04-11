#include <iostream>
#include <algorithm>
#include <fstream>
#include<cstdlib>
using namespace std;

void CitireCifre(int[], int&);
void FunctieAfisare(int[], int);
void Sortare(int[], int);
void BubbleSort(int[], int);
void Stergere(int[], int&,int p);
void Introducere(int[], int&, int, int);
void FrecventaPeCifre(int);
void FrecventaPeNumar(int[], int);
int CautareaLiniara(int[], int, int);
int CautareaBinara(int[], int, int);

int main() {
    int x[200];
    int n;
    CitireCifre(x, n);
    //Sortare(x, n);
    //BubbleSort(x, n);
    //Stergere(x, n,1);
    //Introducere(x, n, 1, 11);
    //FrecventaPeCifre(77731221);
    //FunctieAfisare(x, n);
    
    //FrecventaPeNumar(x, n);

    cout << CautareaBinara(x, n, 22);
}

int CautareaBinara(int x[], int n, int key) {
    int a = 0;
    int b = n - 1;
    int mijl;

    while (a <= b)
    {
        mijl = (a + b) / 2;

        if (x[mijl] == key)
            return mijl;
        else {
            if (key > x[mijl])
                a = mijl + 1;
            else
                b = mijl - 1;
        }
    }
    return -1;
}

int CautareaLiniara(int x[], int n, int a) {
    for (int i = 0; i < n; i++)
    {
        if (x[i] == a)
            return i;
    }
    return -1;
}

void FrecventaPeNumar(int x[], int n) {
    int f[100];
    //init
    for (int i = 0; i < 100; i++) {
        f[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        f[x[i]]++;

    }

    //afisare
    for (int i = 0; i < 100; i++) {
        if (f[i]) {
            cout << i << "se repeta de " << f[i] << endl;
        }
    }
}

void FrecventaPeCifre(int n) {
    int f[10];
    for (int i = 0; i < 10; i++) {
        f[i] = 0;
    }
    while (n)
    {
        f[n % 10]++;
        n = n / 10;
    }
    for (int i = 0; i < 10; i++) {
        if (f[i]) {
            
            cout << i << "se repeta de " << f[i] << endl;
        }
    }
}

void Introducere(int x[], int&n, int p, int nou) {
    for (int i = n - 1; i >= p; i--)
        x[i + 1] = x[i];

        x[p] = nou;
        n++;
    
}


void Stergere(int x[], int&n,int p) {
  

    for (int i = p; i < n - 1; i++)
    {
        x[i] = x[i + 1];
    }

    n--;
}

void BubbleSort(int x[], int n) {
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
}

void Sortare(int x[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n ; j++) {
            if (x[i] > x[j])
            {
                swap(x[i], x[j]);
            }
          
        }
    }
}

void FunctieAfisare(int x[], int d) {
    cout << endl;
    for (int i = 0; i < d; i++)
        cout << x[i] << "\t";
    cout << endl;
}

void CitireCifre(int x[], int& d) {
    ifstream read("Input.txt");
    read >> d;
    for (int i = 0; i < d; i++) {
        read >> x[i];

    }
}