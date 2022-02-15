// arfupt.cpp -- an array of function pointer
#include <iostream>
// various notations same signatures
const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);

int main(){
    using namespace std;
    double av[3] = {1112.3, 1542.6, 2227.9};
    
    // pointer to function
    const double *(*p1)(const double *, int) = f1;
    auto p2 = p1; // C++11 automatic type deduction

    cout << "Using pointer to functions" << endl;
    cout << " Address Value\n";
    cout << (*p1)(av,3) << " : " << *(*p1)(av,3) << endl;
    cout << p2(av,3) << " : " << *p2(av,3) << endl;

    // pa an array of pointers
    // 返回值 const double *
    const double * (*pa[3])(const double *, int n) = {f1,f2,f3};
    auto pb = pa; // pa is a array pointer but pb is the first element of the array
    cout << "\nUsing an array of pointers to functions" << endl;
    cout << " Address Value\n";
    for (int i = 0; i < 3; i++)
    {
        cout << pa[i](av,3) << " : " << *pa[i](av,3) << endl;
    }

    // what about a pointer to an array of functions pointer
    cout << "Using  pointers to an array of functions pointer" << endl;
    cout << " Address Value\n";
    // pc 是指向整个函数指针数组的指针 C++11 auto
    auto pc = &pa;
    cout << (*pc)[0](av,3) << " : " << *(*pc)[0](av,3) << endl;
    // pd 与 pc 类型相同 不用auto
    const double *(*((*pd)[3]))(const double *, int n) = &pa;
    const double * pdb = (*pd)[1](av,3);
    cout << pdb << " : " << *pdb << endl;

    cout << (*(*pd)[2])(av,3) << " : " << *(*(*pd)[2])(av,3) << endl;
    return 0;
}

const double * f1(const double * ar, int n){
    return ar;
}
const double * f2(const double * ar, int n){
    return ar + 1;
}
const double * f3(const double * ar, int n){
    return ar + 2;
}