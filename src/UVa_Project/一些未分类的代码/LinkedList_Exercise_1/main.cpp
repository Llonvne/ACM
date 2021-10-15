#include "stdlib.h"
#include "stdio.h"
struct LinkedListNode {
    int value;

    struct LinkedListNode * next;
};
struct LinkedListNode * createLinkedList(){
    return (struct LinkedListNode *) malloc(sizeof(struct LinkedListNode));
}
void insertvalue(struct LinkedListNode * L,int value){
    L->value = value;
    L->next = createLinkedList();
    L = L->next;
}
void SequenceInsertValue(struct LinkedListNode * listStart,int value){
    struct LinkedListNode * i = listStart;
    struct LinkedListNode * last ;
    while(i->value > value){

        if (i->next == NULL){
            i->next = createLinkedList();
            i = i->next;
            insertvalue(i,value);
            return;
        }
        last = i;
        i = i->next;
    }

    if (i->next != NULL){

        struct LinkedListNode * Buffer ;
        Buffer = createLinkedList();
        insertvalue(Buffer,value);

        struct LinkedListNode * NextBuffer = i;
        last -> next = Buffer;
        Buffer->next = i;
    }
}
void PrintLinkedList(struct LinkedListNode * start){
    for (struct LinkedListNode * i = start;i != NULL ; i = i-> next) {
        if (i->value == 0 ){
            return;
        }
        printf("%d\n",i->value);
    }
}

struct UnionOrIntersectionSolution{
    int select;

    struct LinkedListNode * A;
    struct LinkedListNode * B;

    struct LinkedListNode * result;
};
int ReturnSelectAndPrintMenu(){
    printf("1.并集\n");
    printf("2.交集\n");
    printf("请输入数字选项>>>");
    int insertvalue;
    scanf("%d",&insertvalue);
    return insertvalue;
}
void createSolutionLinkedList(struct UnionOrIntersectionSolution& Solution){

}
int main() {

    int select = ReturnSelectAndPrintMenu();

    struct UnionOrIntersectionSolution Solution;
    Solution.select = select;



}