#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <limits>

using namespace std;

int main()
{
    // vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    
    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }
    // cout << endl;

    uint64_t zmienna = 10000000000;
    cout << numeric_limits<decltype(zmienna)>::max();


    return 0;
}
// /usr/bin/g++ -g main.cpp -o main // or ctrl + shift + B
// ./main