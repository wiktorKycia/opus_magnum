#include<iostream>
#include<cmath>
#include<string>
#include<vector>
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
    return 0;
}


