#include <stdio.h>
using namespace std;

void insert(int *,int count,int insertValue);
void swap(int& a,int& b){
    int buffer = a;a = b; b = buffer;
}

int main(){

    int linearList[1000];

    printf("请输入一个线性表的长度>>>");

    int count ;
    scanf("%d",&count);

    printf("请输入一个有序的线性表>>>");
    for (int i = 0; i < count; ++i) {
        scanf("%d",&linearList[i]);
    }

    printf("请输入要插入的数字>>>");
    int inerstValue;
    scanf("%d",&inerstValue);

    insert(linearList,count,inerstValue);

    printf("正在输出完成的文档");
    for (int i = 0; i < count+1; ++i) {
        printf("%d ",linearList[i]);
    }

}

void insert(int * linearList,int count,int insertValue){
    for (int i = 0; i < count; i++){

        if (insertValue > linearList[i]){
            continue;
        }else {

            for (int endPos = count-1;endPos>=i;endPos--){
                swap(linearList[endPos],linearList[endPos+1]);
            }

            linearList[i] = insertValue;
        }
    }
}