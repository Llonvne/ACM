#include <iostream>
using namespace std;
const int MAX = 100;
int fill_array(double array[],int n){
    int i;
    for (i = 0; i < n && cin; i++)
    {
        cout << "Please enter a double to fill array (" << n-i << "left): ";
        cin >> array[i];
    }
    return i-1;
}
void show_array(double array[],int n){
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
void reverse_array(double array[], int lo, int hi){
    while (lo < hi){
        swap(array[lo++], array[--hi]);
    }
}
void reverse_array(double array[],int n){
    reverse_array(array, 0, n);
}
int main(){
    double a[MAX];
    int size = fill_array(a,MAX);
    show_array(a,size);
    reverse_array(a,size);
    show_array(a,size);
    reverse_array(a,1,size-1);
    show_array(a,size);
    return 0;
}