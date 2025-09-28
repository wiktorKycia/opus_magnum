#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

string name, surname;
int phone_num;

int main()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");

    fstream file;
    file.open("data.txt", ios::in);

    if (file.good()==false) // good() zwraca false jak plik nie istnieje, a true jak istnieje
    {
        cout << "Plik nie istnieje!" << endl;
        file.close();
        exit(0);
    }

    string line;
    int line_number=1;
    // getline pobiera z pliku linię i zapisuje ją do zmiennej, zwraca false jeśli jest to koniec pliku
    // linie iterują się od 1, a nie od 0
    while(getline(file, line)) 
    {
        switch(line_number)
        {
            case 1: name = line; break;
            case 2: surname = line; break;
            case 3: phone_num = atoi(line.c_str()); break;
        }
        line_number++;
    }

    file.close();

    cout << "Imię: " << name << ", Nazwisko: " << surname << ", numer tel: " << phone_num << endl;

    return 0;
}
