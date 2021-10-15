#include "bits/stdc++.h"
using namespace std;

#define MAXN 30

vector<int> pile[MAXN];

int n;

void Find(int value,int& pileNo,int& pileNumber){
    for (pileNo = 0 ; pileNo < n ;pileNo++){
        for (pileNumber = 0; pileNumber < pile[pileNo].size(); pileNumber++){
            if (pile[pileNo][pileNumber] == value) {
                return;
            }
        }
    }
}

void Clear(int value){
    int pileNo,pileNumber;
    Find(value,pileNo,pileNumber);

    for (pileNumber++;pileNumber < pile[pileNo].size();pileNumber++){
        pile[value].push_back(value);
    }

    // 利用 resize来改变大小！！！ 好办法！
    pile[pileNo].resize(pileNumber);
}

void Move(int sourceValue,int targetValue){
    int sourceValuePileNo,sourceValuePileNumber;
    Find(sourceValue,sourceValuePileNo,sourceValuePileNumber);
    int targetValuePileNo,targetValuePileNumber;
    Find(targetValue,targetValuePileNo,targetValuePileNumber);

    for (int i = sourceValuePileNumber;i < pile[sourceValuePileNo].size();i++){
        pile[targetValuePileNo].push_back(pile[sourceValuePileNo][i]);
    }

    pile[sourceValuePileNo].resize(sourceValuePileNo - 1);

}


int main(){

    cin >> n;

    //Init Vector
    for (int i = 0; i < n; ++i) {
        pile[i].push_back(i);
    }

    string frontCmd,latterCmd;
    int sourceValue,targetValue;

    while(cin >> frontCmd >> sourceValue >> latterCmd >> targetValue){

        int sourceValuePileNo,sourceValuePileNumber;
        Find(sourceValue,sourceValuePileNo,sourceValuePileNumber);
        int targetValuePileNo,targetValuePileNumber;
        Find(targetValue,targetValuePileNo,targetValuePileNumber);

        if (sourceValuePileNo == targetValuePileNo){
            continue;
        }

        if (frontCmd == "move"){
            Clear(sourceValue);
        }
        if (latterCmd == "onto"){
            Clear(targetValue);
        }

        Move(sourceValue,targetValue);

    }

    for (int i = 0;i < n;i++){
        printf("%d:",i);

        for (int j = 0; j < pile[i].size(); j++){
            printf(" %d",pile[i][j]);
        }

        printf("\n");
    }

}