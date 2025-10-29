#include<iostream>
using namespace std;

int main()
{
    char a = 0b00000001;
    cout << (int)a << endl;

    int n = 0; // który bit accessujemy 
    // Get
    int get = (a >> n) & 1; // indeksy od 0 do 7 od prawej (czyli najmniejszej potęgi dwójki)
    cout << get << endl;

    // Set
    n = 1;
    a |= 1 << n;

    cout << (int)a << endl;


    // Unset
    a &= ~(1 << n);

    cout << (int)a << endl;

    // Toggle
    a ^= 1 << n;
    cout << (int)a << endl;
    a ^= 1 << n;
    cout << (int)a << endl;

    cout << (int)(a & 1) << endl;


    return 0;
}