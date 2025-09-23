#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int ile;
clock_t start, stop;
double czas;

int main()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");
    cout << "Ile liczb ma być w tablicy?: ";
    cin >> ile;

    int *tablica;
    tablica = new int [ile];

    start = clock();

    for(int i = 0; i < ile; i++)
    {
        tablica[i] = i;
        tablica[i] += 50;
    }

    stop = clock();

    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Czas wykonania: " << czas << endl;

    /*
    for(int i = 0; i < ile; i++)
    {
        cout << tablica << endl;
        tablica++; // dodanie 4 bajtów, bo int ma 4 bajty (przestawienie na kolejną szufladkę)
    }*/

    delete [] tablica;

    int *wsk = tablica;
    tablica = new int [ile];

    start = clock();

    for(int i = 0; i < ile; i++)
    {
        *wsk = i; // zapis do [i] szufladki w tablicy
        *wsk += 50; // odczyt i zapis wartości o 50 większej do szufladki w tablicy
        wsk++; // przestawienie wskaźnika na następną szufladkę
    }

    stop = clock();

    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Czas wykonania: " << czas << endl;

    return 0;
}