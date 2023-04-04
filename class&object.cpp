#include <iostream>
using namespace std;

/*
struct date
{
	int day, month, year;
};
void set_date(struct date *dt,int d, int m, int y)
{
	dt->day = d;
	dt->month = m;
	dt->year = y;
};

void display_date(struct date* dt)
{
	static char* name[] = {
		"J","F","Mz","Ap","Ma","Jn","Jl","Se","Ok","Nov","Dez"
	}
	printf("%d. %s %d", dt->day.name[dt->month - 1], dt->year);
}
*/

class Date {
public: // *** "au�en" sichtbare Elemente
	Date(); // Konstruktor
	Date(int, int, int); // Konstruktor
	void display(); // Methode
	~Date(); // Destruktor
private: // *** "private" Datenelemente, Methoden
	int day, month, year;
	int min(int, int); // Hilfsfunktion
	int max(int, int); // Hilfsfunktion
};

//Hilfsfunktion
int Date::max(int a, int b) { return a > b ? a : b; }
int Date::min(int a, int b) { return a < b ? a : b; }

//StandardKonstruktur
Date::Date()
{
	day = month = year = 1;
}

Date::Date(int d, int m, int y)
{
	static int length[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	month = max(1, m); month = min(month, 12);
	day = max(1, d); day = min(day, length[month - 1]);
	year = max(1, y);
}

// Destruktor
Date::~Date(){}

void Date::display()
{
	static const char* name[] = {
		"J","F","Mz","Ap","Ma","Jn","Jl","Se","Ok","Nov","Dez"
	}
	cout << day << ". " << name[month - 1] << ' ' << year << endl;
}
int main()
{
	Date d1; //Objekt von Date

}