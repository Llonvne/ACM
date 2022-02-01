// 左循环移动
static void leftK(vector<int>& nums,int k){
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());
}
    // 右循环移动
static void rightK(vector<int>& nums, int k) {
    k = (int)nums.size() - (k % (int)nums.size());
    leftK(nums, k);
}

// 其中右循环移动(rightK)需要调用左循环移动，使用时需一并附上
// 此算法需要调用 <algorithm> 算法库
