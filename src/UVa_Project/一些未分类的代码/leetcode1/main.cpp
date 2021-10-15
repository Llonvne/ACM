#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;
        vector<int> b(2,-1);

        //建立哈希表
        for (int i = 0; i < nums.size(); i++) {
            a.insert(map<int,int>::value_type(nums[i],i));
        }

        //循环hash表
        for (int i = 0; i < nums.size(); i++) {
            //找到了而且不是自己
            if (a.count(target - nums[i]) > 0 && a[target - nums[i]]!= i){
                b[0] = i;
                b[1] = a[target - nums[i]];
                break;
            }
        }

        return b;

    }
};
