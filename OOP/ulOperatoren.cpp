#include <iostream>
using namespace std;
class Ckompl { // komplexe Zahlen
public:
	int r, i; // real,imaginär
	Ckompl() { r = 0; i = 0; }
	Ckompl(int rr, int ii) {
		r = rr; i = ii;
	}
	//unäre Operatoren brauchen keinen Parameter
	Ckompl operator~() { // Negation
		return Ckompl(-r, -i);
	}
	//binäre Operatoren haben zwei Operanden!!
	Ckompl operator+(const Ckompl& a) {
		return Ckompl(r + a.r, i + a.i);
	}
    Ckompl operator+(const int a){
        return Ckompl(r+a,i);
    }
    Ckompl& operator()(int rr, int ii) {
        r=rr, i=ii;
        return *this;
    }
};

class CVektor50 { 
public:
    CVektor50(); ~CVektor50();
    int& operator[](int);
private:
    int vek[50];
    int anz; 
};

CVektor50::CVektor50() { 
    anz=50;
    for(int i=0;i<anz;i++) vek[i]=i;
}
CVektor50::~CVektor50(){}
int& CVektor50::operator[](int i) {
    if ((i<0)||(i>=anz)){
        cout << "Der DAP hat zugeschlagen" << endl;
        exit(1); // Fehlerbehandlung :-) return vek[i];
    }
    return vek[i];
}

int main() {
	// Ckompl x(1, 2), y; 
	// //y = x.operator~(); // Memberfunktion
	// y = ~x; // besser
	// cout << "y.r: " << y.r << endl;
	// cout << "y.i: " << y.i << endl;

    // Ckompl a(1, 2), b(3, 4), e;
	// e = a + b;
	// cout << "e.r " << e.r << endl;
	// cout << "e.i " << e.i << endl;
    // e = a +1;
    // cout << "e.r " << e.r << endl;
	// cout << "e.i " << e.i << endl;

    // Ckompl f(1,2),g; // Konstruktor
    // g=f(3,4); // mehrstelliger Operator
    // cout << "f.r " << f.r << endl;
    // cout << "f.i " << f.i << endl;
    // cout << "g.r " << g.r << endl;
    // cout << "g.i " << g.i << endl;

    // CVektor50 v;
    // cout << "Der Teil-Vektor\n";
    // for(int i=0;i<5;i++) {
    //     printf(" v[%d] = %d\n",i,v[i]);
    // }
    // v[1]=99;
    // for(int i=0;i<5;i++) {
    //     printf(" v[%d] = %d\n",i,v[i]);
    // }
    
}