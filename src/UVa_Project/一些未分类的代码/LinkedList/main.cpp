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


int main() {

    struct LinkedListNode * p ;
    p = createLinkedList();
    struct LinkedListNode * start = p;

    while(true){
        int value;
        scanf("%d",&value);
        if (value == -999){
            break;
        }

        insertvalue(p,value);
        p->next = createLinkedList();
        p = p->next;
    }
    p->next = NULL;

    printf("正在拆分为 正，负链表");
    struct LinkedListNode * postive = createLinkedList();
    struct LinkedListNode * negative = createLinkedList();
    struct LinkedListNode * postive_start = postive;
    struct LinkedListNode * negative_start = negative;

    for (struct LinkedListNode * i = start; i != NULL ; i = i-> next) {
        struct LinkedListNode * insertList;
        if (i->value >=0){
            insertList = postive;
        }else {
            insertList = negative;
        }

        insertvalue(insertList,i->value);
        insertList->next = createLinkedList();
        insertList = insertList->next;

    }
    printf("正:");
    PrintLinkedList(postive_start);
    printf("负:");
    PrintLinkedList(negative_start);
}