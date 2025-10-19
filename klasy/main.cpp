#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "A.h" // dołączanie własnych plików robi sie przez "", bo wtedy szuka w katalogu gdzie jest main.cpp
// używanie <> sprawia, że szuka tylko w plikach systemowych (czyli tam, gdzie są zainstalowane biblioteki c++)
#include "Klasa1.h"
using namespace std;

class Point2
{
    // ang. class members:
	double x;//składowa x
	double y;//składowa y;

	double norm()//metoda obliczająca normę euklidesową punktu
	{
		return sqrt(x*x + y*y);
	}
};

class Person
{
    // domyślnie jest private
    public:
        int yearOfBirth;
        float height;
        string name;
        string surname;

        void work();

    protected:
        vector<string> interests;

    private:
        string hobby;

};

int f(int x);
void h(std::string s);

class F
{
public:

	int f(int x);//zasłanianie

	short g(int x);
	int g(int x, char y);//przeładowanie

	void h(std::string s, int x);
	void h(std::string s);//jednoczesne przeładowanie i zasłanianie

	void j(std::string s)
	{
		::h(s);//wywołanie funkcji spoza klasy;
	}

};

int main()
{
    A a1;
    cout << a1.skladowa_3 << endl;
    int value1 = a1.g(10);

    A *a2 = new A;
    cout << a2->skladowa_3 << endl;
    int value2 = a2->i(1);

    cout << sizeof(a2) << endl; // funkcja sizeof zwraca tylko sumę pamięci składowych (bez metod)
    //* pamięć na metody jest alokowana razem z utworzeniem pierwszego obiektu
    //* pamięć metod jest wspólna dla wszystkich obieków klasy 

    // składowe statyczne można odczytać zarówno z poziomu klasy jak i obiektu (przy odpowiednim operatorze)
    cout << A::ile;
    cout << a1.ile;
    cout << a2->ile;


    volatile Klasa1 o1; // do obiektóe typu volatile mogą wykonać się tylko metody volatile

	//o1.g();//!błąd kompilatora
	o1.h();//poprawne

    return 0;
}


