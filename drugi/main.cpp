/* -----------------------------------------------------------
Program na przeliczanie wysokosci podanej w stopach na wysokosc w metrach.
Cwiczymy tu operacje wczytywania z klawiatury i wypisywania na ekranie
------------------------------------------------------------*/

#include<iostream>

using namespace std;

int main()
{
    int ft; 
    double meters;
    double conversion_rate = 0.3;

    cout << "Podaj wysokosc w stopach: ";
    cin >> ft;

    meters = ft * conversion_rate;

    cout << endl;
    cout << ft << " stop - to jest: " << meters << " metrow";


    return 0;
}
