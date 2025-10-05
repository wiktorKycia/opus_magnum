#include<iostream>
using namespace std;


//*Zmienna statyczna – jest to zmienna, która w danym bloku programu posiada dokładnie jedną instancję i istnieje przez cały czas działania programu. 

//*Zmienne lokalne statyczne: zmienne zadeklarowane w bloku funkcji, ale nie znikające po zakończeniu jej działania
// widoczne tylko w zakresie bloku, w którym są zadeklarowane


// zmienne statyczne są alokowane w segmencie danych a nie na stosie

void czerwona(void)
{
	static int ktory_raz;
	ktory_raz++;
	cout << "Funkcja czerwona wywolana "<< ktory_raz << " raz\n";
}

void biala(void)
{
	static int ktory_raz = 100;
	ktory_raz = ktory_raz + 1;
	cout << "Funkcja biala wywolana "<< ktory_raz << " raz\n";
}


int main()
{
	czerwona(); //wydruk: Funkcja czerwona wywolana 1 raz
	czerwona(); //wydruk: Funkcja czerwona wywolana 1 raz
	biala(); //wydruk: Funkcja biała wywolana 101 raz
	czerwona(); //wydruk: Funkcja czerwona wywolana 3 raz
	biala(); //wydruk: Funkcja biała wywołana 102 raz
    return 0;
}