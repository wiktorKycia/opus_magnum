/*
konstruktor jest wywoływany dopiero po alokacji pamięci
zatem w momencie wywołania obiekt musi już być zdefiniowany 
*/

#include<iostream>
#include<string>
using namespace std;

class Person
{
    string name;
    public:
    Person(string _name)
    {
        this->name = _name;
    };

    Person(const Person &p) // konstruktor kopiujący; stała referencja po to, aby uniemożliwić popsucie oryginału przez konstruktor kopiujący
    {
        this->name = p.name;
    }
    void say_hello();
};

void Person::say_hello()
{
    cout << this->name << endl;
}

class A
{
	//...
		double x;
		bool test;
		const int a;
		int & ref;

	public:
        // konstruktorowa lista inicjalizacyjna
        // inicjalizacje zmiennych (lub obiektów) są wykonywane razem z alokacją pamięci dla obiektu klasy A
		A(double _x, bool _test, int _a, int & _ref): a{_a}, ref{_ref} // muszą one się znaleźć tu
        // dla składowych const i referencyjnych (&) nie ma innej możliwości
		{
			//składowe zwykłe

            x = {_x};
            test = {_test};

		};
	//...
};


class C
{
	double x;

	int y;

	public:
		C(double _x,  int _y): x{_x},  y{_y}
		{

		}

		C(): C(0.0, 0){} // dziedziczenie konstruktorów

};

int main()
{
    Person *p = new Person("Wiktor");
    p->say_hello();
    delete p;
    return 0;
}