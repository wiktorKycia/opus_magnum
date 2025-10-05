#include<iostream>

int n; // to wszystko są definicje
double x;
char p;

int f(int x)
{
	std::cout << x << std::endl;
}

double g(double x)
{
	std::cout << x << std::endl;
}

// wymuszenie ograniczenia widoczności zmiennej do jednego pliku
static int zmienna_globalna; // stary sposób

// nowy sposób:
namespace // nie ma nazwy więc przestrzeń jest anonimowa
{
    int zmienna_globalna;
}