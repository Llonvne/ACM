#include <iostream>
#include <array>
#include "golf.h"
int main()
{
    golf g{"Llonvne",100};
    g.show();
    g.set("Lcosvle",109);
    g.show();
    std::array<golf,2> golfs;
    for (auto & i : golfs){
        i.set();
    }
    for (const auto & i : golfs){
        i.show();
    }
    return 0;
}
