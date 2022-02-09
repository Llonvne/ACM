// arrstru -- an array of structures
#include <iostream>

struct inflatable {
    char name[20];
    float volume;
    double price;
};

int main(){
    using namespace std;
    inflatable guests[2] = { // initializing an array of structures
        {"Bambi",0.5,21.99}, // 使用多重花括号来初始化结构体数组
        {"Godzilla",2000,565.99}
    };

    cout << "The guest " << guests[0].name << " and " << guests[1].name;
    cout << "\nhave a combined volume of " << guests[0].volume + guests[1].volume;
    cout << " cubic feet.\n";
    
    return 0;
}