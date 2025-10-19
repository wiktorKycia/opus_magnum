#include "A.h"
#include<iostream>

unsigned int A::ile = {0}; // deifinicja składowej statycznej

int A::f(int x)//definicja metody f z klasy A
{
	//kod metody f
    std::cout << "f("<<x<<")" << std::endl;
    return x;
}

int A::j(int x)
{
    return x;
	//kod metody j
}

int A::i(int x)
{
    return 0;
}

