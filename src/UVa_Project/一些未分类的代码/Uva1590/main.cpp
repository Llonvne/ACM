#include "bits/stdc++.h"
using namespace std;

#define MAX_IP_COUNT 1000

struct Address{
    int b1,b2,b3,b4;
};
Address ip[MAX_IP_COUNT];
int ipCount;

int InputIp();
int GetDifference();


int GetDigits(int number){
    int digits = 0;
    while(number > 0){
        number/=10;
        digits++;
    }
    return digits;
}

bool operator<(Address add1,Address add2){
    if (add1.b1 != add2.b1){
        return add1.b1 < add2.b1;
    }
    else if (add1.b2 != add2.b2){
        return add1.b2 < add2.b2;
    }
    else if (add1.b3 != add2.b3){
        return add1.b3 < add2.b3;
    }
    else if (add1.b4 != add2.b4){
        return add1.b4 < add2.b4;
    }
    return false;
}
bool operator-(Address add1,Address add2){
    if (add1.b1 != add2.b1){
        int buffer = abs(add1.b1 - add2.b1);
        return GetDigits(buffer) - 1;
    }
    else if (add1.b2 != add2.b2){
        int buffer = abs(add1.b2 - add2.b2);
        return GetDigits(buffer) - 1 + 3;
    }
    else if (add1.b3 != add2.b3){
        int buffer = abs(add1.b3 - add2.b3);
        return GetDigits(buffer) - 1 + 6;
    }
    else if (add1.b4 != add2.b4){
        int buffer = abs(add1.b4 - add2.b4);
        return GetDigits(buffer) - 1 + 9;
    }
    return -1;
}

int main(){

    InputIp();

    int diff = GetDifference();



}

int InputIp(){
    scanf("%d",&ipCount);

    for (int perIp = 0 ;perIp < ipCount;perIp++){
        scanf("%d.%d.%d.%d",&ip[perIp].b1,&ip[perIp].b2,&ip[perIp].b3,&ip[perIp].b4);
    }

    sort(ip,ip + ipCount);
}

int GetDifference(){
    int maxDiff = -1;

    for (int i = 0 ;i < ipCount - 1 ;i++){
        int perDiff = ip[i] - ip[i+1];
        if (perDiff > maxDiff){
            maxDiff = perDiff;
        }
    }

    return maxDiff;
}
