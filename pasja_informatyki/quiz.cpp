#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<algorithm>

using namespace std;

string temat, nick;
string tresc[5];
string odpA[5];
string odpB[5];
string odpC[5];
string odpD[5];
string poprawna[5];
string odpowiedz;
int punkty;

int main()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");

    fstream plik;
    plik.open("./pasja_informatyki/quiz.txt", ios::in);

    
    string linia;
    int nr_pytania = 0;

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
            case 3: tresc[nr_pytania] = linia; break;
            case 4: odpA[nr_pytania] = linia; break;
            case 5: odpB[nr_pytania] = linia; break;
            case 6: odpC[nr_pytania] = linia; break;
            case 7: odpD[nr_pytania] = linia; break;
            case 8: poprawna[nr_pytania] = linia; break;
        }
        if(nr_linii == 8)
        {
            nr_linii = 2;
            nr_pytania++;
        }
    }

    plik.close();

    for(int i = 0; i <= 4; i++)
    {
        cout << endl << tresc[i] << endl;
        cout << "A. " << odpA[i] << endl;
        cout << "B. " << odpB[i] << endl;
        cout << "C. " << odpC[i] << endl;
        cout << "D. " << odpD[i] << endl;
        cout << "Twoja odpowiedź: ";
        cin >> odpowiedz;

        transform(odpowiedz.begin(), odpowiedz.end(), odpowiedz.begin(), ::tolower);
        if(odpowiedz == poprawna[i] || odpowiedz == poprawna[i].substr(0, 1))
        {
            cout << "Dobrze!" << endl;
            punkty++;
        }
        else
        {
            cout << "Żle!" << endl;
            cout << "Poprawna odpowiedź to: " << poprawna[i];
        }
    }

    cout << endl << "Koniec quizu! Zdobyte punkty: " << punkty << endl;

    return 0;
}