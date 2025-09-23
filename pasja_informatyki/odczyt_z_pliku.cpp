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

    string text;
    getline(file, text);

    cout << text << endl;

    return 0;
}
