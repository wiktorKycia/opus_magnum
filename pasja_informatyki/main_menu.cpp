#include <iostream>
using namespace std;

float x, y;
int wybor;

int main ()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");
    cout << "Podaj 1 liczbę: " << endl;
    cin >> x;
    cout << "Podaj 2 liczbę: " << endl;
    cin >> y;

    cout << endl;
    cout << "MENU GŁÓWNE" << endl;
    cout << "===========" << endl;
    cout << "1. Dodawanie" << endl;
    cout << "2. Odejmowanie" << endl;
    cout << "3. Mnożenie" << endl;
    cout << "4. Dzielenie" << endl;

    cout << "Wybierz: " ;
    cin >> wybor;

    switch(wybor){
        case 1:{
            cout << x << " + " << y << " = " << x+y << endl;
            break;
        }

        case 2:
        {
            cout << x << " - " << y << " = " << x-y << endl;
            break;
        }

        case 3:
        {
            cout << x << " * " << y << " = " << x*y << endl;
            break;
        }

        case 4:
        {
            cout << x << " / " << y << " = " << x/y << endl;
            break;
        }

        default:
        {
            cout << "Nie ma takiej opcji!" << endl;
        }
    }

    
    

    return 0;
}