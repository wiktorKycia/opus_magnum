#include <iostream>
#include <cstdlib>
using namespace std;

int* create_table(int size) // funkcja zwraca wartość typu wskaźnikowego, tworzy tablicę na swojej stercie i przekazuje adres utworzonego obiektu, sterta nie podlega dealokacji
{
    int *tab = new int[size];

    for(int i = 0; i < size; i++)
    {
        tab[i] = rand();
    }
    return tab;
}

int max_tab(int *tab, int size) // do tab przekazywany jest adres oryginalnego obiektu, nie jest kopiowane ze stosu, nie można podać stałych dosłownych
{
    int m = tab[0];
    for(int i = 1; i < size; i++)
        if (tab[i] < m) m = tab[i];
    
    return m;
}

int main()
{
    int tab[100];
    for (int i = 0; i < 100; i++)
    {
        tab[i] = rand();
    }
    int max = max_tab(tab, 100);
    cout << max << endl;

    return 0;

    int *tab1;
    tab1 = create_table(100);
}