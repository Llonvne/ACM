#include <iostream>
#include <string>
using namespace std;

struct box {
    string maker;
    float height;
    float width;
    float length;
    float volume;
};

void by_value_transfer(box b){
    cout << "maker : " << b.maker << endl;
    cout << "height : " << b.height 
    << " width : " << b.width 
    << " length : " << b.length 
    << " volume :" << b.volume << endl;
}

void by_address_transfer(box * b){
    b->volume = b->height * b->width * b->length;
    cout << "maker : " << b->maker << endl;
    cout << "height : " << b->height 
    << " width : " << b->width 
    << " length : " << b->length 
    << " volume :" << b->volume << endl;
}

int main(){
    box b;
    b.maker = "llonvne";
    b.height = 10;
    b.length = 11;
    b.width = 13;
    cout << "By address transfer:" << endl;
    by_address_transfer(&b);
    cout << "By value transfer:" << endl;
    by_value_transfer(b);

    return 0;
}