#include "bits/stdc++.h"



//数据结构
//棋盘
char border[10][9];
//棋子信息结构体
struct piece {
    int x;
    int y;
    char type;
};
//初始化棋子
piece blackGeneral;
piece redPiece[7];
//统计红色的棋子的数量
int RedPiecesCount = 0;

//function declarations
int input();
// 这个函数接受 输入流并且判断是否输入结束

void GetBlackGeneralMove(int x, int y, bool maps[][3]);
// 这个函数接受 一个黑色的将现在的位置,一个用于返回的数组，他会将所有将可以移动的位置变换成 true

void GetCannonMove(int x, int y, bool maps[][3]);
// 这个函数接受 一个红色的炮现在的位置，一个用于返回的数组，他会将所有可以打击的范围更改为 false

void GetHorseMove(int x, int y, bool maps[][3]);
// 这个函数接受 一个红色的马现在的位置，一个用于返回的数组，他会将所有可以打击的范围更改为 false

void GetChariotMove(int x, int y, bool maps[][3]);
// 这个函数接受 一个红色的车现在的位置，一个用于返回的数组，他会将所有可以打击的范围更改为 false

void GetRedGeneralFly(int x, int y, bool maps[][3]);
//这个函数接受 一个红色帅的位置，一个用于返回的数组，他会讲所有可以打击的位置更改为false

void BorderPosTransformBool(int point[], bool BorderToBool);
//这个函数接受 一个棋盘坐标返回一个在 bool数组对应的坐标

void IsInsideBoolArea(int x, int y, bool maps[][3], bool turnToTrue);
//这个函数接受 一个点坐标（包含 x y 两个参数） 会判断是否属于Bool区域，如果是 就会改成最后一个参数值

char Router(int x,int y,int xoffset, int yoffset,int point[2]);
//这个函数 接受 一个开始查找的点 （包含 x,y） 一个查找方向（包含 xoffset yoffset） 他会把找到地图上的第一个字符用retrun返回，坐标返回到传入的数组

void SetValues(int x1,int y1,int x2,int y2,bool maps[][3],bool Turnto);
//这个函数会把 从 p1 - p2 点全部设定为指定布尔值 只允许横竖，不能斜

int main() {
    // 变量初始化
    blackGeneral.type = 'B'; // B 代表 黑色将军
    //例子循环
    int first = true;
    while (~input()) {
        if (!first){
            printf("\n");
        }
        first = false;

        //变量初始化
        bool blackGeneralMove[3][3];
        memset(blackGeneralMove, 0, sizeof(blackGeneralMove));

        //获得将可移动区域
        GetBlackGeneralMove(blackGeneral.x, blackGeneral.y, blackGeneralMove);

        //循环所有将可以走的位置
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                //判断是否是将能走的位置
                if (blackGeneralMove[i][j]){

                    //变更将的位置
                    border[blackGeneral.x][blackGeneral.y] = '\0';
                    //将 i j 转换为 border上的坐标
                    int point[] = {blackGeneral.x,blackGeneral.y};
                    BorderPosTransformBool(point,false);
                    blackGeneral.x = point[0];
                    blackGeneral.y = point[1];
                    border[blackGeneral.x][blackGeneral.y] = blackGeneral.type;
                    blackGeneralMove[i][j] = false;

                    //建立打击范围区域
                    bool AttackFiled[3][3];
                    memset(AttackFiled, true, sizeof(AttackFiled));

                    //获得打击范围
                    //获得车，炮，马，帅打击位置
                    for (int k = 0; k < RedPiecesCount; ++k) {
                        switch (redPiece[k].type) {
                            case 'R':
                                GetChariotMove(redPiece[k].x, redPiece[k].y, AttackFiled);
                                break;
                            case 'H':
                                GetHorseMove(redPiece[k].x, redPiece[k].y, AttackFiled);
                                break;
                            case 'C':
                                GetCannonMove(redPiece[k].x, redPiece[k].y, AttackFiled);
                                break;
                            case 'G':
                                GetRedGeneralFly(redPiece[k].x,redPiece[k].y,AttackFiled);
                                break;
                        }
                    }

                    //如果还是True 那么就是未被打击 就是为绝杀
                    if (AttackFiled[i][j]){
                        printf("NO");
                        goto done;
                    }
                }
            }
        }

        printf("YES");
        done:;
    }
    return 0;
}

