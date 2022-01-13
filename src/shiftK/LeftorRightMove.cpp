    // reverse 为 C++提供的函数

    static void rightK(vector<int>& nums, int k) {
        k = (int)nums.size() - (k % (int)nums.size());
        leftK(nums, k);
    }
    static void leftK(vector<int>& nums,int k){
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }