#include<iostream>
using namespace std;

int main()
{
    int * tab = new int[10]; // new int[10] zwraca adres pierwszego elementu tablicy 10 elementów

    for(int i = 0; i < 10; i++)
    {
        *(tab + i) = i+1;
    }
    for(int i = 0; i < 10; i++)
    {
        cout << tab[i] << endl;
    }


    delete [] tab;

    return 0;
}