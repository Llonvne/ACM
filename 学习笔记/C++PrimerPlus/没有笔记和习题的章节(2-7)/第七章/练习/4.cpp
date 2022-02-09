#include <iostream>
using namespace std;

typedef long double ld;

int main() {
    ld rate1 = 47 * 46 * 45 * 44 * 43 / (5 * 4 * 3 * 2 * 1);
    ld rate2 = 27;
    printf("%Lf\n",rate1 * rate2);
    cout << rate2 * rate1 << endl;
}