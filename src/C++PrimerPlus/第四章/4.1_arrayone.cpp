// arrayone.cpp -- small arrays of intergers
#include <iostream>
int main(){
    using namespace std;
    int yam[3];
    // you can also use
    // int yam[3]{7,8,6}; // bat the {} for initialization will not allow narrow 
    // like this ： int yam[3]{7.8,7.9,7.0}; // this will be error;
    //int yam[3]{7.8,7.9,7.0};
    yam[0] = 7;
    yam[1] = 8;
    yam[2] = 6;

    int yamcost[3] = {20,30,5};

    cout << "Total yams = " << yam[0] + yam[1] + yam[2] << endl;
    cout << "The package with " << yam[0] << " yams costs ";
    int total = yamcost[0] * yam[0] + yamcost[1] * yam[1] + yamcost[2] * yam[2];
    cout << yamcost[0] * yam[0] << endl ;
    cout << "The total yam expenses " << total << "cents" << endl;

    cout << "\nSize of yams array = " << sizeof yam;
    cout << " bytes.\n" << "Size of one element = " << sizeof yam[0];
    cout << " bytes.\n";

    return 0;
}