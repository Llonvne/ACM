#include <iostream>
using namespace std;
int main(){
    int arr[100];
    // arr 是指向数组第一个元素的指针
    // &arr 是指向整个数组的指针
    cout << "arr = " << arr << endl;
    cout << "&arr = " << &arr << endl;

    cout << "sizeof(arr) = " << sizeof(arr) << endl;
    cout << "sizeof(&arr) = " << sizeof(&arr) << endl;

    // arr + 1 会第二个元素处
    // &arr + 1 会到数组结尾后一个元素
    cout << "arr + 1 = " << arr + 1 << endl;
    cout << "&arr + 1 = " << &arr + 1 << endl;
}