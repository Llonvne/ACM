#include <stdio.h>

#define DEFAULT_MONSTER_VOLUME 1000;
struct monster{
    int bloodVolume = DEFAULT_MONSTER_VOLUME;
};

int main(){

    monster m;

    printf("怪物的血量是 %d",m.bloodVolume);

    int damage;
    scanf("%d",&damage);

    m.bloodVolume -= damage;

    printf("怪物的剩余血量的是 %d ", m.bloodVolume );
}
