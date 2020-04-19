#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;
ifstream read("Input.txt");

void FunctieAfisare(int[], int);
void CitireCifreInputUnu(int[], int &);
void CitireCifreInputDoi(int[], int &);
void SumaElementelorUnuiVector(int[], int);                     //P1
void CautareaElementuluiMinim(int[], int);                      //P2
void OrdineaCrescatoareSauDesc(int[], int);                     //P3
void OrdonareCrescatoareSortareLiniara(int[], int);             //P4
void OrdonareCrescatoareSortareBubble(int[], int);              //P4
void SumaSiDiferentaADoiVectori(int[], int, int[], int, int[]); //P5
void InterclasareVectori(int[], int, int[], int, int[]);        //P6
void StergereElementDePePozitiaK(int[], int &, int);            //P7
void InserareElementPePozitiaK(int[], int &, int, int);         //P8
int Prim(int);
void Stergere(int[], int &, int);
void Solutie(int[], int &);                       //P9 nu am rezolvat
void SortareVectorElementePrime(int[], int, int); //P10
void Interclasare(int[], int, int[], int, int[], int &);

int main()
{
    int x[200];
    int y[200];
    int z[200];
    int nX;
    int nY;
    int n, m, k;
    CitireCifreInputUnu(x, nX);
    CitireCifreInputUnu(y, nY);
    OrdonareCrescatoareSortareBubble(x, nX);

    OrdonareCrescatoareSortareBubble(y, nY);
    Interclasare(x, nX, y, nY, z, k);
    FunctieAfisare(z, k);
    // CitireCifreInputDoi(y, nY);
    // SumaElementelorUnuiVector(x, n);
    // CautareaElementuluiMinim(x, n);
    // OrdineaCrescatoareSauDesc(x, n);
    // OrdonareCrescatoareSortareLiniara(x, n);
    // OrdonareCrescatoareSortareBubble(x, n);
    // StergereElementDePePozitiaK(x, nX, 3);
    // SumaSiDiferentaADoiVectori(x, nX, y, nY, z);
    // InterclasareVectori(x, nX, y, nY, z);
    //InserareElementPePozitiaK(x, nX, 3, 111);
    //Solutie(x, nX);
    //SortareVectorElementePrime(x, 1, 10);
}

void Interclasare(int x[], int n, int y[], int m, int v[], int &k)
{
    int i = 0, j = 0;
    k = 0;
    while (i < n && j < m)
    {
        if (x[i] == y[j])
        {
            v[k] = x[i];
            i++;
            j++;
            k++;
        }
        else
        {
            if (x[i] < y[j])
            {
                v[k] = x[i];
                i++;
                k++;
            }
            else
            {
                v[k] = y[j];
                k++;
                j++;
            }
        }
    }
    while (i < n)
    {
        v[k] = x[i];
        k++;
        i++;
    }
    while (j < m)
    {
        v[k] = y[j];
        k++;
        j++;
    }
}

int Prim(int n)
{
    if (n == 1 || n == 0)
    {
        return 0;
    }
    for (int i = 2; i <= n / 2; i++)
        if (n % 2 == 0)
            return 0;
    return 1;
}

void Stergere(int x[], int &n, int p)
{
    for (int i = p; i < n - 1; i++)
    {
        x[i] = x[i + 1];
    }
    n--;
}

void Solutie(int x[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        if (Prim(x[i]))
        {
            Stergere(x, n, i);
            i--;
        }
    }
    FunctieAfisare(x, n);
}

void SortareVectorElementePrime(int x[], int a, int b)
{
    int contorIndex = 0;
    for (int i = a; i <= b; i++)
    {
        if (i % 2 != 0 || i != 2)
        {
        }
    }
}

void VerificareNumerePrime(int x[200])
{
    bool flag = false;

    for (int i = 0; i < 200; i++)
    {
        for (int j = 2; j < x[i]; j++)
        {
            if (x[i] % j == 0)
            {
                flag = true;
                break;
            }
            else
            {
                flag = false;
            }
        }

        if (flag == false && x[i] > 1)
        {
            cout << x[i] << " is prime" << endl;
        }
        else
        {
            cout << x[i] << " number is not prime" << endl;
        }
    }
}

