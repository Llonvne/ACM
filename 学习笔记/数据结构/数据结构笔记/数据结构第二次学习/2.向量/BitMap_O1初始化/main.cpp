#include <iostream>
#include "BitMap_O1.h"
using namespace std;
int main()
{
    BitMap<int> a(100001);
    a.set(100000);
    cout << a.test(100000) << endl;
    cout << a.test(1) << endl;
    a.set(999);
    cout << a.test(999) << endl;
    cout << a.test(998) << endl;
}
