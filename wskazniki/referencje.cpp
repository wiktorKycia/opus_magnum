#include<iostream>
using namespace std;
int main()
{
    int a = 10; // nazwa a identyfikuje zawartość kontenera o adresie &a
    cout << "a=" << a << endl;
    int b = a; // nazwa b identyfikuje zawartość kontenera o adresie &b, zawierającego kopię wartości a
    int *p = &a;// nazwa p reprezentuje ten kontener o adresie &a
    cout << "*p="<< *p << endl;
    int &r = a; //referencja  r reprezentuje inną niż  a  nazwę zawartości kontenera o adresie &a, tzn. &r == &a
    r = 20; // zmiana wartości bez dereferencji
    cout << "r="<< r << endl;
    cout << "a=" << a <<endl;
    *p = 20;// zmiana wartości przez dereferencję

    {
        // zmiana wartości r automatycznie zmienia wartość a i vice versa. 
        int a = 10;
        int &r = a;
        r = 20; // a == 20;
        a = 30; // r == 30;
    }

    {
        int a = 10;
        cout << "a="<< a<<endl;
        int b = 20;
        int &r1 = a;
        cout << "r1="<<r1<<endl;
        cout << &a << " " << &r << endl;
        r1 = b; //zmiana wartości referencji
        cout << "r1=" <<r1<<endl;
        cout << "a="<<a<<endl;
        cout << &a << " " << &r << endl;
        
        // &r1 = &b;//! tak nie można
        const int   &r2 = a; // r2 jest stałą referencją do obiektu typu int
        // r2 = b;// !Błąd kompilatora - próba zmiany stałej referencji
        // stałej referencji nie można zmieniać bezpośrednio, ale można zmienić wartość oryginalnej zmiennej, wtedy wartość referencji też się zmieni
        cout <<"r2=" <<r2 << endl;
        cout <<"a="<<a<<endl;
        a= 50;
        cout <<"r2=" <<r2 << endl;
        cout <<"a="<<a<<endl;
        
        int const  &r3 = a; // alternatywny zapis, że r3 stałą referencją do obiektu typu int
        // r3 = b;// !Błąd kompilatora - próba zmiany stałej referencji




        int  * const p1 = &a; // p1 jest stałym wskaźnikiem do obiektu typu int
        *p1 = 40; // możliwa zmiana wartości przez dereferencję wskaźnika
        // p1 = &b;// !Błąd kompilatora - próba zmiany stałego wskaźnika
        // stały wskaźnik:
        // - można zmieniać wartość na którą wskazuje
        // - nie można zmieniać tego na co wskazuje

        int const  * p2  = &a; // p2 jest wskaźnikiem do stałego obiektu typu int
        //! *p2 = 50; // !Błąd kompilatora - próba zmiany stałej wartości
        int b = 60;
        p2 = &b; // możliwa zmiana wartości wskaźnika

        // wskaźnik do stałego obiektu:
        // - nie można zmieniać wartości obiektu, na który wskazuje
        // - można zmienić na co wskazuje
    }

    return 0;
}