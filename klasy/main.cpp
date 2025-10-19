#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "A.h" // dołączanie własnych plików robi sie przez "", bo wtedy szuka w katalogu gdzie jest main.cpp
// używanie <> sprawia, że szuka tylko w plikach systemowych (czyli tam, gdzie są zainstalowane biblioteki c++)
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

int main()
{
    A a1;
    cout << a1.skladowa_3 << endl;
    int value1 = a1.g(10);

    return 0;
}


