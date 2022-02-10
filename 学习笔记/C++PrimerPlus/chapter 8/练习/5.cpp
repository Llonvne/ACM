#include <iostream>
using namespace std;
template <typename T>
T max5(T arr[],int n = 5){
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

int main(){
    int arr[] = {1,2,3,4,5};
    double arr2[] = {1.0,2.0,3.0,4.0,5.0};
    cout << max5(arr) << endl;
    cout << max5(arr2);
}