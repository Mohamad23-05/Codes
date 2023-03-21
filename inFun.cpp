#include <iostream>
using namespace std;

#define MAX(A,B) ( (A)>(B) ? (A) : (B))
inline int max(int, int);

int main() {

    int x=12,y=24;
    cout << MAX(++x,++y) << '\n'; // Seiteneffekt
    x=23; y=24;
    cout << max(++x,++y) << '\n'; // besser !!!
    return 0;
}

int max(int a, int b)
{
    if (a>b) return a; return b;
}