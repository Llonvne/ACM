#include <bits/stdc++.h>
using namespace std;

#define MOVE "move"
#define ONTO "onto"
#define MAX_SIZE_BLOCK 25
#define SOURCE command.source.value
#define DEST command.destination.value
int blockCount;
vector<int> p[MAX_SIZE_BLOCK];
struct Value{
    int value;
    int pileNumber;
    int noNumber;
};
struct Command{
    string prefix;
    string suffix;
    Value source;
    Value destination;
};
Command command;
int Init(){
    scanf("%d",&blockCount);
    for (int i = 0; i < blockCount; ++i) {
        p[i].push_back(i);
    }
    return 1;
}
int InputCommand(){
    cin >> command.prefix;
    if (command.prefix == "quit"){
        return 0;
    }
    cin >> command.source.value >> command.suffix >> command.destination.value;
    return 1;
}
void FindValue(){
    int findCount = 0;
    for (int i = 0; i < blockCount; ++i) {
        for (int j = 0; j < p[i].size(); ++j) {

            if (findCount == 2){
                return;
            }

            if (p[i][j] == SOURCE){
                command.source.pileNumber = i;
                command.source.noNumber = j;
                findCount++;
            }

            if (p[i][j] == DEST){
                command.destination.pileNumber = i;
                command.destination.noNumber = j;
                findCount++;
            }
        }
    }
}
void Back(int value){
    int pileNumberBuffer, noNumberBuffer;

    if (value == SOURCE){
        pileNumberBuffer = command.source.pileNumber;
        noNumberBuffer = command.source.noNumber;
    }else {
        pileNumberBuffer = command.destination.pileNumber;
        noNumberBuffer = command.destination.noNumber;
    }

    for (int i = noNumberBuffer+1; i < p[pileNumberBuffer].size(); ++i) {
        int moveValue = p[pileNumberBuffer][i];
        p[moveValue].push_back(moveValue);
    }

    p[pileNumberBuffer].resize(noNumberBuffer+1);
}
void Move(){

    int sourceStart = command.source.noNumber;
    int sourceEnd = (int)p[command.source.pileNumber].size();
    int destPile = command.destination.pileNumber;

    for (int i = sourceStart; i < sourceEnd;i++){
        p[destPile].push_back(p[command.source.pileNumber][i]);
    }

    p[command.source.pileNumber].resize(sourceStart);
}
void PrintResult(){
    for (int i = 0; i < blockCount; ++i) {
        printf("%d:",i);

        if (!p[i].empty()){
            for (int j : p[i]) {
                printf(" %d",j);
            }
        }

        printf("\n");
    }
}
int main(){
        Init();
        while (InputCommand()){
            FindValue();
            //检查错误
            if (command.source.pileNumber == command.destination.pileNumber){
                continue;
            }

            if (command.prefix == MOVE){
                Back(SOURCE);
            }
            if (command.suffix == ONTO){
                Back(DEST);
            }

            Move();
        }

        PrintResult();
}