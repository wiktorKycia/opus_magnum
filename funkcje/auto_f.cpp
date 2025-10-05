#include<iostream>
using namespace std;

double mul (int  x, float y)
{
	return x * y;
}


auto add(int x, int y) -> decltype(x)//typ zwracanego obiektu będzie zawsze zgodny z typem argumentu
{
	return x + y;
}
//W powyższym przypadku typy argumentów są znane, więc można by jawnie  określić typ funkcji,
//Niemniej w przypadku szablonów (ten materiał będzie w drugim semestrze) ogólnie typy są nieznane
//w momencie definicji szablonu


using typ_funkcji = decltype(&add); //typ_funkcji zawsze będzie zgodny z wzorcem funkcji add()

int a = 10;

decltype(a) b; // zmienna b będzie zawsze zgodna typem ze zmienną a

auto suma = add(10, 10);


using typ_funkcji = decltype(&add); //typ_funkcji zawsze będzie zgodny z wzorcem funkcji add()
double gg(typ_funkcji f) // `typ_funkcji` można zastąpić od razu decltype-m
{
	return f(10, 18.9);
}



constexpr double mile_na_kilometry(double mil)
{
	return (1.609344 * mil);
}
/*
1.każdy argument aktualny (wywołania) funkcji musi być wyrażeniem constexpr (lub po prostu stałą) lub referencją do obiektu constexpr
2.rezultat funkcji (czyli to, co stoi przy instrukcji return) musi być wyrażeniem constexpr (a zatem funkcja constexpr nie może zwracać typu void ) 
3.ciało funkcji constexpr może zawierać:
    tylko jedną instrukcję return
    puste instrukcje (czyli sam średnik)
    proste deklaracje typedef
    deklaracje using
    dyrektywyusing
    wyrażenia warunkowego, czyli operatora ( ? : ) 

4.Funkcje constexpr muszą być od razu definiowane, gdyż są obliczane w czasie kompilacji
5.Funkcja constexpr nie może mieć żadnych efektów ubocznych, czyli w jej ciele nie możemy próbować modyfikować żadnych zmiennych będących poza jej własnym ciałem. 
*/






bool zwykla_funkcja(char pierwszy, char drugi)
{
    cout << "Dziwna sytuacja dla " << pierwszy << " i " << drugi << endl;
	return false;
}

constexpr bool czy_alfabetycznie(char a, char b)
{
	return a < b ? true : zwykla_funkcja(a,b);//potencjalnie zabroniony element: zwykla_funkcja
}

//Wywołanie

constexpr bool r = czy_alfabetycznie('a', 'z');

/*Powyższe wywołanie nie spowoduje błędu kompilatora, gdyż wartość parametrów oznacza,
że ta funkcja może byż wywołana dopiero w czasie wykonywania programu.*/

// constexpr int odp2 = czy_alfabetycznie('z', 'm');//!błąd

//Powyższe wywołanie  spowoduje błąd kompilatora


constexpr double wbezwzgledna(const double & n)
{
	return n < 0 ? -n : n;
}

//Powyższa funkcja jest zabezpieczona przed modyfiakcją obiektu przekazywanego w argumencie
//przez referencję  dzięki  zastosowaniu stałej referencji



int main()
{
    // można automatycznie odczytać typ wskaźnika słowem kluczowym `auto`
    auto * f = & mul;

    auto iloczyn = f(10,20);


    //Wywołanie
    constexpr double buty_kilometrowe = mile_na_kilometry(7);

    constexpr double dystans_mile = 2614;

    constexpr double dystans_km = mile_na_kilometry(dystans_mile);



    return 0;
}