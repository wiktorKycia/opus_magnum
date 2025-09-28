#include<iostream>
using namespace std;

int main()
{
    // operator * należy do nazwy, a nie do typu 
    int* ptr1, ptr2; // ptr1 to wskaźnik do int, ptr2 to zmienna typu int

    int *a = new int;
    *a = 10;
    void *b = a; // poprawne - do b przypisywany jest adres z new (czyli a), do *b przypisywana jest wartość *a 

    cout << a << endl; // adres do obiektu zwróconego przez new
    cout << *a << endl;// wartość obiektu zwróconego przez new
    cout << b << endl; // adres do obiektu zwróconego przez new
    // cout << *b << endl; // nie można wypisać

    cout << &a << endl;
    cout << &b << endl;

    int c{10};
    void *wsk_c = &c; // poprawne - wskaźnik do zmiennej c

    const int d = 20;
    //void *wsk_d = &d; // przypisanie adresu z consta traktowane jest jako jego modyfikacja

    int liczba{20};
    void *wsk_liczba = &liczba;
    // *wsk_liczba = 10; // niepoprawne - wymagana jawna konwersja typu
    *(int*)wsk_liczba = 20; // konwersja na typ int* i dostanie się do wartości, przypisanie 20
    cout << liczba << endl;

    void *wsk1 = new int;
    //int *wsk2 = wsk1; // błąd: nie można przypisać void* do int*
    int *wsk2 = (int*)wsk1; // konwersja na typ int*

    auto *wsk3 = &liczba; // można przypisać wartość jawnie
    auto wsk4 = &liczba; // lub niejawnie

    auto *wsk5 = new int; // tutaj tak samo, ale jak porównamy, to nie będą sobie równe, bo są to różne obiekty
    auto wsk6 = new int;

    if(*wsk3 == *wsk4)
    {
        cout << "to jest to samo" << endl;
    }

    // Operatory

    // + przesuwa wskaźnik o określoną wielokrotność bajtów (np. dla int jest to 4, bo int ma 4 bajty)
    // - (op. różnicy):
    // przesuwanie wskaźników podobnie jak przy plusie(+)
    // różnica dwóch wskaźników tego samego typu jest równa ilości elementów tego typu między wskaźnikami (przydatne w tablicach)

    // operatory porównania: ==, >, <, >=, <=, != służa do określania kolejnośći wzajemnego położenia obiektów (przydatne w tablicach)

    
    return 0;
}