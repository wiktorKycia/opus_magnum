#include<iostream>
#include<string>

using namespace std;

int main()
{
    string solar {"Panel-sloneczny"}; 
    string antena ("Antena"); // starszy (odradzany) sposób pisania inicjalizacji
    cout << "Napisz, jak masz na imie: ";
    string imie; // wstêpnie pusty 
    cin >> imie;
    cout << "Sterowanie sonda kosmiczna przejal wlasnie " << imie << endl;

    if(imie == "Jurek") 
    {
        cout << "(To jest najgorszy pilot)\n";
    }

    string rozkaz;
    rozkaz = "Naprawic " + solar; 
    string komunikat = antena + " dziala poprawnie"; // "Antena dziala poprawnie"

    rozkaz += " natychmiast"; // doczepienie do koñca 
    cout << rozkaz << endl;

    rozkaz = komunikat; 
    cout << rozkaz << endl;

    string raport = "Alfabetycznie wczesniej jest: ";
    if(solar < antena)
        raport += solar;
    else
        raport += antena; 
    
    cout << raport << endl;


    komunikat = "Sprawdzone juz zostaly segmenty: ";
    for(int nr_segm = 39 ; nr_segm < 42 ; ++nr_segm) 
    {
        string liczba_tekstowo = to_string(nr_segm); 
        string element = antena + liczba_tekstowo; 
        string nazwa_pliku = element + ".txt"; 
        cout << " Test segmentu " << nr_segm << " zapisany w pliku c:\\" << nazwa_pliku << endl; 
        komunikat += ( element + ", " ); 
    }

    cout << komunikat << endl; 
    //------------------
    string info = " NIE DZIALA Antena satelitarna "; 

    // tworzenie tekstu alarmowego w ramce
    int szer = info.size() + 6; 
    string kreska (szer, '*'); //* fajny sposób na tworzenie stringów z pojedyńczego znaku
    string alarm = kreska + "\n";
    alarm += "*!*" + info + "*!*\n";
    alarm += kreska;
    cout << alarm << endl;

    return 0;
}