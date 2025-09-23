#include <iostream>
#include<conio.h>

/* potrzebne na windowsie, na linuxie wystarczy to co jest wyżej
#include <stdio.h>
#include <cstdlib>
*/

using namespace std;

float x, y;
char wybor;

int main ()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");

    do
    {
        system("clear");

        cout << endl;
        cout << "MENU GŁÓWNE" << endl;
        cout << "===========" << endl;
        cout << "1. Dodawanie" << endl;
        cout << "2. Odejmowanie" << endl;
        cout << "3. Mnożenie" << endl;
        cout << "4. Dzielenie" << endl;
        cout << "5. Wyjdź" << endl;
        
        cout << endl;
        wybor = getch();

        if (wybor == 5)
        {
            exit(0);
        }
        
        cout << "Podaj 1 liczbę: ";
        cin >> x;
        cout << "Podaj 2 liczbę: ";
        cin >> y;

        switch(wybor){
            case '1':{
                cout << x << " + " << y << " = " << x+y << endl;
                break;
            }

            case '2':
            {
                cout << x << " - " << y << " = " << x-y << endl;
                break;
            }

            case '3':
            {
                cout << x << " * " << y << " = " << x*y << endl;
                break;
            }

            case '4':
            {
                if (y == 0)
                {
                    cout << "Nie można dzielić przez 0" << endl;
                }
                else
                {
                    cout << x << " / " << y << " = " << x/y << endl;
                }
                break;
            }

            default:
            {
                cout << "Nie ma takiej opcji!" << endl;
            }
        }
        getchar();getchar();
        
    }while(true);
    
    

    return 0;
}