int input() {
    //重制棋盘
    memset(border, '\0', sizeof(border));
    // 获得 红色棋子的个数和 黑色将军的坐标
    //为什么有个buffer 因为实际的坐标数字跟棋盘是相差1的 而且输入的是包含帅的红色棋子数，我们需要不包含帅的
    int blackGeneral_xBuffer, blackGeneral_yBuffer;
    scanf("%d%d%d", &RedPiecesCount, &blackGeneral_xBuffer, &blackGeneral_yBuffer);
    //判断是否结束
    if ((RedPiecesCount == 0) && (blackGeneral_yBuffer == 0) && (blackGeneral_xBuffer == 0)) {
        return -1;
    }
    //黑色将赋值
    blackGeneral.x = blackGeneral_xBuffer - 1;
    blackGeneral.y = blackGeneral_yBuffer - 1;
    border[blackGeneral.x][blackGeneral.y] = blackGeneral.type;
    //循环输入红色棋子
    for (int i = 0; i < RedPiecesCount; ++i) {
        int xbuffer, ybuffer;
        scanf(" %c%d%d", &redPiece[i].type, &xbuffer, &ybuffer);
        //printf(" %c %d %d",redPiece[i].type,redPiece[i].x,redPiece[i].y);
        //写入棋盘
        redPiece[i].x = xbuffer - 1;
        redPiece[i].y = ybuffer - 1;
        border[redPiece[i].x][redPiece[i].y] = redPiece[i].type;
    }
    return 0;
}

void GetBlackGeneralMove(int x, int y, bool maps[][3]) {
    //上下左右分别判断
    IsInsideBoolArea(x + 1, y, maps, true);
    IsInsideBoolArea(x - 1, y, maps, true);
    IsInsideBoolArea(x, y + 1, maps, true);
    IsInsideBoolArea(x, y - 1, maps, true);
}

// 坐标转换函数
void BorderPosTransformBool(int point[], bool BorderToBool) {
    // border [0,3] --> Bool [0,0]
    // border [2,5] --> Bool [2,2]
    // + [0,3]
    if (BorderToBool) {
        point[1] -= 3;
        return;
    } else {
        point[1] += 3;
        return;
    }
}

//炮函数
void GetCannonMove(int x, int y, bool maps[][3]) {
    //一个炮要对 Bool 区域实行打击
    //这个炮的位置必须限定在 x 属于 0 ~ 2 y 属于 3 ~ 5
    //排除不能无法进行打击的炮（无用炮）
    if (x > 2) {
        if ((y < 3 || y > 5) ||(x == 1 && y == 4)) {
            return;
        }
    }
    //如果 x <=2 y<= 2 只能向右打击
    if (x >= 0 && x <= 2 && y <= 2 && y >= 0) {
        int nearFoot;
        int SecondFoot = 9;
        bool findFlag = false;
        for (int i = y; i < 9; ++i) {
            if(border[x][i] != '\0' && border[x][i] != 'B' && border[x][i] != 'C'){
                if(!findFlag){
                    nearFoot = i;
                    findFlag = true;
                    continue;
                }
                SecondFoot = i;
                break;
            }
        }
        if (findFlag) {
            for (int i = nearFoot + 1; i <=SecondFoot; ++i) {
                IsInsideBoolArea(x, i, maps, false);
            }
        }
    }
        //如果 x<=2 y>=6 y<=8 只能向左打击
    else if (x <= 2 && y >= 6 && y <= 8) {
        int nearFoot;
        bool findFlag = false;
        int secondFoot = 0;
        for (int i = y; i >= 0; --i) {
            if(border[x][i] != '\0' && border[x][i] != 'B' && border[x][i] != 'C'){
                if(!findFlag){
                    nearFoot = i;
                    findFlag = true;
                    continue;
                }
                secondFoot = i;
                break;
            }
        }
        if (findFlag) {
            for (int i = nearFoot - 1; i >= secondFoot; --i) {
                IsInsideBoolArea(x, i, maps, false);
            }
        }
    }
// 如果 x>=3 x<=9 只能向上打击
    else if (x >= 3 && x <= 9) {
        int nearFoot;
        int secondFoot = 0;
        int findFlag = false;
        for (int i = x; i >=0 ; --i) {
            if(border[i][y] != '\0' && border[i][y] != 'B' && border[i][y] != 'C'){
                if(!findFlag){
                    nearFoot = i;
                    findFlag = true;
                    continue;
                }
                secondFoot = i;
                break;
            }
        }
        if (findFlag) {
            for (int i = nearFoot - 1; i >= secondFoot; --i) {
                IsInsideBoolArea(i, y, maps, false);
            }
        }
    }
//如果 x处于bool区域 判断所有方向
    else {
        //当一个炮处于Bool区域时，只有他邻边存在障碍物，才有可能攻击到
        //我们新建一个Bool数组 通过使用黑色将数组获取临边
        bool cannon[3][3];
        memset(cannon, 0, sizeof(cannon));
        GetBlackGeneralMove(x,y,cannon);
        //轮训获取的邻边值 判断该处有没有障碍物
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (cannon[i][j]){
                    //有障碍物
                    int xoffset = i - x;
                    int yoffset = j - y;
                    maps[i + xoffset][y + yoffset] = false;
                }
            }
        }
    }
}

