#include<iostream>
using namespace std;
int main()
{
    cout << "start";
    if('\0') // '\0' is false
    {
        cout << "to jest prawda";
    } 
    if ('0') // '0' is true because its ASCII value is non-zero
    {
        cout << "0 to falsz, a 0 to prawda"; // jak zapiszemy \0 to nic po nim się nie wyświetli
    }
    if ('a') // 'a' is true because its ASCII value is non-zero
    {
        cout << "a to prawda";
    }
    else 
    {
        cout << "nie ma prawdy";
    }
    if(-1)
    {
        cout << "liczba -1 to prawda";
    }

    cout << endl << endl;

    int day = 7;
    // constexpr int seven{7};
    constexpr int seven = 3+4;
    switch(day)
    {
        case 1: cout << "Monday\n"; break;
        case 2: cout << "Tuesday\n"; break;
        case 3: cout << "Wednesday\n"; break;
        case 4: cout << "Thurdsay\n"; break;
        case 5: cout << "Freeday\n"; break;
        case 6: cout << "Saturnday\n"; break;
        case seven: cout << "Sunday\n"; break;
        default: cout << "you stoo pid!!!";
    }
    return 0;
}