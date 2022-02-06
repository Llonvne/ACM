// fun_ptr.cpp pointers to function
#include <iostream>
using namespace std;

double betsy(int);
double pam(int);

void estimate(int lines, double (*pf)(int));

int main(){
    using namespace std;
    int code;
    cout << "How many lines of code do you need?" << endl;
    cout << ">>> ";
    cin >> code;

    cout << "Here are betsy estimate:\n";
    estimate(code, betsy);
    cout << "Here are pam estimate:\n";
    estimate(code, pam);

    return 0;
}

double betsy(int lns){
    return 0.05 * lns;
}

double pam(int lns) {
    return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int)){
    using namespace std;
    cout << lines << " line will take ";
    cout << pf(lines) << " hour(s)\n" << endl;
}