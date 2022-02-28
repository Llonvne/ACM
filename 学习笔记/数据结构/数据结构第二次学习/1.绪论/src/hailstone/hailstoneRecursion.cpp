// Hailstone Recursion Algorithm
static void HailstoneGen(vector<int>& hailstone,int n){
    // 递归基
    if (n == 1){
        hailstone.push_back(1);
        return;
    }
    // 把自己推入
    hailstone.push_back(n);
    // 分别处理
    if (n % 2 == 0){
        HailstoneGen(hailstone,n/2);
    }
    else {
        HailstoneGen(hailstone,3*n+1);
    }
}