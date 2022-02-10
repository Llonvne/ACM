#include "1.cpp"
#include <string>

struct CandyBar {
    string brand;
    float weight;
    int calories;
};

void initCandyBar(CandyBar & candyBar,const string& brand,float weight,int calories){
    candyBar.brand = brand;
    candyBar.calories= calories;
    candyBar.weight= weight;
}

void displayCandyBar(const CandyBar & candyBar){
    cout << "品牌: ";
    print(candyBar.brand.c_str()); // use 1.cpp print function
    cout << endl << "重量: ";
    cout << candyBar.weight;
    cout << endl << "热量: ";
    cout << candyBar.calories << endl;
}

int main(){
    CandyBar candyBar;
    initCandyBar(candyBar, "Millennium Munch",2.85,350);
    displayCandyBar(candyBar);
}
