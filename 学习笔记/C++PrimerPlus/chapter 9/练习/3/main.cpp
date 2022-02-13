#include <iostream>
struct chaff {
    char dross[20];
    int slag;
};
char buffer[5 * sizeof(chaff)];
int main()
{
    using namespace std;
    chaff *c = new(buffer)chaff[2];
    strcpy(c[0].dross,"Llonvne");
    c[0].slag = 1;
    strcpy(c[1].dross,"Lcosvle");
    c[1].slag = 1;

    for (int i = 0; i < 2; ++i) {
        cout << c[i].dross << " " << c[i].slag << endl;
    }
    return 0;
}
