#include "bits/stdc++.h"
using namespace std;

#define MAXN 105
#define NOT_FOUND (-1)
#define COM1_WIN 1
#define COM2_WIN 2
const char DNAtype[] = {"ACGT"};

int GetCharPos(char needToGet, int posList[]);
int CompareDictionarySequence(int start1,int start2);
int GetFullCaseinAnyStartPos(int start,char returnCharArray[]);
int GetSafePos(int startPos,int offset);

char DNAcase[MAXN];
int caseLen;

int main(){

    int caseCount = 0;
    scanf("%d",&caseCount);

    while(caseCount--){

        memset(DNAcase,'\0',MAXN);

        scanf("%s",DNAcase);
        caseLen = (int)strlen(DNAcase);

        int posList[MAXN];
        int posCount;
        for (int charPoint = 0; charPoint < 4; ++charPoint) {
            posCount = GetCharPos(DNAtype[charPoint],posList);

            if (posCount != NOT_FOUND) {
                break;
            }
        }

        int winPos = posList[0];
        for (int checkPos = 1; checkPos < posCount; ++checkPos) {
            winPos = CompareDictionarySequence(winPos,posList[checkPos]);
        }

        char winList[MAXN];
        GetFullCaseinAnyStartPos(winPos,winList);

        printf("%s\n",winList);

        memset(winList,'\0',MAXN);

    }
}

int GetCharPos(char needToGet, int posList[]){
    memset(posList,0,MAXN);

    int posCount = 0;
    for (int checkPos = 0; checkPos < caseLen; ++checkPos) {
        if (needToGet == DNAcase[checkPos]){
            posList[posCount] = checkPos;
            posCount++;
        }
    }

    if (posCount){
        return posCount;
    }else {
        return NOT_FOUND;
    }

}

int CompareDictionarySequence(int start1,int start2){
    char competitor1[MAXN],competitor2[MAXN];
    GetFullCaseinAnyStartPos(start1,competitor1);
    GetFullCaseinAnyStartPos(start2,competitor2);

    int winFlag = NOT_FOUND;
    for (int i = 0; i < caseLen; ++i) {
        if (competitor1[i] == competitor2[i]){
            continue;
        }else if(competitor1[i] > competitor2[i]){
            winFlag = COM2_WIN;
            break;
        }else {
            winFlag = COM1_WIN;
            break;
        }
    }

    if (winFlag == COM1_WIN){
        return start1;
    }else {
        return start2;
    }
}

int GetFullCaseinAnyStartPos(int start,char returnCharArray[]){
    int returnCharArrayIndex = 0;
    for (int i = start; i < start + caseLen;i++){
        returnCharArray[returnCharArrayIndex] = DNAcase[GetSafePos(i,0)];
        returnCharArrayIndex++;
    }
    returnCharArray[returnCharArrayIndex] = '\0';
    return 1;
}

int GetSafePos(int startPos,int offset){
    return (startPos+offset+caseLen)%caseLen;
}