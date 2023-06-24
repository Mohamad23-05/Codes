#include <iostream>
#include "string"
using namespace std;

/*   
class Date {
    public: // *** "außen" sichtbare Elemente
        Date(); // Konstruktor
        Date(int, int, int); // Konstruktor
        void display() const ; // Methode
        ~Date(); // Destruktor
    private: // *** "private" Datenelemente, Methoden
        int day, month, year;
        int min(int, int); // Hilfsfunktion
        int max(int, int); // Hilfsfunktion
};

int Date::max(int a,int b) { return a>b ? a:b; }
int Date::min(int a,int b) { return a<b ? a:b; }

Date::Date() {
day = month = year = 1;
}
Date::Date(int d, int m, int y) { // ohne Schaltjahre !!!
    static const int length[]={31,28,31,30,31,30,31,31,30,31,30,31};
    month = max(1,m); month = min(month,12);
    day = max(1,d); day = min(day, length[month-1]);
    year = max(1,y);
}
Date::~Date() { } // Funktion tut nichts
void Date::display() const {
    static const char *name[] = {
    "Januar", "Februar", "März", "April", "Mai", "Juni",
    "Juli", "August", "September", "Oktober", "November", "Dezember" };
    cout << day << '.' << name[month-1] << ' ' << year << endl;
}
*/
class CString { 
    public:
        CString();
        CString(const char*);
        ~CString();
        CString(const CString&);
        void display();
        void append(const char*);
        CString &operator=(const CString &src);
    private:
        int length;
        char *buf;
};

CString::CString(){
    length =0;
    buf = new char[1];
    buf[0] = '\0';
}
CString::CString(const char *s) {
    length=strlen(s);
    buf = new char[length +1];
    strcpy(buf,s);
}
CString::~CString(){
    delete[] buf; //auch problemlos wenn buf == 0 //wegen Vektor!!
}

void CString::append(const char *add) {
    int old=length;               // alte Länge merken length+=strlen(add); // neue Länge berechnen
    char *tmp=new char[length+1]; // neuen Speicher belegen
    strcpy(tmp,buf);              // alten String kopieren
    delete[] buf;                 // "alten" Speicher freigeben
    strcpy(tmp+old,add);          // neuen String anhängen
    buf=tmp;                      // neue Adresse übernehmen
}
CString &CString::operator=(const CString &src) { //Zuweisungsoperator überschreiben pdf '4' Folie 8
    if(&src != this){
        delete[] buf;                 // ursprünglichen Speicher freigeben
        length = src.length;          // neue Länge
        buf = new char[length+1];     // neuer Speicher 
        strcpy(buf,src.buf);          // Zeichenkette kopieren
    }
    return *this;
}
CString::CString(const CString &src) {
    length = 0;
    buf = 0;
    *this = src; // "="-Operator nutzen
}
void CString::display() { 
    cout << buf << endl;
}

/*
    - Klassen mit Zeigern auf dynamischen Speicher brauchen
        - einen eignen einen eigenen Zuweisungsoperator
        – einen eigenen Kopier-Konstruktor
        – einen eigenen Destruktor
*/
int main() {
    CString s1, s2("Hallo"), s3;
    s2.append(" Du!");
    s2.display();
    s1 = s2; //s1.operator=(s2);
    s1.display();
    s3 = s2 = s1; //Mehrwachzuweiung
    s3.display();
    CString s4 = s1; //Kopie-Konstruktur überschreiben
    s4.display();
}