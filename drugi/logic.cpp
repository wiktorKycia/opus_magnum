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
    return 0;
}