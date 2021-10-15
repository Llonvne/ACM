#include "bits/stdc++.h"

using namespace std;

#define MAX_SECRET_CODE_LENGTH 1005
#define GUESS_STOP_SIGNAL (-1)
#define GUESS_RANGE 9


int input(int needToInput[]);
int GetBothRight();
int GetAppearedButPosWrong();
int GetNumberCount(int number,const int searchArray[]);

int gameTimeCount = 0;
int answerLen;
int secretCode[MAX_SECRET_CODE_LENGTH];
int guessBuffer[MAX_SECRET_CODE_LENGTH];
int secretCodeNumberCountList[GUESS_RANGE];

int main(){
    while(scanf("%d",&answerLen) && answerLen){

        gameTimeCount++;
        printf("Game %d:\n",gameTimeCount);

        input(secretCode);

        for (int perNumber = 1; perNumber <= 9 ; ++perNumber) {
            int listIndex = perNumber - 1;
            secretCodeNumberCountList[listIndex] = GetNumberCount(perNumber,secretCode);
        }

        while (input(guessBuffer) != GUESS_STOP_SIGNAL){
            int bothRight = GetBothRight();
            int appearedButPosWrong = GetAppearedButPosWrong();

            printf("    ");
            printf("(%d,%d)\n",bothRight, appearedButPosWrong - bothRight);
        }

        memset(secretCode,0,MAX_SECRET_CODE_LENGTH);
        memset(guessBuffer,0,MAX_SECRET_CODE_LENGTH);
        memset(secretCodeNumberCountList,0,GUESS_RANGE);
    }
}

int input(int needToInput[]){
    for (int inputTimes = 0;inputTimes < answerLen;inputTimes++){
        scanf("%d",&needToInput[inputTimes]);
    }
    if (needToInput[0] == 0){
        return GUESS_STOP_SIGNAL;
    }
    return 0;
}

int GetBothRight(){
    int bothRight = 0;
    for (int checkPos = 0; checkPos < answerLen; checkPos++) {
        if (guessBuffer[checkPos] == secretCode[checkPos]){
            bothRight++;
        }
    }
    return bothRight;
}

int GetAppearedButPosWrong(){

    int appearedButPosWrong = 0;
    int minSecretAndGuess = 0;
    int guessBufferNumberCountList[GUESS_RANGE];

    for (int perNumber = 1;perNumber < 10;perNumber++) {
        int listIndex = perNumber - 1;
        guessBufferNumberCountList[listIndex] = GetNumberCount(perNumber,guessBuffer);
        minSecretAndGuess = min(secretCodeNumberCountList[listIndex],guessBufferNumberCountList[listIndex]);
        appearedButPosWrong += minSecretAndGuess;
    }

    return appearedButPosWrong;
}
int GetNumberCount(int number,const int searchArray[]){
    int numberCount = 0;
    for (int checkPos = 0; checkPos < answerLen; ++checkPos) {
        if (searchArray[checkPos] == number){
            numberCount++;
        }
    }
    return numberCount;
}







