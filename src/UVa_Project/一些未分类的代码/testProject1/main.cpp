#include "bits/stdc++.h"
using namespace std;

#define MAP_MAX_SIZE 9
#define INPUT_ERROR (-1)
#define INPUT_OVER (1)
#define SAFE 1
#define UNSAFE 0

int InputMap();
void GetcharUntilIsEnter();
void SetLine();
int TransferInputPos(int& InputPos);
bool CheckSizeSquare(const int point[]);
void PrintPuzzleCount();

struct Point{
    bool downLine;
    bool rightLine;
};

const int defaultSquareSize = 1;
Point maps[MAP_MAX_SIZE][MAP_MAX_SIZE];
int mapSize;
int lineCount;
int squareSize = defaultSquareSize;
int puzzleCount = 0;


int main(){

    while(InputMap() != INPUT_ERROR){

        int SquareSize = 1;

        for (int i = 0;i < mapSize -1 ;i++){
            for (int j = 0;j<mapSize -1 ;j++){

                const int point[2] = {i,j};

                if (CheckSizeSquare(point)){
                    printf("%d %d \n",i,j);
                }

            }
        }

    }
    return 0;
}

int InputMap(){

    memset(maps, 0, sizeof(maps));
    squareSize = defaultSquareSize;

    if (scanf("%d",&mapSize) == EOF){
        return INPUT_ERROR;
    }

    scanf("%d",&lineCount);

    for (int perLine = 0;perLine < lineCount;perLine++) {
        GetcharUntilIsEnter();
        SetLine();

    }

    return INPUT_OVER;
}

void SetLine(){

    char lineType;
    int horizonPos,verticalPos;
    scanf("%c %d %d",&lineType,&horizonPos,&verticalPos);

    horizonPos = TransferInputPos(horizonPos);
    verticalPos = TransferInputPos(verticalPos);

    if (lineType == 'H'){//H horizon
        maps[horizonPos][verticalPos].rightLine = true;
    }
    else if (lineType == 'V'){
        maps[horizonPos][verticalPos].downLine = true;
    }
}

void GetcharUntilIsEnter(){
    while(getchar() != '\n'){
        ;
    }
}

int TransferInputPos(int& InputPos){
    return InputPos -1;
}

int PointSafeCheck(const int point[]){
    if (point[0] < 0 || point[0] >= mapSize || point[1] < 0 || point[1] >= mapSize){
        return UNSAFE;
    }
    return SAFE;
}

bool GetMapsDownLineBoolWithPoint(const int point[]){
    return maps[point[0]][point[1]].downLine;
}

bool GetMapsRightLineBoolWithPoint(const int point[]){
    return maps[point[0]][point[1]].rightLine;
}

bool CheckSizeSquare(const int point[]){

    const int destPos[2] = {
            point[0] + squareSize , point[1] + squareSize
    };

    for (int lineCheck = point[1]; lineCheck < destPos[1];lineCheck++){

        const int checkPointUp[2] = {
                point[0],lineCheck
        };

        const int checkPointDown[2] = {
                destPos[0],lineCheck
        };

        if (!GetMapsRightLineBoolWithPoint(checkPointUp)){
            return false;
        }

        if (!GetMapsRightLineBoolWithPoint(checkPointDown)){
            return false;
        }
    }

    for (int columnCheck = point[0];columnCheck < destPos[0];columnCheck++){

        const int checkPointLeft[2] = {
                columnCheck,point[1]
        };

        const int checkPointRight[2] = {
                columnCheck,destPos[1]
        };

        if (!GetMapsDownLineBoolWithPoint(checkPointLeft)){
            return false;
        }

        if (!GetMapsDownLineBoolWithPoint(checkPointRight)){
            return false;
        }
    }

    return true;

}

void PrintPuzzleCount(){
    printf("Problem #%d\n\n",++puzzleCount);
}