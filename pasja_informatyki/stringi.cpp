#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void name()
{
    string imie;

    cout << "Tell me your name: ";
    cin >> imie;

    int dlugosc = imie.length();
    
    if(imie[dlugosc-1] == 'a')
    {
        cout << "you are a woman" << endl;;
    }
    else
    {
        cout << "you are a man" << endl;
    }
}

void wyraz()
{
    string wyraz;

    cout << "podaj wyraz: ";
    getline(cin, wyraz);

    int dlugosc = wyraz.length();

    for(int i = dlugosc-1; i >= 0; i--)
    {
        cout << wyraz[i];
    }
    cout << endl;
}

void konkatenacja()
{
    string first = "Ala ma ";
    string second = "kota";
    cout << first + second; // konkatenacja
}

void upper_and_lower()
{
    string napis = "Ala ma kota";
    transform(napis.begin(), napis.end(), napis.begin(), ::toupper);
    cout << napis << endl;

    transform(napis.begin(), napis.end(), napis.begin(), ::tolower);
    cout << napis << endl;
}

void szukanie_podciagow()
{
    string napis = "Ala ma kota";
    string szukaj = "kot";

    size_t pozycja = napis.find(szukaj);

    if(pozycja != string::npos)
    {
        cout << "znaleziono na pozycji: " << pozycja << endl;
    }
    else
    {
        cout << "nie znaleziono";
    }
}

void kasowanie()
{
    // erase(5,10); kasuje 10 elementów od piątego włącznie
    string napis = "Ala ma kota";
    napis.erase(5, 2);
    cout << napis << endl;
}

void wstawianie()
{
    string napis = "Ala ma kota";
    napis.insert(11, " Filemona"); // od znaku o idx 11 wstaw napis
    cout << napis << endl;
}

void zastepowanie()
{
    string napis = "ala ma kota";
    napis.replace(4, 2, "nie ma"); // od którego elementu, ile znaków zastąpić, czym
    cout << napis << endl;
}

void wyjmowanie()
{
    string napis = "ala ma kota";
    string nowynapis = napis.substr(4, 7); // od którego, ile
    cout << nowynapis << endl;
}

int main()
{
    
    wyjmowanie();
    return 0;
}