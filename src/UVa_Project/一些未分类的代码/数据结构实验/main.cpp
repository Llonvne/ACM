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
        cin >> linearList[i];
    }

    cout << "开始输出反转后的结果";
    reverse(linearList,count);

    for (int i = 0; i < count; ++i) {
        cout << linearList[i] << " ";
    }

}

void reverse(int * linearList,int count){

    int startPos = 0,endPos = --count;

    for (i = startPos;i != endPos ;i++,endPos--){
        swap(linearList[startPos],linearList[endPos]);
    }
}