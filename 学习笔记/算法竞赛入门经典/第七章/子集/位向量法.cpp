void print_subset(int n,int * B,int cur){
    if(cur==n){
        for(int i=0;i<cur;i++){
            printf("%d ",B[i]);
        }
        printf("\n");
        return;
    }
    // 选择 cur 号元素
    B[cur] = 1;
    print_subset(n,B,cur+1);
    // 不选择 cur 号元素
    B[cur] = 0;
    print_subset(n,B,cur+1);
}