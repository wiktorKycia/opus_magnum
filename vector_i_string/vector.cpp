#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    vector<double> czynniki;
    vector<string> uczestnicy_wyprawy;
    vector<string> kompozytorzy { "F. Chopin", "J.S. Bach", "B. Bartok", "C. Debussy"};

    vector<int> ww {8, 2,5,3,-2,10};
    cout << "ww[1]="<<ww[1]<<endl;

    int rozmiar = ww.size();
    cout << "Wektor ww ma elementow: " << rozmiar << endl;

    for(int i = 0; i < ww.size(); ++i)
    {
        cout << ww[i] << ", ";
    }
    cout << endl;

    vector<char> symbole(10); 
    vector<char> litery(12, '.'); // wypełnia 12-elementowy wektor kropkami

    cout << symbole.size() << endl;
    litery[0] = 'A';
    for(int i = 0; i < litery.size(); i++) cout << litery[i] ;
    cout << endl;

    cout << kompozytorzy.size();
    kompozytorzy.push_back("ABC");
    cout << kompozytorzy.size();

    for(string &k: kompozytorzy)
    {
        k = "aaa";
    }
    for (auto k: kompozytorzy)
    {
        cout << k << endl;
    }
    
    return 0;
}