#include<iostream>
#include<fstream>
using namespace std;

void print_bit_representation(char& a)
{
    for(int i = 7; i >= 0; i--)
    {
        cout << (int)((a & (1 << i)) >> i);
    }
    cout << endl;
}

int main()
{
    char a = 0b00000000;

    int i = 0;
    while(true)
    {
        a |= (1 << i);
        print_bit_representation(a);
        // a <<= 1; 
        // print_bit_representation(a);
        i++;
        if(i == 8) break;
    }

    print_bit_representation(a);

    return 0;
}