// when D > C
#include <iostream>
using namespace std;
int main(){
    double D = 100;
    double C = 100;
    int years = 0;
    while (C <= D){
        D += 100*0.1;
        C += C*0.05;
        printf("years: %2d,C has $%5.2f,D has $%5.2f.\n", ++years, C, D);
    }
    printf("Ohhhhh!!!! years: %2d,C has $%5.2f,D has $%5.2f.C is more rich!!\n", years, C, D);

    return 0;
}