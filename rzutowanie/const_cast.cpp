#include<iostream>
using namespace std;
int main()
{
    const double staly = 15.64;
    double zwykly;
    
    double const * wsk_staly = &staly; // wskaźnik do stałego double 

    //* dzięki const_cast kompilator pozwoli zapisać adres stałego obiektu do zwykłego wskaźnika


    //przyklad:

    double zmienna = 0;
    const double stala = 3.14;

    double *wsk_do_zmiennej = &zmienna;
    const double *wsk_do_stalej = &stala;
    
    const double *wsk2_do_stalej;

    cout << "Na początku, stala = " << stala << endl;

    wsk2_do_stalej = wsk_do_zmiennej;
    // wsk_do_zmiennej = wsk_do_stalej; //! błąd
    wsk_do_zmiennej = const_cast<double *>(wsk_do_stalej); // konwertuje wskaźnik do stałej (const double *) na wskaźnik (double *)

    *wsk_do_zmiennej = -333;
    cout << "Potem ------> stala = " << stala << endl;

    // stały (nieruchomy) wskaźnik do zmiennej
    // usuwamy stałość stałej, a nadajemy stałość (nieruchomość) wskaźnika

    double * const st_wsk_do_zmiennej = const_cast<double * const>(wsk_do_stalej);
    wsk_do_zmiennej = st_wsk_do_zmiennej;

    return 0;
}