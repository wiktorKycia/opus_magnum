#include <iostream>
#include <fstream>

using namespace std;

string name, surname;
int phone_num;

int main()
{
    cout << "Podaj imie:";
    cin >> name;
    cout << "Podaj nazwisko:";
    cin >> surname;
    cout << "Podaj nr_tel:";
    cin >> phone_num;

    fstream file;
    file.open("data.txt", ios::out | ios::app);
    // ios::out - zapis do pliku, podmienia jeśli plik istnieje i jest w nim coś
    // ios::out | ios::app - dopisuje do pliku

    file << name << endl;
    file << surname << endl;
    file << phone_num << endl;

    file.close();

    return 0;
}