#include "bits/stdc++.h"
using namespace std;

#define INPUT_ERROR (-1)
#define INPUT_OVER (1)
#define MAX_LENGTH 105
#define MATCH_MAX_SIZE 3

char upLine[MAX_LENGTH];
char downLine[MAX_LENGTH];
int upLineLen,downLineLen;
int maxLength,sumLength;

int InputAllLine();
int GetNumberInCharArray(char ArrayName[],int pos);
int GetLengthOfUpMove();
int GetLengthOfDownMove();

int main(){

    while (InputAllLine() != INPUT_ERROR){

        int LenUpMove = GetLengthOfUpMove();
        int LenDownMove = GetLengthOfDownMove();

        int minLen = min(LenUpMove,LenDownMove);

        printf("%d\n", minLen);
    }
}

int InputAllLine(){
    memset(upLine,'\0',MAX_LENGTH);
    memset(downLine,'\0',MAX_LENGTH);

    if (scanf("%s %s",downLine,upLine) != 2){
        return INPUT_ERROR;
    }

    upLineLen = (int)strlen(upLine);
    downLineLen = (int)strlen(downLine);

    maxLength = max(upLineLen,downLineLen);
    sumLength = upLineLen + downLineLen;

    return INPUT_OVER;
}

int GetNumberInCharArray(char ArrayName[],int pos){
    return ArrayName[pos] - '0';
}

bool GetIsMatched(int downPos,int upPos){
    int upSize = GetNumberInCharArray(upLine,upPos);
    int downSize = GetNumberInCharArray(downLine,downPos);

    if (upSize + downSize <= MATCH_MAX_SIZE){
        return true;
    }

    return false;
}

bool LoopForCheckMatch(int downPos,int upPos){

    while(downPos < downLineLen && upPos < upLineLen){

        if (!GetIsMatched(downPos,upPos)){
            return false;
        }

        downPos ++;
        upPos ++;
    }

    return true;

}

bool GetSpecialDownStartPosMatched(int downStartPos){
    int downPos = downStartPos;
    int upPos = 0;
    return LoopForCheckMatch(downPos,upPos);
}
int GetTotalLengthInUpMove(int downStartPos){
    return max(maxLength,upLineLen + downStartPos);
}

int GetLengthOfUpMove(){

    for (int downStartPos = 0 ; downStartPos < downLineLen ; downStartPos++){

        if (GetSpecialDownStartPosMatched(downStartPos)){
            return GetTotalLengthInUpMove(downStartPos);
        }

    }

    return sumLength;
}

int GetTotalLengthInDownMove(int upStartPos){
    return max(maxLength,downLineLen + upStartPos);
}

bool GetSpecialUpStartPosMatched(int upStartPos){
    int downPos = 0;
    int upPos = upStartPos;
    return LoopForCheckMatch(downPos,upPos);
}

int GetLengthOfDownMove(){
    for (int upStartPos = 0 ; upStartPos < upLineLen ; upStartPos ++){
        if (GetSpecialUpStartPosMatched(upStartPos)){
            return GetTotalLengthInDownMove(upStartPos);
        }
    }

    return sumLength;
}