#include<iostream>
using namespace std;

void print_bit_representation(char& a)
{
    for(int i = 7; i >= 0; i--)
    {
        cout << (int)((a & (1 << i)) >> i);
    }
    cout << endl;
}

int main()
{
    char a = 0b00000001;
    cout << (int)a << endl;

    int n = 0; // który bit accessujemy 
    // Get
    int get = (a >> n) & 1; // indeksy od 0 do 7 od prawej (czyli najmniejszej potęgi dwójki)
    cout << get << endl;

    // Set
    n = 3;
    a |= 1 << n;
    cout << (int)a << endl;
    print_bit_representation(a);


    // Unset
    a &= ~(1 << n);
    print_bit_representation(a);
    // cout << (int)a << endl;

    // Toggle
    a ^= 1 << n;
    print_bit_representation(a);
    // cout << (int)a << endl;
    a ^= 1 << n;
    print_bit_representation(a);
    // cout << (int)a << endl;

    cout << (int)(a & 1) << endl;

    print_bit_representation(a);


    return 0;
}