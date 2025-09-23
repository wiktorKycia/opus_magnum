#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    fstream file;
    file.open("data.txt", ios::in);

    if (file.good()==false) // good() zwraca false jak plik nie istnieje, a true jak istnieje
    {
        cout << "Plik nie istnieje!" << endl;
        file.close();
        exit(0);
    }

    string line;
    int line_number;
    // getline pobiera z pliku linię i zapisuje ją do zmiennej, zwraca false jeśli jest to koniec pliku
    // linie iterują się od 1, a nie od 0
    while(getline(file, line)) 
    {

    }

    cout << line << endl;

    return 0;
}
