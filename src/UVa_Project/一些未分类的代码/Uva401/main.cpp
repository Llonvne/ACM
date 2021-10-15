#include "bits/stdc++.h"

#define MAXN 21
#define UNABLETOREVERSE -1

char textBuffer[MAXN];
int len;

int GetPalindromeResult();
int GetMirrorResult();
char Reverse(char NeedToReverse);

int main(){


    while(~scanf("%s", textBuffer)){

        len = (int)strlen(textBuffer);
        int palindromeResult = GetPalindromeResult();
        int mirrorResult = GetMirrorResult();

        if ((!palindromeResult) && (!mirrorResult)){
            printf("%s -- is not a palindrome.\n\n",textBuffer);
        }
        else if ((palindromeResult) && (!mirrorResult)){
            printf("%s -- is a regular palindrome.\n\n",textBuffer);
        }
        else if ((!palindromeResult) && mirrorResult){
            printf("%s -- is a mirrored string.\n\n",textBuffer);
        }else {
            printf("%s -- is a mirrored palindrome.\n\n",textBuffer);
        }
    }
}

int GetPalindromeResult(){

    for (int start = 0; start < len; ++start) {
        int stop = len - start - 1;
        if (textBuffer[start] != textBuffer[stop]){
            return 0;
        }
    }

    return 1;
}

int GetMirrorResult(){

    char reverseBuffer;

    for (int reversePosStart = 0; reversePosStart < len; ++reversePosStart) {
        int needToCompare = len - reversePosStart - 1;

        reverseBuffer = Reverse(textBuffer[reversePosStart]);

        if (reverseBuffer == UNABLETOREVERSE){
            return 0;
        }

        if (reverseBuffer != textBuffer[needToCompare]){
            return 0;
        }
    }

    return 1;

}

char Reverse(char NeedToReverse){
    const char couldReverse[] = "AE3HIJLMOS2TUVWXYZ518";
    const char reverse[] =      "A3EHILJMO2STUVWXY5Z18";
    const int reverseLen = (int)strlen(couldReverse);

    for (int searchPos = 0;searchPos < reverseLen;searchPos++){
        if (couldReverse[searchPos] == NeedToReverse){
            return reverse[searchPos];
        }
    }
    return UNABLETOREVERSE;
}