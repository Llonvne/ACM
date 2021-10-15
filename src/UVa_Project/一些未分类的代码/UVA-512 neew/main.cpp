#include "bits/stdc++.h"

#ifndef ONLINE_JUEGE
#define local
#endif
#ifdef local //本地调试区
//#define debug
#endif

#define maxCommand 1000
#define maxPos 1000
#define GONE -1

//Define trackPos Struct
struct Pos {
    int x;
    int y;
};
Pos p[maxPos];
// Define Command Struct
struct command {
    // Type
    char type[2] = {'\0'};
    // EX
    bool isEX = false;
    int x1, x2, y1, y2;
    //NON EX
    int p[1000] = {0};
    int pCount = 0;
};
command c[maxCommand];

// This Function Will input command
void CommandInput(int i) {
    command commandBuffer;
    //input type
    scanf("%s", commandBuffer.type);
    //printf("%s",commandBuffer.type);
    //EX
    if (memcmp(commandBuffer.type, "EX", 2) == 0) {
        commandBuffer.isEX = true;
        scanf("%d%d%d%d", &commandBuffer.x1, &commandBuffer.y1, &commandBuffer.x2, &commandBuffer.y2);
    }
        //NON EX
    else {
        scanf("%d", &commandBuffer.pCount);

        for (int j = 0; j < commandBuffer.pCount; ++j) {
            scanf("%d", &commandBuffer.p[j]);
        }
    }
    //赋值
    c[i] = commandBuffer;
}
int EX(int& x, int& y, int i) {
    //判断两个坐标是不是自己 如果不是则无变化
    if (c[i].x1 == x && c[i].y1 == y) {
        x = c[i].x2;
        y = c[i].x2;
    } else if (c[i].x2 == x && c[i].y2 == y) {
        x = c[i].x1;
        y = c[i].x1;
    }
    return 0;
}

int DC(int& x, int& y, int i) {
    for (int j = 0; j < c[i].pCount; ++j) {
        //判断是不是自己lie
        if (c[i].p[j] == y) {
            y = GONE;
            return -1;
        } else if (c[i].p[j] <= x) {
            y++;
        }
    }
    return 0;
}

int DR(int& x, int& y, int i) {
    for (int j = 0; j < c[i].pCount; ++j) {
        //判断是不是自己行
        if (c[i].p[j] == x) {
            x = GONE;
            return -1;
        } else if (c[i].p[j] <= x) {
            x++;
        }
    }
    return 0;
}

int IC(int& x, int& y, int i) {
#ifdef debug
    printf("IN");
#endif
    for (int j = 0; j < c[i].pCount; ++j) {
        //判断是不是自己列
        if (c[i].p[j] <= y) {
            y++;
#ifdef debug
            printf("ADD");
#endif
        }
    }
    return 0;
}

int IR(int& x, int& y, int i) {
    for (int j = 0; j < c[i].pCount; ++j) {
        //判断是不是自己行
        if (c[i].p[j] <= x) {
            x++;
        }
    }
    return 0;
}

int main() {
    int m, n;
    int sheetCount = 0;
    while (~scanf("%d%d", &m, &n) && m && n && (++sheetCount)) {

        //Get Command
        int commandCount = 0;
        scanf("%d", &commandCount);
        for (int i = 0; i < commandCount; ++i) {
            CommandInput(i);
        }

        //Get Track Pos
        int trackPosCount = 0;
        scanf("%d", &trackPosCount);
        for (int i = 0; i < trackPosCount; ++i) {
            scanf("%d%d", &p[i].x, &p[i].y);
        }

        //Pos Transform
        int passCount = 0;
        printf("Spreadsheet #%d\n", sheetCount);
        while (trackPosCount--) {

            //Print SheetHeader and Origin Pos
            printf("Cell data in (%d,%d) ", p[passCount].x, p[passCount].y);

            //将坐标带进去做.
            for (int i = 0; i < commandCount; ++i) {
                // EX Exchange Cell
                if (memcmp(c[i].type, "EX", 2) == 0) {
                    EX(p[passCount].x, p[passCount].y, i);
                }
                // DC 删除列
                if (memcmp(c[i].type, "DC", 2) == 0) {
                    if (DC(p[passCount].x, p[passCount].y, i) == -1) {
                        break;
                    }
                }
                //DR 删除行
                if (memcmp(c[i].type, "DR", 2) == 0) {
                    if (DR(p[passCount].x, p[passCount].y, i) == -1) {
                        break;
                    }
                }
                // IC insert
                if (memcmp(c[i].type, "IC", 2) == 0) {
                    IC(p[passCount].x, p[passCount].y, i);
                }
                //IR insert
                if (memcmp(c[i].type, "IR", 2) == 0) {
                    IR(p[passCount].x, p[passCount].y, i);
                }
            }

            //Output result
            if (p[passCount].x && p[passCount].y) {
                //不输出GONE
                printf("moved to (%d,%d)\n",p[passCount].x,p[passCount].y);
            } else {
                printf("GONE\n");
            }
            passCount++;
        }
    }
}