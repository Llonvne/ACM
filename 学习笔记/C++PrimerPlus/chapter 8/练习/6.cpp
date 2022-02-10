#include <iostream>
#include <array>
using namespace std;

template <typename T>
T maxn(T arr[],int n){
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }
    return arr[max];
}
template <> const char * maxn(const char *arr[],int n){
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (strlen(arr[i]) > strlen(arr[max]))
        {
            max = i;
        }
    }
    return arr[max];
}

int main(){
    int arr[] = {1,2,5};
    cout << maxn(arr,3) << endl;
    const char * arr1[] = {"123","12345","12345678990"};
    cout << maxn(arr1,3) << endl; 
}

extern "C++" int getNumer();
void operator delete[] (int a){

}