// assign_st.cpp -- assigning structure
#include <iostream>

struct inflatable {
    char name[20];
    float volume;
    double price;
};

int main(){
    using namespace std;
    inflatable bouquet {
        "sunflower",
        0.20,
        12.40
    };
    inflatable choice;
    cout << "bouquet : " << bouquet.name << " for $" << bouquet.price << endl;

    choice = bouquet;
    cout << "choice : " << choice.name << " for $" << choice.price << endl;

    return 0;
}