#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

/*
funkcje i metody:

file.ignore(ile_znakow)
file.get() - zwraca pojedyńczy znak z pliku
file.eof() - sprawdza czy flaga eof jest ustawiona
file.fail() - sprawdza czy flaga eof lub failbit są ustawione
file.seekg(0, file.beg) - reset pozycji kursora, nie działa gdy jest ustawiona flaga eof lub failbit
- pozycja
- kierunek


czyszczenie flag:
eof:
file.clear(file.rdstate() & ~ios::eofbit);
eof i failbit:
file.clear(file.rdstate() & ~(ios::eofbit | ios::failbit))


flagi:
goodbit - brak błędów strumienia:
if (stream.rdstate() & std::ifstream::goodbit)

eofbit - osiągnięto koniec pliku w czasie czytania:
if (stream.rdstate() & std::ifstream::eofbit)

failbit - jakaś operacja we/wy nie powiodła się, po wyzerowaniu flagi, można pracować ze strumieniem
if (stream.rdstate() & std::ifstream::failbit)

badbit - poważny błąd naruszający budowę strumienia, dalsza praca jest niemożliwa
if (stream.rdstate() & std::ifstream::badbit)
*/


void reset_file_position(ifstream &file)
{
    if(file.fail())
    file.clear(file.rdstate() & ~(ios::eofbit | ios::failbit));
    
    file.seekg(0, file.beg);
}

void read_char_by_char(ifstream &file)
{
    int i, ile = 0;
    file.ignore(1); // ignorujemy 1 znak

    while(!file.eof())
    {
        ile++;
        i = file.get();
        cout << char(i);//musimy przekonwertować, bo file.get() zwraca kod znaku, a nie sam znak
    }
    reset_file_position(file);
}

void read_char_by_char2(ifstream &file)
{
    int ile = 0;
    char c;
    while(!file.eof())
    {
        ile ++;
        file.get(c); // tu zostanie odczytany na końcu EOF, ale poprzednia wartość c nie zostanie wtedy zmieniona, przez to potrzebne jest sprawdzenie przed wypisaniem, czy EOF nie jest już przypadkiem osiągnięty
        // w przypadku mojego pliku ostatni znak to nowa linia, więc i tak się nic nie podwoiło
        if (!file.eof())
        {
            cout << c;
        }
    }
    reset_file_position(file);
}

void read_with_char_array(ifstream &file)
{
    char znaki[260]; // w nawiasach [] max liczba znaków do wczytania, wykorzystujemy to że typ char zajmuje tylko 1B pamięci
    file.get(znaki, sizeof(znaki), EOF); // czyta i zapisuje do tablicy, max tyle ile wynosi rozmiar tablicy znaków lub gdy nie trafi na EOF
    cout << znaki;
    reset_file_position(file);
}

void read_max_line_lenght(ifstream &file)
{
    char line[255]; // 255 tutaj to max długość linii
    while (file.getline(line, sizeof(line))) // znak LF jest usuwany z końca linii; // na końcu jako 3 parametr też można dać ogranicznik
    {
        cout << line << endl;
    }
    reset_file_position(file);
}

void read_with_std_getline(ifstream &file)
{
    string line;
    while(getline(file, line)) // tu też LF się usuwa
    {
        cout << line << endl;
    }
    reset_file_position(file);
}

void read_with_operator(ifstream &file)
{
    string line;
    while(file >> line) // tu LF też jest usuwany
    {
        cout << line << endl;
    }
    reset_file_position(file);
}

void read_with_string_stream(ifstream &file)
{
    ostringstream ss;
    ss << file.rdbuf(); //wczytanie całego pliku ze znakami LF
    string lines = ss.str(); // konwersja na 1 string
    cout << lines;
    // cout << endl; // czasem się przydaje, jak np. plik nie ma pustej linii na końcu, bo tym sposobem nie czyta ostatniego LF
    reset_file_position(file);
}

void read_with_vector(ifstream &file)
{
    file.seekg(0, file.end);
    auto endPos = file.tellg();
    file.seekg(0, file.beg);
    int size = size_t(endPos - file.tellg()); // rozmiar pliku

    vector<char> buff(size);
    file.read(buff.data(), buff.size());// 1. gdzie zapisać, 2. ile zapisać
    cout << buff.data() << endl;

    reset_file_position(file);
}

int main()
{
    ifstream file;
    string fileName = "output.txt";

    file.open(fileName, ios::in);

    if(!file.good())
    {
        cout << u8"Błąd otwarcia pliku: " << fileName << endl;
        exit(1);
    }

    // read_char_by_char(file);
    // read_char_by_char2(file);
    // read_with_char_array(file);
    // read_max_line_lenght(file);
    // read_with_string_stream(file);
    read_with_vector(file);


    file.close();

    return 0;
}