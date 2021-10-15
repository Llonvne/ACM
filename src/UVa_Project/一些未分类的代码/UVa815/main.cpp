#include "bits/stdc++.h"
using namespace std;

#define MAX_SIZE (30 * 30)
const int FILL_ONE_BLOCK_WATER_COST = 100;
int Input();
int Blocks[MAX_SIZE];
int totalLength;
int waterVolume;

int main() {
    int region = 0;
    while(Input()) {

        sort(Blocks,Blocks+totalLength);
        int waterCostCountSum = 0;
        int i;
        for (i = 0 ; i < totalLength - 1; i++) {

            int heightDiff = abs(Blocks[i+1] - Blocks[i]);

            waterCostCountSum = heightDiff * (FILL_ONE_BLOCK_WATER_COST * (i + 1));

            if (waterVolume < waterCostCountSum){
                break;
            }else {
                waterVolume -= waterCostCountSum;
            }
        }

        auto globalSeaLevel = (double)Blocks[i];
        globalSeaLevel += (double)waterVolume/((double)(i + 1) * FILL_ONE_BLOCK_WATER_COST);

        region++;
        printf("Region %d\n",region);
        printf("Water level is %.2f meters.\n",globalSeaLevel);
        if (waterVolume == 0){
            printf("%.2f percent of the region is under water.\n\n",100 * (float)(i) / (float)totalLength) ;
        }else {
            printf("%.2f percent of the region is under water.\n\n", 100 * (float) (i + 1) / (float) totalLength);
        }
    }
}
int Input() {
    int length,width;
    scanf("%d %d",&length,&width);
    totalLength = length * width;

    if (totalLength == 0){
        return 0;
    }

    for (int i = 0; i < totalLength; i++){
        scanf("%d",&Blocks[i]);
    }

    scanf("%d",&waterVolume);

    return 1;
}