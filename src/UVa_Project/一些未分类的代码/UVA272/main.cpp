#include "bits/stdc++.h"

int ReplaceChar(char text[],char replace,char first,char second){
    char ch;
    bool isLeft = true;
    int len = strlen(text);
    for (int i = 0; i < len; ++i) {
        if(text[i] != replace) {
            continue;
        }
        else if(isLeft){
            text[i] = first;
            isLeft = false;
        }
        else {
            isLeft = true;
            text[i] = second;
        }
    }
    return 1;
}

int main(){
    char a[200] = "1227637928749823647182301284767392671283490213849";
    ReplaceChar(a,'1','*','&');
    for (int i = 0; i < strlen(a); ++i) {
        printf("%c",a[i]);
    }
}