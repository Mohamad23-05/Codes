//02Referenzen

#include <iostream>
using namespace std;

//call by value
void fkt_v(float f)
{
    f = 3.4f;
}

//call by reference
void fkt(float *f)
{
    *f = 3.4f;
}

//call by reference - mit Rerefernzvariale
void fkt_r(float &f)
{
    f = 3.4f;
}

int main() {

 int i =123;
 int &iref=i;
 float f2 = 2.3f;

 fkt_r(f2);
 cout << i << ' ' << iref << endl;
 cout << (&i) << ' ' << (&iref) << endl;

 return 0;

}