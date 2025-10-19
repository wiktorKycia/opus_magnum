#include "A.h"
#include<iostream>

int A::f(int x)//definicja metody f z klasy A
{
	//kod metody f
    std::cout << "f("<<x<<")" << std::endl;
    return x;
}

int A::j(int x)
{
	//kod metody j
}

int A::i(int x)
{
    return 0;
}

