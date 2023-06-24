#include <iostream>
using namespace std;

class Punkt { // Basisklasse
private:
    int i1;
protected:
    int i2;
public:
int x,y;
Punkt(int a=0, int b=0) {
x=a;y=b;
}
virtual void display() { 
cout << "Punkt: x=" << x << " y=" << y <<endl; 
}
};
class Kreis: public Punkt { // Kreis "erbt" von Punkt
public:
int r;
Kreis(int xm, int ym, int rk) {
x=xm; y=ym; r=rk;
}
void display() { 
cout << "Kreis: r=" << r << " Mittel-";
Punkt::display(); //geerbte Funktion
}
};
int main() {
Punkt p(10,10); // Objekt der Basisklasse Punkt
Kreis k(20,20,5); // Objekt der abgeleit. Kl. Kreis
p.display(); k.display(); 
p=k; p.display(); // Wertzuweisung Teilobjekt
return 0;
}