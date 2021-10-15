#include "bits/stdc++.h"
using namespace std;

#define INPUT_STOP (0)
#define INPUT_OVER (1)
#define MATRIX_MAX_SIZE (10)
#define IS_STARTPOS (1)
#define NOT_STARTPOS (0)
#define BLACKBLOCK ('*')
#define NO_WHITE_IN_UPORLEFT (1)
#define WHITE_IN_UPORLEFT (0)
#define OUT_MATRIX (0)
#define IN_MATRIX (1)

int GetLineAndColumnCount();

int InputMatrix();

int GetStartPos();

int IsStartPos(const int point[]);

int IsUppAndLeftBlockNotWhite(const int point[]);

int SafePosCheck(const int point[]);

char GetMatrixValue(const int point[]);

void GetCharUnitlEnter();

void PrintAllAcross();

void PrintAcross(const int point[]);

void PrintPuzzleCount();

bool GetIsBlack(const int point[]);

void PrintDown(const int point[]);

void PrintAllDown();

//  使用大写因为left是保留字
const int Left[] = {0,-1};
const int Upper[] = {-1,0};
const int Right[] = {0,1};
const int Down[] = {1,0};

struct Block{
    char value = '\0';
    bool isStartPos = false;
    int whiteCount = 0;
};

Block matrix[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE];
int lineCount,columnCount;
int globalPuzzleCount = 0;

int main(){

    while(GetLineAndColumnCount() == INPUT_OVER){

        InputMatrix();

        GetStartPos();

        PrintPuzzleCount();

        PrintAllAcross();

        PrintAllDown();

    }

}

int GetLineAndColumnCount(){
    scanf("%d",&lineCount);

    if (INPUT_STOP == lineCount){
        return INPUT_STOP;
    }else {
        scanf("%d",&columnCount);
        return INPUT_OVER;
    }
}

int InputMatrix(){

    memset(matrix,0,sizeof(matrix));

    GetCharUnitlEnter();

    for (int line = 0; line < lineCount; ++line) {
        for (int column = 0;column < columnCount; ++column) {
            scanf("%c",&matrix[line][column].value);
        }
        GetCharUnitlEnter();
    }

    return INPUT_OVER;
}

int GetStartPos(){

    int globalWhiteCount = 1;

    for (int line = 0; line < lineCount; ++line) {
        for (int column = 0; column < columnCount; ++column) {

            const int point[2] = {line,column};
            if (IsStartPos(point) == IS_STARTPOS){
                matrix[line][column].isStartPos = true;

                matrix[line][column].whiteCount = globalWhiteCount;
                globalWhiteCount++;

            }
            else {
                matrix[line][column].isStartPos = false;
            }
        }
    }
    return 0;
}

int IsStartPos(const int point[]){

    if (GetMatrixValue(point) == BLACKBLOCK){
        return NOT_STARTPOS;
    }

    if(IsUppAndLeftBlockNotWhite(point) == NO_WHITE_IN_UPORLEFT){
        return IS_STARTPOS;
    }

    return NOT_STARTPOS;
}

int IsUppAndLeftBlockNotWhite(const int point[]){

    const int upperPoint[] = {point[0] + Upper[0],point[1] + Upper[1]};
    const int leftPoint[] = {point[0] + Left[0],point[1] + Left[1]};

    if (SafePosCheck(upperPoint) == OUT_MATRIX || SafePosCheck(leftPoint) == OUT_MATRIX){
        return NO_WHITE_IN_UPORLEFT;
    }

    if (GetIsBlack(upperPoint) || GetIsBlack(leftPoint)){
        return NO_WHITE_IN_UPORLEFT;
    }

    return WHITE_IN_UPORLEFT;
}

int SafePosCheck(const int point[]){

    if (point[0] < 0 || point[0]>=lineCount){
        return OUT_MATRIX;
    }
    if (point[1] < 0 || point[1]>=columnCount){
        return OUT_MATRIX;
    }

    return IN_MATRIX;
}

char GetMatrixValue(const int point[]){
    return matrix[point[0]][point[1]].value;
}

void GetCharUnitlEnter(){
    while (getchar() != '\n'){
        ;
    }
}

bool GetisStartPos(const int point[]){
    return matrix[point[0]][point[1]].isStartPos;
}

void PrintAllAcross(){

    printf("Across\n");

    for (int line = 0; line < lineCount; line++) {
        for (int column = 0; column < columnCount; column++) {

            const int point[] = {line,column};

            if (GetisStartPos(point) == IS_STARTPOS){
                PrintAcross(point);
            }

        }
    }
}

int GetMatrixwhiteCount(const int point[]){
    return matrix[point[0]][point[1]].whiteCount;
}

bool GetIsBlack(const int point[]){
    if (GetMatrixValue(point) == BLACKBLOCK){
        return true;
    }
    return false;
}

void ReturnRighter(int point[]){
    point[0] += Right[0];
    point[1] += Right[1];
}

void SetisStartPos(const int point[],bool NeedToSet){
    matrix[point[0]][point[1]].isStartPos = NeedToSet;
}

void PrintAcross(const int point[]){

    printf("%3d.", GetMatrixwhiteCount(point));
    printf("%c", GetMatrixValue(point));
    SetisStartPos(point,false);

    int righterPoint[2] = {point[0],point[1]};
    ReturnRighter(righterPoint);

    while (!GetIsBlack(righterPoint) && SafePosCheck(righterPoint) == IN_MATRIX){
        SetisStartPos(righterPoint,false);
        printf("%c", GetMatrixValue(righterPoint));
        ReturnRighter(righterPoint);
    }

    printf("\n");
}

void PrintPuzzleCount(){
    globalPuzzleCount++;
    if (globalPuzzleCount!=1){
        printf("\n");
    }
    printf("puzzle #%d:\n",globalPuzzleCount);
}

void PrintAllDown(){
    printf("Down\n");

    for (int line = 0; line < lineCount; line++) {
        for (int column = 0; column < columnCount; column++) {

            const int point[] = {line,column};

            if (GetMatrixwhiteCount(point) > 0){
                PrintDown(point);
            }
        }
    }
}

void SetMatrixWhiteCount(const int point[],int SetValue){
    matrix[point[0]][point[1]].whiteCount = SetValue;
}

void ReturnDowner(int ArrayToReturn[]){
    ArrayToReturn[0] += Down[0];
    ArrayToReturn[1] += Down[1];
}

void PrintDown(const int point[]){
    printf("%3d.", GetMatrixwhiteCount(point));
    printf("%c", GetMatrixValue(point));
    SetMatrixWhiteCount(point,0);

    int downerPoint[2] = {point[0],point[1]};
    ReturnDowner(downerPoint);

    while (!GetIsBlack(downerPoint) && SafePosCheck(downerPoint) == IN_MATRIX){
        SetMatrixWhiteCount(downerPoint,0);
        printf("%c", GetMatrixValue(downerPoint));
        ReturnDowner(downerPoint);
    }

    printf("\n");
}
