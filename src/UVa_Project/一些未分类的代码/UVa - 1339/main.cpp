#include "bits/stdc++.h"
using namespace std;

#define INPUT_ERROR (-1)
#define INPUT_OVER (1)
#define BLACK_GENERAL_TYPE 'B'
#define RED_GENERAL_TYPE 'S'
#define HORSE_TYPE 'H'
// chariot 代表车 cannon代表炮！
#define CHARIOT_TYPE 'R'
#define CANNON_TYPE 'C'
#define RED_PIECE_MAX_COUNT 7

#define BLACK_GENERAL_LEFT_BORDER (3)
#define BLACK_GENERAL_RIGHT_BORDER (5)
#define BLACK_GENERAL_UP_BORDER (0)
#define BLACK_GENERAL_DOWN_BORDER (2)

const int BORDER_LINE_LENGTH = 10;
const int BORDER_COLUMN_LENGTH = 9;

const int horseMove[4][2][2] = {
        -2,-1,-2,1,2,-1,2,1,1,-2,-1,-2,1,2,-1,2
};

void GetcharUntilEnter();
int InputBorder();
void SetStructToBorder(struct PieceInfo piece);

bool IsBlackGeneralCouldReach(int point[]);

bool IsPieceMoveToBlackGeneral(int point[]);
bool IsFlyGeneralCouldReach(const int point[],struct PieceInfo pieces);
bool IsHorseCouldReach(int point[],struct PieceInfo pieces);
bool IsCannonCouldReach(int point[],struct PieceInfo pieces);
bool IsChariotCouldReach(int point[],struct PieceInfo pieces);
bool IsObstaclesIntheDirections(int point[],int direct[]);
bool PointSafeCheck(const int point[]);
char GetBorderTypeInPoint(const int point[]);
void MovePointInDirect(int point[],int direct[]);

char border[BORDER_LINE_LENGTH][BORDER_COLUMN_LENGTH];
struct PieceInfo{
    int x;
    int y;
    char type;
};
PieceInfo blackGeneral;
PieceInfo redPieces[RED_PIECE_MAX_COUNT];
int redPiecesCount;

int main(){

    blackGeneral.type = BLACK_GENERAL_TYPE;

    while(InputBorder() != INPUT_ERROR){

        for (int line = BLACK_GENERAL_UP_BORDER ;line <= BLACK_GENERAL_DOWN_BORDER;line++){
            for (int column = BLACK_GENERAL_LEFT_BORDER;column <= BLACK_GENERAL_RIGHT_BORDER;column++){

                int point[] = {line,column};

                if (!IsBlackGeneralCouldReach(point)){
                    continue;
                }

                if (IsPieceMoveToBlackGeneral(point)){
                    printf("YES\n");
                }else{
                    printf("NO\n");
                }
            }
        }
    }
}

int InputBorder(){

    memset(border,'\0',sizeof(border));
    memset(redPieces,0,sizeof(redPieces));

    scanf("%d",&redPiecesCount);

    scanf("%d %d",&blackGeneral.x,&blackGeneral.y);
    SetStructToBorder(blackGeneral);

    if (blackGeneral.x == 0 && blackGeneral.y == 0 && redPiecesCount == 0){
        return INPUT_ERROR;
    }
    int Rcount = redPiecesCount;
    for (int perRedPieces = 0;perRedPieces < Rcount;perRedPieces++){
        GetcharUntilEnter();
        scanf("%c %d %d",&redPieces[perRedPieces].type,&redPieces[perRedPieces].x,&redPieces[perRedPieces].y);
        SetStructToBorder(redPieces[perRedPieces]);
    }

    redPiecesCount = Rcount;
    return INPUT_OVER;

}

void GetcharUntilEnter(){
    while(getchar()!='\n'){
        ;
    }
}

void SetStructToBorder(struct PieceInfo piece){
    border[piece.x][piece.y] = piece.type;
}

