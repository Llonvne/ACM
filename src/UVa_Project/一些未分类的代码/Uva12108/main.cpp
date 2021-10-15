#include "bits/stdc++.h"
using namespace std;
#define COULD_SLEEP 1
#define NOT_SLEEP 2
#define ALL_AWAKE 3
struct Student{
    int foucs;
    int sleep;
    int isSleep;
    int now;
    int loop;
};
Student student[10];
int studentCount;
int SleepCheck(){
    int sleepCount = 0;
    int awakeCount = 0;
    for (int i= 0; i < studentCount;i++){
        if (student[i].isSleep){
            sleepCount++;
        }else {
            awakeCount++;
        }
    }

    if (sleepCount == 0){
        return ALL_AWAKE;
    }
    if (sleepCount > awakeCount){
        return COULD_SLEEP;
    }
    return NOT_SLEEP;
}
void NextMin(Student stu){
    if (stu.now == stu.foucs){
        if (SleepCheck() == NOT_SLEEP){
            stu.now = 1;
            return;
        }else {
            stu.isSleep = true;
        }
    }

    if (stu.now > stu.loop){
        stu.now = 1;
        stu.isSleep = false;
    }

    stu.now ++;
}
int Input(){
    scanf("%d",&studentCount);
    if (!studentCount){
        return 0;
    }

    for (int i = 0;i < studentCount;i++){
        scanf("%d %d %d",&student[i].foucs,&student[i].sleep,&student[i].now);
        student[i].loop = student[i].foucs + student[i].sleep;
    }

    return 1;
}

int main(){
    while (Input()){
        int timeCount = 0;
        timeCount++;

        for (int i = 0; i < studentCount; i++) {
            NextMin(student[i]);
        }

        while ((SleepCheck() != ALL_AWAKE) && timeCount < 10000){
            for (int i = 0; i < studentCount; i++) {
                NextMin(student[i]);
            }
        }
        printf("%d",timeCount);
    }
}