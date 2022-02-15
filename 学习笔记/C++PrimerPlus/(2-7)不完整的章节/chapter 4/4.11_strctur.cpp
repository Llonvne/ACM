// structcu.cpp -- an simple structure
#include <iostream>
struct inflatable {
    char name[20];
    float volume;
    double price;
};

int main(){
    using namespace std;
    inflatable guest {
        "Llonvne", // name value
        1.99,
        29.99
    };
    inflatable pal {
        "Lcosvle",
        3.12,
        32.99
    };

    cout << "Expand your guest list with " << guest.name << " and "
    << pal.name << endl;
    cout << "You can have both for $";
    cout << guest.price << endl;
    return 0;

}