//转换函数
void IsInsideBoolArea(int x, int y, bool maps[][3], bool turnToTrue) {
    //转换成 Bool坐标
    int point[] = {x, y};
    BorderPosTransformBool(point, true);
    //检查是否越界
    if (point[0] >= 0 && point[0] <= 2 && point[1] >= 0 && point[1] <= 2) {
        //不越界就设置为 给定的值
        maps[point[0]][point[1]] = turnToTrue;
    }
        //越界就直接退出
    else {
        return;
    }
}
//马函数
void GetHorseMove(int x, int y, bool maps[][3]){
    const int Router[4][2] = {1,0,0,1,-1,0,0,-1};
    for (int i = 0; i < 4; ++i) {
        int HorseFoot[2] = {x + Router[i][0], y + Router[i][1]};
        //判断压马脚
        if (border[HorseFoot[0]][HorseFoot[1]]!='\0'){
            continue;
        }
        else {
            if(Router[i][0] == 1 && Router[i][1] == 0){
                IsInsideBoolArea(x + 2,y-1,maps,false);
                IsInsideBoolArea(x + 2,y+1,maps,false);
            }else if(Router[i][0] == -1 && Router[i][1] == 0){
                IsInsideBoolArea(x - 2,y-1,maps,false);
                IsInsideBoolArea(x - 2,y+1,maps,false);
            }else if(Router[i][0] == 0 && Router[i][1] == 1){
                IsInsideBoolArea(x + 1,y + 2,maps,false);
                IsInsideBoolArea(x - 1,y+2,maps,false);
            }else if(Router[i][0] == 0 && Router[i][1] == -1){
                IsInsideBoolArea(x + 1,y - 2,maps,false);
                IsInsideBoolArea(x - 1,y-2,maps,false);
            }
        }
    }
}
//车函数
void GetChariotMove(int x, int y, bool maps[][3]){
    //如果车旁边有将 就无效
    if (border[x+1][y] == 'B' || border[x-1][y] == 'B' || border[x][y+1] == 'B' || border[x][y-1] =='B'){
        return;
    }
    int point[2];
    //开始循环四个方向 分别是 0 1 1 0 -1 0 0 -1
    point[0] = 9;
    point[1] = y;
    Router(x,y,1,0,point);
    SetValues(x,y,point[0],point[1],maps,false);
    point[0] = x;
    point[1] = 8;
    Router(x,y,0,1,point);
    SetValues(x,y,point[0],point[1],maps,false);
    point[0] = 0;
    point[1] = y;
    Router(x,y,-1,0,point);
    SetValues(x,y,point[0],point[1],maps,false);
    point[0] = x;
    point[1] = 0;
    Router(x,y,0,-1,point);
    SetValues(x,y,point[0],point[1],maps,false);
}
//帅函数
void GetRedGeneralFly(int x, int y, bool maps[][3]){
    //printf("MAPSTEST %d %d %d",maps[1][1],maps[2][2],maps[0][3]);
    int point[2] = {0,y};
    Router(x,y,-1,0,point);
    //printf("\nPOINT:%d %d START: %d %d\n",point[0],point[1],x,y);
    SetValues(x,y,point[0],point[1],maps,false);
}
//向不同方向查找
char Router(int x,int y,int xoffset, int yoffset,int point[2]){
    for (int i = 0; i < 10; ++i) {
        x+=xoffset;y+=yoffset;
        if (x>=0 && y>=0 && x<10 && x<9){
            if(border[x][y] != '\0' && border[x][y] != 'B'){
                point[0] = x;
                point[1] = y;
                return border[x][y];
            }
        }
        else{
            return -1;
        }
    }
    return 0;
}
//从一个点到另一个点全部设置为给定的值
//只允许横竖
void SetValues(int x1,int y1,int x2,int y2,bool maps[][3],bool Turnto){
    int offset = 1;
    if (x1 - x2 == 0){
        if (y1>y2) {
            for (int i = y2; i <= y1 ; ++i) {
                IsInsideBoolArea(x1,i,maps,false);
            }
        }else{
            for (int i = y1; i <= y2 ; ++i) {
                IsInsideBoolArea(x1,i,maps,false);
            }
        }
    }
    else{
        // x1 -- > x2
        if (x1>x2) {
            for (int i = x2; i <= x1 ; ++i) {
                IsInsideBoolArea(i,y1,maps,false);
            }
        }else{
            for (int i = x1; i <= x2 ; ++i) {
                IsInsideBoolArea(i,y1,maps,false);
            }
        }
    }
}