#include "bits/stdc++.h"

using namespace std;

int GetNumberBits(int number);
int GetBitsPerNumberSumMax(int bits);
int GetDigitsSum(int number);

int caseCount;
int input;

int main(){

    scanf("%d",&caseCount);

    while(caseCount--){

        scanf("%d",&input);

        int inputBits = GetNumberBits(input);
        int bitsPerNumberSumMax = GetBitsPerNumberSumMax(inputBits);
        int minPossibleGenerator = input - bitsPerNumberSumMax;

        int findFlag = false;
        for (int i = minPossibleGenerator; i < input; i++) {

            int Total = GetDigitsSum(i) + i;

            if (Total == input){
                printf("%d\n",i);
                findFlag = true;
                break;
            }
        }
        if (!findFlag){
            printf("0\n");
        }
    }
}

int GetNumberBits(int number){
    int Bits = 0;
    while(number){
        Bits ++ ;
        number /= 10;
    }
    return Bits;
}

int GetBitsPerNumberSumMax(int bits){
    return bits * 9;
}

int GetDigitsSum(int number){
    int sum = 0;
    while(number){
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
