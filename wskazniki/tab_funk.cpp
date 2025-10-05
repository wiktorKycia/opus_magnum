#include <iostream>
using namespace std;

void print_info(int tab, int size) // ta funkcja nie ma sensu, nie ma jak się dostać do oryginalnych wartości w tablicy, bo przekazywana jest tylko kopia pierwszego elementu
{
    cout << "Print info: " << endl;
    // for(int i = 0; i < size; i++)
    // {
    //     cout << tab[i] << " "; //! błąd: nie można odczytać wartości tab[i], bo tab ma typ int
    // }
    // cout << endl;
    // cout << tab << endl;
    // cout << &tab << endl;
}

void print_ptr_info(int *tab, int size)
{
    cout << endl << "Print pointer info: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
    cout << tab << endl; // adres przekazanej tablicy
    cout << &tab << endl; // adres skopiowanego wskaźnika
}

void print_ref_info(int &tab, int size)
{
    cout << endl << "Print ref info: " << endl;
    // for(int i = 0; i < size; i++)
    // {
    //     cout << tab[i] << " ";//! błąd: nie można odczytać wartości tab[i], bo tab ma typ int
    // }
    // cout << endl;
    // cout << tab << endl;
    // cout << &tab << endl;
    int *tab_ptr = &tab;
    for(int i = 0; i < size; i++)
    {
        cout << *(tab_ptr+i) << " " ;
    }
    cout << endl;
    cout << tab << endl;        // wartość pierwszego elementu, bo taki został przekazany
    cout << &tab << endl;       // adres pierwszego elementu = adres oryginalnej tablicy
    cout << *tab_ptr << endl;   // dereferencja wskaźnika, który wskazuje na pierwszy element
    cout << tab_ptr << endl;    // wartość wskaźnika = adres pierwszego elementu = adres tablicy
    cout << &tab_ptr << endl;   // adres wskaźnika (w tym przypadku lokalnego dla funkcji)
}

int main()
{
    constexpr int size = 5;
    int *arr = new int[size]{1,2,3,4,5};

    cout << &arr << endl;
    cout << arr << endl;
    cout << *arr << endl;

    // print_info(arr, size);
    print_ptr_info(arr, size);
    print_ref_info(*arr, size);



    return 0;
}