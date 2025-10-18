#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

int main()
{
    // Zapis
    string fileName{"dane.bin"};
    ofstream file;

    file.open(fileName, ios::out | ios::binary | ios::trunc);

    // dane do zapisu:
    struct Person
    {
        string name;
        string surname;
        double height;
        int age;
    };

    double d{12.123456};
    int n{12345};
    string text {"Mężny bądź chroń pułk swój i sześć flag"};
    Person person {"Grzegorz", "Brzężeszczykiewicz", 176.5, 40};

    file.write((char*)&d, sizeof(double)); // konwersja na wskaźnik do char, czyli trzeba podać adres
    file.write((char*)&n, sizeof(int));

    int text_length = text.size();

    file.write((char*)&text_length, sizeof(int));
    file.write((char*)text.data(), sizeof(char) * text_length);

    // file.write((char*)&person, sizeof(Person)); // w ten sposób zamiast pól stringowych (w sensie ich danych) zostaną zapisane tylko wskaźniki do ich lokacji w RAM-ie

    // Serialize Person
    int name_length = person.name.size();
    int surname_length = person.surname.size();

    file.write((char *)&name_length, sizeof(int));
    file.write((char *)person.name.data(), sizeof(char) * name_length);

    file.write((char *)&surname_length, sizeof(int));
    file.write((char *)person.surname.data(), sizeof(char) * surname_length);

    file.write((char *)&person.height, sizeof(double));
    file.write((char *)&person.age, sizeof(int));
    
    file.close();

{
    // Odczyt
    
    ifstream file;
    file.open(fileName, ios::in | ios::binary);
    
    double d;
    int n, text_length;
    string text;
    Person person;
    
    file.read((char*)&d, sizeof(double));
    file.read((char*)&n, sizeof(int));

    file.read((char*)&text_length, sizeof(int));
    text.resize(text_length);
    file.read((char*)&text[0], text_length); // tu też korzystamy z tego, że char ma 1B (mogło by być sizeof(char) * text_length)

    // file.read((char*)&person, sizeof(Person));

    // Deserialize Person
    int name_length_in, surname_length_in;

    file.read((char *)&name_length_in, sizeof(int));
    person.name.resize(name_length_in);
    file.read((char *)&person.name[0], name_length_in);

    file.read((char *)&surname_length_in, sizeof(int));
    person.surname.resize(surname_length_in);
    file.read((char *)&person.surname[0], surname_length_in);

    file.read((char *)&person.height, sizeof(double));
    file.read((char *)&person.age, sizeof(int));
    
    cout << d << endl;
    cout << n << endl;
    cout << text << endl;
    cout << person.age << endl << person.name << endl << person.surname << endl << person.height << endl;

    file.close();

}


    return 0;
}