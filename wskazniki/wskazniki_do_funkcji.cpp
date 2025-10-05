#include <iostream>
using namespace std;

//* definiowanie nazwy wzorca funkcyjnego
// typedef double (*funkcja)(int  x, float y) ;

//lub równoważnie
using funkcja =  double (*)(int  x, float y);

double mul(int x, float y)
{
    return x * y;
}
double add(int x, float y)
{
    return x+y;
}

double gg(funkcja f)
{
    return f(10, 10.89);
}

inline int subtract(int a, int b) //* inline powoduje, że w miejscach, gdzie funkcja jest wywoływana, kompilator skopiuje operacje, które funkcja ma wykonać do miejsca jej wywołania
// jest to szybsze, dzięki temu, że nie trzeba skakać do sekcji kodu tej funkcji w pamięci RAM, ale ma duży wpływ na wielkość pliku .exe
// trzeba z tym uważać w pętlach, gdyż kompilator może sobie z tym nie radzić co w konsekwencji może oznaczać skopiowanie kodu miliony razy
{
    return a-b;
}

int main()
{
    // wskaźnik do jakiejkolwiek funkcji (nazwa pełni rolę nazwy zmiennej) z argumentami typów int i float, która zwraca typ double
    // nawiasy wraz ze wskaźnikiem `(* )` są istotnie, bo inaczej byłabyto deklaracja funkcji
    double (* f)(int x, float y); //* deklaracja zmiennej f, będącej wskaźnikiem do funkcji

    f = &mul; // przypisanie adresu istniejącej funkcji

    double iloczyn = (*f)(10, 10.5);

    f = add; // nazwa funkcji jest wskaźnikiem, więc można to zapisać bez `&` (tak jak tablica)
    // w przypadku metod, operator `&` jest obowiązkowy

    double suma = f(10,10.6); // przy wywołaniu też można pominąć dereferencję

    cout << "iloczyn: "<<iloczyn<<endl;
    cout << "suma: " << suma<< endl;


    funkcja g = &mul;
    cout << g(12, 12.8) <<endl;

    gg(g);

    // grupowanie funkcji w tablice:

    double (*(tab_fun_1[2]))(int x, float y) = {&add, &mul}; // dwuelementowa tablica wskaźników do funkcji

    funkcja tab_fun_2[2] = { &add, &mul};

    cout << tab_fun_1[0](2,3.4)<<endl;
    cout << tab_fun_2[1](4,5.6)<<endl;

    cout << subtract(20,5)<<endl;



    return 0;
}