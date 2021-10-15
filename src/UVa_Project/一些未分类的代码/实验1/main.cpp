#include "bits/stdc++.h"

using namespace std;
#define MAX_LENEAR_LIST_LENGTH 1000


void reverse(int *,int count);

int main(){

    int LinearList[MAX_LENEAR_LIST_LENGTH];
    int count;
    cout << "请输入线性表的长度 >>>";
    cin >> count;
    cout << "请开始输入线性表：" << endl;

    for (int i = 0; i < count; ++i) {
        cin >> LinearList[i];
    }

    cout << "开始输出反转后的结果";
    reverse(LinearList,count);

    for (int i = 0; i < count; ++i) {
        cout << LinearList[i] << " ";
    }

}

void reverse(int * linearList,int count){

    int startPos = 0,endPos = count -1;

    for (;startPos != endPos ;startPos++,endPos--){
        swap(linearList[startPos],linearList[endPos]);
    }
}
