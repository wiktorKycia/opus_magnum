#include "Klasa1.h"
#include<iostream>

int Klasa1::ile = 0;

int Klasa1::f(int x)
{
	std::cout << this << std::endl;//drukuje adres obiektu
	std::cout << x << std::endl;// w rzeczywistości jest tu std::cout << this->x << std::endl;
	return ile++;
}
void Klasa1::g() const
{
	//x = 100; //!błąd funkcje składowe const nie mogą edytować składowych
    std::cout << "to jest składowa funkcja const" << std::endl;
}

void Klasa1::h() volatile
{
	x = 100;
}