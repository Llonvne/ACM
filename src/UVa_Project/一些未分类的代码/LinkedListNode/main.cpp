#include "cstdio"
#include "cstdlib"

struct LinkedListNode{
    int value;

    LinkedListNode * next;
};

LinkedListNode * CreateLinkedListMemory();

struct LinkedList{
    LinkedListNode * start;
    LinkedListNode * end;

    LinkedListNode * getNode(int value){
        LinkedListNode * valueNode = CreateLinkedListMemory();
        valueNode->value = value;

        return valueNode;
    }

    LinkedList(){
        start = CreateLinkedListMemory();
        start->next = nullptr;
        end = start;
        end->value = 0;
    }

    void push_back(int value){
        end->value = value;
        end->next = CreateLinkedListMemory();
        end = end->next;
        end->value = 0;
        end -> next = nullptr;
    }

    void print() const{
        LinkedListNode * i = this->start;
        while (i != end){
            printf("%d ",i->value);
            i = i->next;
        }
    }

    void insert(int value){
        LinkedListNode * i = this->start;
        LinkedListNode * before ;

        while (value < i->value){
            if (i->next == nullptr){
                push_back(value);
                return ;
            }
            before = i;
            i = i->next;
        }

        LinkedListNode * valueNode = getNode(value);
        if (i != this->start){
            before->next = valueNode;
        }else {
            start = valueNode;
        }
        valueNode->next = i;
    }

    void inputWithKeyBoard(){
        while (true){
            int inputValue;
            scanf("%d",&inputValue);
            if (inputValue == 0){
                return;
            }
            push_back(inputValue);
        }
    }

    bool exist(int value) const{
        LinkedListNode * i = start;
        while (i != end){
            if (i->value == value){
                return true;
            }
            i = i->next;
        }
        return false;
    }
};

LinkedListNode * CreateLinkedListMemory(){
    return (LinkedListNode *) malloc(sizeof(LinkedListNode));
}

struct Union { // 并

    LinkedList Solution;
    LinkedList * A;
    LinkedList * B;

    Union(LinkedList * A,LinkedList * B){
        this -> A = A;
        this -> B = B;

        getSolution();
    }

    void getSolution(){
        if (A == nullptr || B == nullptr){
            printf("请为函数配置需要处理的变量");
        }

        LinkedListNode * i = A->start;
        while (i != A->end){
            Solution.push_back(i->value);
            i = i->next;
        }

        i = B->start;
        while (i != B->end){
            if (!A->exist(i->value)){
                Solution.push_back(i->value);
            }
            i = i->next;
        }
    }

    void print() const{
        Solution.print();
    }
};

struct Intersections{

    LinkedList Solution;
    LinkedList * A;
    LinkedList * B;

    Intersections(LinkedList * A,LinkedList * B){
        this -> A = A;
        this -> B = B;

        getSolution();
    }

    void getSolution(){
        if (A == nullptr || B == nullptr){
            printf("请为函数配置需要处理的变量");
        }

        LinkedListNode * i = A->start;
        while (i != A->end){
            if (B->exist(i->value)){
                Solution.push_back(i->value);
            }
            i = i->next;
        }
    }

    void print() const{
        Solution.print();
    }
};

int main(){
    LinkedList A;
    A.inputWithKeyBoard();
    A.print();
    int x;
    scanf("%d",&x);
    A.insert(x);
    A.print();
}