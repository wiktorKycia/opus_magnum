#include<iostream>
using namespace std;
int main()
{
    double pi = 3.14;
    int m;
    m = static_cast<int>(pi); // kompilator uwierzy nam na słowo, że taka operacja ma sens

    cout << "int pi: " << m << endl << "pi: " << pi << endl;
    //* static_cast jest do sytuacji możliwych lub możliwych w pewnych sytuacjach

    return 0;
}