#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int losuj(int a, int b)
{
    int result = a + rand()%(b-a+1);
    return result;
}

double losuj(double a, double b)
{
    double result = a + (double)rand()/RAND_MAX * (b - a);
    return result;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "");
    cout << "Wartości losowe z zakresu 50 - 100: \n";
    for(int i = 0; i < 10; i++)
    {
        cout << losuj(50, 100) << endl;
    }
    for(int i = 0; i < 10; i++)
    {
        cout << losuj(50.0, 100.0) << endl;
    }
    return 0;
}