//01Einführung_2
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello world\n";
    int zahl=123;
    char name[20];
    //Zahleneingabe:
    
    cout << "Die Zahl: " << zahl <<" ist eine dreistellige Zahl\n" << endl;
    cout << dec << zahl << ' '
         << oct << zahl << ' '
         << hex << zahl << endl;
    
    cout << "Geben Sie eine Zahl ein: ";
    cin >> zahl;
    cout << "Die zahl: " << zahl << endl;    

    //Nameeingabe:
    cout << "Geben Sie ihren Name ein: ";
    cin >> name;
    cout << "Der Name ist: " << name << endl;

    //Schlüsselwort --- const ---
    const int maxzahl=20;
    float zahle[maxzahl];

    // konstanter Zeiger auf ein Zeichen
    char c='c',d='d';
    char* const ptr=&c;
    *ptr='a'; // Verändern worauf ptr zeigt: OK
    //ptr=&d;  // Verändern des Zeigers: ERROR

    return 0;
}

