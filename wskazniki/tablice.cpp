#include <iostream>
using namespace std;

int main()
{
    int tab[10]; // statyczna alokacja tablicy 10 intów na stosie funkcji main
    // nazwa tab identyfikuje adres pierwszego bajta tablicy
    tab[0] = 10;
    tab[1] = 5;
    int *adres_tablicy = tab;

    cout << tab << endl;                // adres pierwszego bajta tablicy
    cout << *adres_tablicy << endl;     // wartość pierwszego elementu
    cout << adres_tablicy << endl;      // adres pierwszego bajta tablicy
    cout << &adres_tablicy << endl;     // adres wskaźnika

    if(tab[0] == *tab) // zawartość pierwszego elementu vs. wartość stojąca pod adresem tablicy (czyli adresem pierwszego elementu)
    {
        cout << *tab << endl;
    }

    int drugi_element = *(tab + 1); // tab+1 to adres pierwszego elementu tablicy przesunięty o 4 bajty (wielkość int) względem początku, czyli wskazuje na drugi element, operatorem * otrzymujemy wartość tego drugiego elementu
    cout << drugi_element << endl;

    if(tab[1] == *(tab + 1)) // zawartość drugiego elementu vs. zawartość elementu o adresie o 4 bajty większym od elementu pierwszego
    {
        cout << "to sie zgadza" << endl;
    }


    return 0;
}