#include<iostream> // cin, cout, cerr, clog
#include<iomanip> // setprecision, fixed, setw
#include<fstream> // file streams
#include<sstream> // string streams
#include<vector> // adds vector
#include<codecvt> // for converting between character encodings
#include<cstdio> // for C-like i/o operations (printf, scanf)
//#include "tinyutf8.h" // handling utf8 strings
#include<string>

using namespace std;

/* tryby zapisu:
ios::out
    - opens for writing
    - if the file exists the content is truncated unless combined with ios::app
    - if the file does not exists it creates it

ios::in
    - opens for read
    - the file must exists, otherwise: error

ios::app
    - appending
    - data is added at the end
    - file created if not exists

ios::truncates
    - truncates the file
    - usually combined with ios::out

ios::ate
    - read and write
    - pointer position at the end

ios::binary
    - opens in binary mode
    - read/write binary data
    - without this mode the new lines may be translated (e.g. \n to \r\n on Windows)
*/

int main()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");
    ofstream outputFile;

    const char* fileName {"output.txt"};

    outputFile.open(fileName, ios::out | ios::trunc);

    if(!outputFile.good())
    {
        cout << "Błąd otwarcia pliku: " << fileName << endl;
        exit(1);
    }

    string answer;
    vector<string> shopping_list;
    do
    {
        cout << "Co na liste zakupów: ";
        cin >> answer;
        shopping_list.push_back(answer);

    } while (answer!="koniec");
    

    for(string item : shopping_list)
    {
        outputFile << item << endl;
    }
    outputFile.close();

    return 0;
}