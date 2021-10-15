#include "bits/stdc++.h"

#define FindPostionTrans -1

int main(){
    const char keyboardSequence[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    char keyboardBuffer;

    while((keyboardBuffer = getchar()) != EOF){
        if (keyboardBuffer != ' ' && keyboardBuffer != '\n'){
            for (int searchPos = 0; searchPos < strlen(keyboardSequence); searchPos++) {
                if (keyboardSequence[searchPos] == keyboardBuffer){
                    printf("%c",keyboardSequence[searchPos + FindPostionTrans]);
                    break;
                }
            }
        }
        else if(keyboardBuffer == '\n'){
            printf("\n");
        }
        else {
            printf(" ");
        }
    }
}
