#include<iostream>

using namespace std;

float metry;

float metry_na_cale(float m) // przesyłanie przez wartość
{
    return m*39.37;
}

float metry_na_jardy(float m); // nagłówek funkcji

void metry_na_mile(float m);

int main()
{
    cout << "Podaj ilosc metrow" << endl;
    cin >> metry;

    cout << metry_na_cale(metry) << " cali" << endl;
    cout << metry_na_jardy(metry) << " jardow" << endl;
    metry_na_mile(metry);

    return 0;
}

float metry_na_jardy(float m) // ciało funkcji
{
    return m*1.0936;
}
void metry_na_mile(float m)
{
    cout << m * 0.0006213 << " mil";
}