#include<iostream>
using namespace std;

//* static_assert - w momencie kompilacji, upewnij sie, że warunek jest prawdziwy, a jak nie to zgłoś błąd
// static_assert(bool_constexpr, text info)

constexpr int liczba_czujnikow = 7;
static_assert( (liczba_czujnikow % 2) == 0, "Blad: liczba_czujnikow musi byc parzysta");

int main()
{
	cout << "Bardzo rozbudowany program. Podaj nr opcji [1-4]: " << endl;
	int nr;
	cin >> nr;
	switch(nr)
	{
		case 1: break;
		case 2:
			if(sizeof(int) == 2) cout << "Blad: Typ int jest za maly dla tej opcji";
			static_assert(sizeof(int) == 2, "Blad: W tym kompilatorze typ int nie jest 2-bajtowy" );
			break;
		default: break;
	}

	static_assert(numeric_limits::is_signed, "Uwaga: Ten kompilator traktuje typ char jako bez znaku!");
	static_assert(35000 < numeric_limits::max(),"Blad, typ int nie nadaje sie do tak duzych wartosci!");
}