void InserareElementPePozitiaK(int x[], int &n, int p, int nou)
{
    for (int i = n - 1; i >= p; i--)
        x[i + 1] = x[i];

    x[p] = nou;
    n++;

    FunctieAfisare(x, n);
}

void StergereElementDePePozitiaK(int x[], int &n, int p)
{
    for (int i = p; i < n - 1; i++)
    {
        x[i] = x[i + 1];
    }
    n--;
    //FunctieAfisare(x, n);
}

void InterclasareVectori(int x[], int nX, int y[], int nY, int z[])
{
    int dimensiuneZ = nX + nY;

    for (int i = 0; i < nX; i++)
    {
        z[i] = x[i];
    }
    for (int j = nX; j < nX + nY; j++)
    {
        z[j] = y[j - nX];
    }

    cout << endl
         << endl
         << "Interclasare: " << endl;
    OrdonareCrescatoareSortareBubble(z, dimensiuneZ);
}

void SumaSiDiferentaADoiVectori(int x[], int nX, int y[], int nY, int z[])
{
    char alegere;
    cout << "Doriti sa calculati [s]uma sau [d]iferenta? : ";
    cin >> alegere;

    switch (alegere)
    {
    case 's':
        if (nX == nY)
        {

            for (int i = 0; i < nX; i++)
            {
                z[i] = x[i] + y[i];
            }
        }
        else
        {
            cout << "Vectorii au dimensiuni diferite!" << endl;
        }
        break;
    case 'd':
        if (nX == nY)
        {

            for (int i = 0; i < nX; i++)
            {
                z[i] = x[i] - y[i];
            }
        }
        else
        {
            cout << "Vectorii au dimensiuni diferite!" << endl;
        }
        break;
    default:
        cout << "Alegere gresita.Alege s-suma sau d-diferenta!" << endl;
    }
    FunctieAfisare(z, nX);
}

void OrdonareCrescatoareSortareBubble(int x[], int n)
{
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

void OrdonareCrescatoareSortareLiniara(int x[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (x[i] > x[j])
            {
                swap(x[i], x[j]);
            }
        }
    }
    FunctieAfisare(x, n);
}

void OrdineaCrescatoareSauDesc(int x[], int n)
{
    bool ordineC = false; // = true;
    bool ordineD = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (x[i] < x[i + 1])
            ordineC = true;
        else
        {
            ordineC = false;
            break;
        }
    }

    if (ordineC == false)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (x[i] > x[i + 1])
                ordineD = true;
            else
            {
                ordineD = false;
                break;
            }
        }
    }

    if (ordineC == false && ordineD == false)
    {
        cout << " Numerele nu sunt in ordine" << endl;
    }
    else if (ordineC == true)
        cout << "Numerele sunt in ordine crescatoare" << endl;
    else if (ordineD == true)
        cout << "Numerele sunt in ordine descrescatoare" << endl;
}

void CautareaElementuluiMinim(int x[], int n)
{
    int elementulMinim = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (x[i] < elementulMinim)
            elementulMinim = x[i];
    }
    cout << "Elementul minim din vector este: " << elementulMinim;
}

void SumaElementelorUnuiVector(int x[], int n)
{
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma = suma + x[i];
    }
    cout << "Suma elementelor din vector este: " << suma;
}

void CitireCifreInputUnu(int x[], int &n)
{

    read >> n;
    for (int i = 0; i < n; i++)
    {
        read >> x[i];
    }
}

void CitireCifreInputDoi(int x[], int &n)
{
    ifstream read("Input2.txt");
    read >> n;
    for (int i = 0; i < n; i++)
    {
        read >> x[i];
    }
    FunctieAfisare(x, n);
}

void FunctieAfisare(int x[], int d)
{
    cout << endl;
    for (int i = 0; i < d; i++)
        cout << x[i] << "\t";
    cout << endl;
}