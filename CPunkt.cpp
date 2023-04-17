#include <iostream>
using namespace std;

class CPunkt{
    public:
        CPunkt(int xp, int yp);
        void display();
        CPunkt();
        ~CPunkt();
    private:
        int x,y;
};
CPunkt::CPunkt() { x=y=0;}
CPunkt::CPunkt(int xp, int yp) { x=xp; y=yp;}

CPunkt::~CPunkt(){}

void CPunkt::display() {
    cout << "Punkt: x=" << x << " y=" << y << endl;
}



class CLinie{ 
    public:
        void display();
        CLinie(const CPunkt &p1p,const CPunkt &p2p); 
        CLinie();
        ~CLinie();
    private:
        CPunkt p1,p2;
    };
    CLinie::CLinie() {}
    
    CLinie::CLinie(const CPunkt &p1p, const CPunkt &p2p) :p1(p1p), p2(p2p) {}
    
    CLinie::~CLinie() {}
    
    void CLinie::display(){
        cout << "Linie:" << endl; p1.display(); p2.display();
    }

class CKreis { public:
    CKreis(const CPunkt &p, int r); CKreis();
    ~CKreis();
    void display();
    private:
    int radius; CPunkt m;
};
    CKreis::CKreis() { radius=0; }
    CKreis::CKreis(const CPunkt &p, int r) :m(p) { radius=r;}
    CKreis::~CKreis() {}
    void CKreis::display() {
    cout << "Kreis: " << endl; m.display(); cout << "Radius: " << radius << endl;}


class CContainer { 
    public:
        bool Insert(const CLinie &l);
        bool Insert(const CKreis &k);
        void display(); CContainer();
        ~CContainer();
    private:
        CLinie lvek[100]; int lvekanz; CKreis kvek[100]; int kvekanz;
};

CContainer::CContainer() { kvekanz = lvekanz = 0;}

CContainer::~CContainer() {}

void CContainer::display() { 
    int i;
    cout << "Container: " <<  endl;
    for(i=0; i<lvekanz; i++) lvek[i].display();
    for(i=0; i<kvekanz; i++) kvek[i].display();
}
bool CContainer::Insert(const CLinie &l) { 
    if (lvekanz==100) return false; lvek[lvekanz++]=l;
    return true;
}
bool CContainer::Insert(const CKreis &k) {
    if (kvekanz==100) return false; kvek[kvekanz++]=k;
    return true;
}
int main()
{

    CContainer c1;
    for(int i=0; i<10; i++) {
    c1.Insert(CLinie(CPunkt(rand()%100,rand()%100),
                     CPunkt(rand()%100,rand()%100)));
    c1.Insert(CKreis(CPunkt(rand()%100,rand()%100), rand()%100));
    }    c1.display();
    //c.display();
    //k.display();
}