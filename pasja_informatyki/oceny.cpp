#include<iostream>

using namespace std;

constexpr int number_of_grades = 10;
float grades[number_of_grades];
double average = 0;

int main()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");
    for (int i = 0; i < number_of_grades; i++)
    {
        cout << endl << "Podaj "<<i+1<<" ocenę: ";
        cin >> grades[i];
        average += grades[i];
    }
    average /= number_of_grades;
    cout << "Twoja średnia ocen to: " << average << endl;

    return 0;
}