bool IsBlackGeneralCouldReach(int point[]){

    int verticalDistance = abs(point[0] - blackGeneral.x);
    int horizontalDistance = abs(point[1] - blackGeneral.y);

    if (verticalDistance == 1 && horizontalDistance == 0){
        return true;
    }else if(verticalDistance == 0 && horizontalDistance == 1){
        return true;
    }

    return false;

}

bool IsPieceMoveToBlackGeneral(int point[]){

    for (int perRedPieces = 0; perRedPieces < redPiecesCount; perRedPieces++) {

        switch (redPieces[perRedPieces].type) {

            case RED_GENERAL_TYPE : {
                if (IsChariotCouldReach(point,redPieces[perRedPieces])){
                    return true;
                }
                break;
            }
            case HORSE_TYPE : {
                if (IsHorseCouldReach(point,redPieces[perRedPieces])){
                    return true;
                }
                break;
            }
            case CANNON_TYPE : {
                if (IsCannonCouldReach(point,redPieces[perRedPieces])){
                    return true;
                }
            }
            case CHARIOT_TYPE : {
                if (IsChariotCouldReach(point,redPieces[perRedPieces])){
                    return true;
                }
            }
        }
    }

    return false;
}

bool IsChariotCouldReach(int point[],struct PieceInfo pieces){

    if (point[0] != pieces.x && point[1] != pieces.y){
        return false;
    }

    const int router[4][2] ={
            1,0,-1,0,0,1,0,-1
    };

    for (int routerChose = 0 ; routerChose <4 ; routerChose++){
        int direct[2] = {
                router[routerChose][0],router[routerChose][1]
        };

        int nowPoint[2] = {
                point[0],point[1]
        };

        while (PointSafeCheck(nowPoint)){
            if (GetBorderTypeInPoint(nowPoint) == BLACK_GENERAL_TYPE){
                return true;
            }
            MovePointInDirect(nowPoint,direct);
        }
    }

    return false;

}

bool IsHorseCouldReach(int point[],struct PieceInfo pieces){

    for (int direct = 0 ; direct < 4;direct ++){
        for (int i = 0;i < 2; i++) {

            int horseDestPos[2] = {
                    point[0] + horseMove[direct][i][0],point[1] + horseMove[direct][i][1]
            };

            if (border[horseDestPos[0]][horseDestPos[1]] == 'B'){
                return true;
            }
        }
    }

    return false;
}

bool IsCannonCouldReach(int point[],struct PieceInfo pieces){

    const int router[4][2] ={
            1,0,-1,0,0,1,0,-1
    };

    for (int routerChose = 0;routerChose < 4;routerChose ++){

        int nowRouter[2] = {
                router[routerChose][0],router[routerChose][1]
        };

        if (IsObstaclesIntheDirections(point,nowRouter)){
            return true;
        }
        else {
            continue;
        }
    }
    return false;
}
bool IsObstaclesIntheDirections(int point[],int direct[]){

    int nowPoint[2] = {
            point[0],point[1]
    };

    MovePointInDirect(nowPoint,direct);

    bool findObstacle = false;
    while (PointSafeCheck(nowPoint)){
        char pointType = GetBorderTypeInPoint(nowPoint);

        if (pointType == BLACK_GENERAL_TYPE){
            return false;
        }

        if(pointType != '\0'){
            findObstacle = true;
            break;
        }

        MovePointInDirect(nowPoint,direct);
    }

    if (!findObstacle){
        return false;
    }

    while (PointSafeCheck(nowPoint)){
        if(GetBorderTypeInPoint(nowPoint) == 'B'){
            return true;
        }
        MovePointInDirect(nowPoint,direct);
    }
    return false;
}

bool PointSafeCheck(const int point[]){
    if (point[0] < 0 || point[0] >= BORDER_LINE_LENGTH){
        return false;
    }else if (point[1] < 0 || point[1] >= BORDER_COLUMN_LENGTH){
        return false;
    }

    return true;
}

char GetBorderTypeInPoint(const int point[]){
    return border[point[0]][point[1]];
}

void MovePointInDirect(int point[],int direct[]){
    point[0] += direct[0];
    point[1] += direct[1];
}
