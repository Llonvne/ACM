// convert.cpp -- convert stone to pound
#include <iostream>
int stonetolb(int); // function prototype
int main(){
    using namespace std;
    int stone;
    cout << "Enter the weight in stone : ";
    cin >> stone;
    int pounds = stonetolb(stone);
    cout << stone << " stone = ";
    cout << pounds << " pounds" << endl;
    return 0;
}
int stonetolb(int stone){
    return 14 * stone;
}
