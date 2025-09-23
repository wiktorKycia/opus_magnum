#include <iostream>

using namespace std;


float srednia(float *tab, int ile) // *tab informuje, że przekazujemy wskaźnik do tablicy
{
    float suma = 0;
    for (int i = 0; i < ile; i++)
    {
        suma += *tab;
        *tab = 999; // dowód, że mamy do czynienia z kopią
        tab++;
    }
    return suma / ile;
}

float srednia1(float &a, float &b, float &c) // & informuje, że oryginały zmiennych zostaną przeniesione do funkcji (a nie ich wartości)
{
    return (a+b+c)/3;
}

int main()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");

    float tablica[3] { 1.5, 3.2, 5.4 };
    float a, b, c;

    cout << "Średnia wynosi: " << srednia(tablica, 3) << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << tablica[i] << endl;
    }
    return 0;
}