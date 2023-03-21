
#include <iostream>
using namespace std;

/*
beachte:
wird ein Argument weggelassen müssen auch alle folgenden weggelassen werden !!
*/
void show(int =1, float =2.3f, long =4L);
int z=11;
int main() {
    int z=12;
    cout << "zahl global: " << ::z << endl; //Zugriffoperator :: auf globale Variable zuzugreifen.
    cout << "zahle lokal: " << z << endl;
    show();
    show(5);
    show(5,7.8f);
    show(5,9.9f,12L);
    // show(,,12L); ist nicht erlaubt
    return 0;
}

void show(int first, float sec, long third)
{
    cout << first << ' ' << sec << ' '
        << third << endl;
}