#include "bits/stdc++.h"
using namespace std;

#define MAX_LENGTH 100000
#define INPUT_STOP (-1)
#define SUB_OK (1)


char parentString[MAX_LENGTH];
char subString[MAX_LENGTH];

int InputString();

bool CheckSubString();

bool CharCheckEqual(int parentStringPos,int subStringPos);

int main(){

    while(InputString() != INPUT_STOP){

        if (CheckSubString() == SUB_OK){
            printf("Yes\n");
        }else {
            printf("No\n");
        }

    }
}

int InputString(){
    memset(parentString,'\0',sizeof(parentString));
    memset(subString,'\0',sizeof(subString));

    if (scanf("%s",subString) == EOF){
        return INPUT_STOP;
    }
    scanf("%s",parentString);

    return 0;
}

bool CheckSubString(){

    int posInParent = 0;
    int posInSub = 0;
    int subStringLen = (int)strlen(subString);
    int parentStringLen = (int)strlen(parentString);

    while(posInSub < subStringLen){

        if (CharCheckEqual(posInParent,posInSub)){
            posInSub++;
            posInParent++;
        }else {
            posInParent++;
        }

        if (posInParent > parentStringLen){
            return false;
        }
    }

    return SUB_OK;
}

bool CharCheckEqual(int parentStringPos,int subStringPos){
    if (parentString[parentStringPos] == subString[subStringPos]){
        return true;
    }
    return false;
}
