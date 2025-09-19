#include<iostream>
#include<cstdint>
#include<locale>
#include<typeinfo>

using namespace std;

/*
można też zapisać:
using std::cout
using std::cin
*/

typedef int calkowita; // te dwie deklaracje można stosować zamiennie
using real = float;
// utarło się, że typy tworzone deklaracją typedef zapisywać z końcówką _t, by nie pomylić z nazwą zmiennej

int k = 33;

int main()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");
    std::ios_base::sync_with_stdio(false);
    std::wcout.imbue(std::locale("pl_PL.UTF-8"));

    short int zmienna = 234; // równoznaczne z short
    cout << zmienna << endl;

    unsigned int a = -5; // to samo so uint
    cout << a << endl;

    int16_t b = 32000;
    cout << b << endl;

    int_fast32_t c = 1530; // potrzebuje cstdint, najszybszy możliwy typ 32 bitowy
    cout << c << endl;

    int_least64_t d = 1681513516546; // najmniejszy możliwy typ 64 bitowy
    cout << d << endl;

    float e = 0.0000000002;
    cout << e << endl;

    float f = 200000000000;
    cout << f << endl;

    float g = 161654654132684651;
    cout << g << endl;

    double h = 161654654132684651;
    cout << h << endl;

    unsigned long long i = 18446744073709551615;// long i long long to to samo, wypisze warning, ale się wykona
    cout << i << endl;

    long j = 9223372036854775807;
    cout << j << endl;


    cout << sizeof j << endl; // wielkość w bajtach, tutaj 8, czyli tak samo jak long long


    //* Inicjalizacja *//
    int zmienna1 = 6;
    int zmienna2 (6);
    int zmienna3 {6};
    int zmienna4 = {6};

    int y = 12.9; // y będzie równy 12, niejawna konwersja
    int z (12.9);
    //int x = {12.9};//int x{12.9} // kompilator podniesie alarm
    cout << y << z << endl;

    if (int k = y/z) // można definiować obiekty chwilowe w instrukcjach for, if oraz while
    {
        cout << k << endl;
    }
    else
    {
        cout << "zerowy: " << k << endl;
    }

    cout << 0x234abc << endl; // zapis szesnastkowy

    cout << 014 << endl; // zapis ósemkowy

    cout << 0b1010 << endl; // zapis dwójkowy (od c++ 14)

    cout << 0x165acd5165135L << endl; // L na końcu oznacza typ long, a LL typ long long

    // końcówka u. podobnie jak L oznacza typ unsigned, można łączyć te końcówki w dowolnej kolejności
    // końcówki są mają znaczenie przy słowie kluczowym auto

    cout << -12. << endl; // nieznaczące zera można pominąć

    cout << 5.2e-3 << endl; // notacja wykładnicza

    // końcówka F - typ float; 
    // końcówka L - typ long double

    cout << '7' << '7' << '\b' << '7' << endl;

    cout << "lorem ipsum \f lorem ipsum" << endl; // \f to nowa strona (form feed)

    cout << "lorem ipsum \r lorem ipsum" << endl; // \r to powrót karetki (carriage return)

    cout << "lorem ipsum \v lorem ipsum?" << endl; // \v - vertical tab

    cout << "\'\\\"\?\0" << endl;

    // wchar_t - rozszerzony zakres znaków, unicode
    // char16_t - utf-16
    // char32_t - utf-32
    const wchar_t tekst[38] = L"Zażółć żółcią gęślą jaźń"; // takie coś jest typu wchar_t[38]
    std::wcout << tekst << std::endl;

    /*
    cout << "Długi 
    string" << endl; 
    tak jak powyżej nie można zapisać, stringi muszą być w jednej linii
    */
    cout << "Cały ten tek"
    "st jest traktowa"
    "ny jako jeden dłu" "gi string" << endl; // jako, że nie daliśmy znaku \n lub endl, wypisany zostanie w jednej linii

    cout << R"(to jest surowy
    string \n "' )" << endl;

    cout << R"ogranicznik(Zawisza "(Czarny)" zawolal)ogranicznik" << endl; 
    cout << R"##(Boleslaw "(Krzywousty)" wszedl do komnaty)##" << endl;

    /*
[] - tablica
* - wskaźnik
() - funkcja
& - referencja
    */
    void *p; // wskaźnik wskazujący na obiekt nieznanego typu

    void funkcja(); // funkcja nie zwracająca wartości


    {
        int k = 10;
        cout << "lokalne k: " << k << endl;
        cout << "globalne k: " << ::k << endl;
    }

    const int wybor {5}; 
    constexpr int minimalny_wiek = 18; // "stała od zawsze", wartość przypisywana w momencie kompilacji, może się składać ze stałych dosłownych (literałów) lub innych wyrażeń constexpr

    constexpr int start {1};
    constexpr int koniec {2};
    
    int choice = 1;

    switch(choice)
    {
        case start:
            cout << "start" << endl;
            break;
        case koniec:
            cout << "koniec" << endl;
            break;
    }

    register int l; // zmienna do której potrzeba mieć bardzo szybki dostęp (przechowywana w rejestrze)
    // za to nie można uzyskać od takiej zmiennej adresu pamięci

    volatile int m; // zmusza kompilator do sięgnięcia do pamięci po tę zmienną, zamiast cachowania sobie jej do rejestru

    real n {5.4};
    cout << n << endl;

    enum class Takcja //zakresowe enum
    {
        start_pomiaru = 0,
        odczyt_pomiaru = 1,
        zmiana_probki = 54,
        zniszczenie_probki = 55
    };

    Takcja co_robic;

    co_robic = Takcja::start_pomiaru;
    // co_robic = 1; // tak nie można
    // co_robic = akcja_t::1; // tak też nie można

    if(co_robic == Takcja::start_pomiaru)
    {
        cout << "start pomiaru" << endl;
    }

    enum class Todtwarzacz:char
    {
        play, stop, pause=16, fast_forward
    };

    int stop = static_cast<int>(Todtwarzacz::stop);
    cout << stop << endl;

    enum nazwa_enum {a1,a2}; // zwykłe (stare) enum
    // różni sie to tym, ze nazwy a1, a2 są dostępne normalnie i nie trzeba poprzedzać tego np. w ten sposób: nazwa_enum::a1
    // może nastąpić konflikt nazw między różnymi enum, dlatego lepiej jest stosować enum class

    // stare zastosowanie zwykłego enum to definiowanie stałych liczbowych (w przypadku nienazwanego enum)
    enum { a3, a4, a5};
    cout << a4 << endl;

    auto variable = 56.78;

    auto akcja = Takcja::zmiana_probki;

    // cout << typeid(akcja).name() << endl; // checking type, requires typeinfo

    double szer;
    decltype(szer) wys;


    unsigned int obj = 5;
    using typ_roboczy = decltype(obj);

    typ_roboczy zmie1;
    typ_roboczy zmie2;

    // cout << decltype(obj) << endl; // nie można wypisać


    // ! jeśli zmienna jest zadeklarowana, ale nie jest zainicjalizowana:
    // ! poza main (globalnie): kompilator przypisuje zero stosowne do typu obiektu
    // ! w main(): kompilator wogóle nie inicjalizuje, są tam losowe wartości

    int liczba {}; // <- inicjalizacja zmiennej z zerem odpowiednim dla danego typu (wartość domniemana)

    cout << liczba << endl;


    enum class wyliczanka {ene=4, due=10, rabe};

    wyliczanka em {}; // wartość domyślna dla enum to 0
    cout << static_cast<int>(em) << endl; // 0
    
    // auto x {}; // tak nie można, poza tym to jest bez sensu

    alignas(16) long zmienna; // adres zmiennej musi być krotnością liczby 16 (dozwolone tylko potęgi liczby 2)


    return 0;
}