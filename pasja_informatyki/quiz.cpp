#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

string temat, nick;
string tresc[5];
string odpA[5];
string odpB[5];
string odpC[5];
string odpD[5];
string poprawna[5];

int main()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");

    fstream plik;
    plik.open("./pasja_informatyki/quiz.txt", ios::in);

    
    string linia;

    if(!plik.good())
    {
        cout << "Nie udało się otworzyć pliku!" << endl;
        exit(0);
    }

    for(int nr_linii = 1; getline(plik, linia); nr_linii++)
    {
        switch(nr_linii)
        {
            case 1: temat = linia; break;
            case 2: nick = linia; break;
            case 3: tresc[0] = linia; break;
            
        }
    }

    return 0;
}