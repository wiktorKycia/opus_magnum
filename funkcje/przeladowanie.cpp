#include<iostream>
using namespace std;

int f(int x);//{ //...}//funkcja wzorcowa

int f(unsigned int x);//{ //...}liczba argumentów bez zmian, zmiana typu argumentów

int f(int &x);//{ //...}liczba argumentów bez zmian, zmiana typu argumentów

int f(int* x);//{ //...}//liczba argumentów bez zmian, zmiana typu argumentów

int f(float x);//{ //...}//liczba argumentów bez zmian, zmiana typu argumentów

int f(int x, int y);//{ //...}// zmiana liczby argumentów, typy bez zmian

int f(int x, float y );//{ //...}//zmiana liczby i typów argumentow

int f(float x, int y);//{ //...}//zmiana liczby i typów argumentow
/*
int f(int x = 10){ //...}//!błędne przeładownie - niejednozanaczność przy wywołaniu

void f(int y){ //...}//!błędne przeładowanie - zmiana jedynie wartości zwracanej
*/


void fff(int tab[10])
{
	//...
}

void fff(int tab[5])
{
	//...
}
//!błąd - funkcja fff() ma już treść


// nazwa tablicy statycznej jest traktowana jako wskaźnik, więc w ten sposób funkcja fff() ma już przeładowanie ze wskaźnikiem
void fff(int * wsk)
{
	//...
}
//!błąd - funkcja fff() ma już treść





int main()
{
    int y1 = f(10);//int
    // int y2 = f(10.0);//!błąd  - stała dosłowna zmiennoprzecinkowa jest typu double
    int y3 = f(10.0f);// float
    int y4 = f(10, 20);//int int
    int y5 = f(10, 10.0f); //int float

    float z = 20.0;
    double w = 30.6;

    int y6 = f(z);// float
    int y6 = f((float)w);// float


    {
        void fff(int tab[10][10]);
        {
            //...
        }

        void fff(int tab[10][5]);
        {
            //...
        }
        //nie ma błędu


        void fff(int tab[3][5]);
        {

        }//błąd - różnica tylko na skrajnie lewym wymiarze
    }

    {
        //Funkcje różniące się jedynie referencją argumentu przy tym sammy typie nie są traktowane jako przeładowane, 
        // gdyż wywołanie nie pozwoli wybrać jednoznacznie jndnej z nich 

        void ggg( int m );
        //! void ggg( int &k )
        {
            //...
        } //błąd

        int m = 10;
        ggg(m);
    }

    {
        //Funkcje różniące się jedynie modfikatorem const lub volatile 
        //argumentu przy tym sammy typie nie są traktowane jako przeładowane, 
        //gdyż wywołanie nie pozwoli wybrać jednoznacznie jednej z nich 
        //- działanie const i volatile odnosi się do kopii argumentu 
        void ggg( int m );
        //! void ggg( const int k );
        {
            //...
        } //błąd

        //! void ggg( volatile int k );
        {
            //...
        } //błąd

        int m = 10;
        ggg(m);
    }

    {
        /*
        Funkcje różniące się modfikatorem const lub volatile argumentu przy tym samym typie,
        ale wskaźnikowym lub referencyjnym są traktowane jako przeładowane, gdyż wywołanie,
        gdyż w tym przypadku działanie const i volatile odnosi się do oryginału zmiennej 
        wstawionej jako argument i zmienna ta musi być zgodna typem z argumentem 
        */
        void ggg( int *m );
        void ggg( const int* k );
        {
            //...
        } //nie ma błędu

        void ggg( volatile int* k );
        {
            //...
        } //nie ma błędu

        int m = 10;
        ggg(&m); // wywołanie pierwszej wesrji

        const int n = 10;
        ggg(&m); // wywołanie drugiej wesrji


        void fff( int &m );
        void fff( const int& k );
        {
            //...
        } //nie ma błędu

        void fff( volatile int& k );
        {
            //...
        } //nie ma błędu

        int m = 10;
        fff(m); // wywołanie pierwszej wesrji

        const int n = 10;
        fff(m); // wywołanie drugiej wersji
    }

}