#include <bits/stdc++.h>
using namespace std;

struct LineExistMatrix{
    bool existLineBLow;
    bool existLineRight;
};

void InputLines(int lineCount);

void LineCreator(int point[],char lineType);

int CheckSquareInSpecificSize(int startPos[],int size);

LineExistMatrix maps[9][9];

int main() {

    int matrixActualSize;
    scanf("%d",&matrixActualSize);

    int lineCount;
    scanf("%d",&lineCount);
    // 这个getchar会忽略一个回车
    getchar();

    InputLines(lineCount);
    int sizeOneSquareCount = 0;
    int nowSize = 1;
    for(int perX = 0;perX < matrixActualSize ; perX ++){
        for (int perY = 0;perY < matrixActualSize;perY ++){
            int nowCheckPoint[2] = {perX,perY};
            if(!CheckSquareInSpecificSize(nowCheckPoint,nowSize)){
                sizeOneSquareCount++;
                printf("Wo Got %d ",sizeOneSquareCount);
            }
        }
    }



}

void InputLines(int lineCount){
    char lineTypeBuffer;
    int lineStartPos,LineEndPos;
    for (int NowLineCount = 0;NowLineCount < lineCount;NowLineCount++){
        scanf("%c %d %d",&lineTypeBuffer,&lineStartPos,&LineEndPos);
        // getchar 函数用于忽略一个回车
        getchar();

        int point[] = {lineStartPos,LineEndPos};
        LineCreator(point,lineTypeBuffer);
    }
}

void LineCreator(int point[],char lineType){
    const char BlowLineType = 'V';
    const char RightLineType = 'H';

    if (lineType == BlowLineType){
        maps[point[0]][point[1]].existLineBLow = true;
    }
    else {
        maps[point[0]][point[1]].existLineRight = true;
    }
}

int CheckSquareInSpecificSize(int startPos[],int size){

    //竖向检测 这里需要 <=
    for (int nowBlowLine = startPos[0]; nowBlowLine <= startPos[0] + size;nowBlowLine ++) {
        if (!maps[nowBlowLine][startPos[1]].existLineBLow){
            return -1;
        }
    }

    //横向检测 这里需要小于
    for (int nowRightLine = startPos[1]; nowRightLine < startPos[1] + size; ++nowRightLine) {
        if (!maps[nowRightLine][startPos[1]].existLineBLow){
            return -1;
        }
    }
    return 0;
}


