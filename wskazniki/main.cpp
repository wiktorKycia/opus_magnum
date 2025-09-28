#include<iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");
    int liczba = 12;
    int *adres_liczby = &liczba;
    int **adres_adresu_liczby = &adres_liczby;

    cout << "wartość liczby: \t\t\t" << liczba << endl;
    cout << "adres liczby: \t\t\t\t" << &liczba << endl;
    cout << "rozpakowanie wskaźnika (wartość): \t" << *adres_liczby << endl;
    cout << "wskaźnik: \t\t\t\t" << adres_liczby << endl;
    cout << "adres wskaźnika: \t\t\t" << &adres_liczby << endl;

    cout << endl << endl;

    cout << &adres_adresu_liczby << endl; // adres adresu adresu liczby
    cout << adres_adresu_liczby << endl; // adres do adresu liczby
    cout << *adres_adresu_liczby << endl; // adres liczby
    cout << **adres_adresu_liczby << endl; // wartość liczby

    cout << endl << endl;

    // dynamiczna alokacja pamięci = wskaźnik do obiektu, który dopiero tworzymy
    // insrukcja new:
    // int - argument instrukcji new
    // new zwraca adres do nowo utworzonego typu

    int *adres = new int; // zaalokuj mi nowy int, gdzieś tam na stercie
    *adres = 15; // przypisz do niego 12
    cout << *adres << endl; // odczytaj wartość nowego inta
    cout << adres << endl; // odczytaj adres nowego inta
    cout << &adres << endl; // odczytaj adres wskaźnika

    delete adres; // po użyciu zmiennej trzeba ją usunąć
    delete adres_adresu_liczby;
    delete adres_liczby;

    return 0;
}