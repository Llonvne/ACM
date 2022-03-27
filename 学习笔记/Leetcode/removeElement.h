//https://leetcode-cn.com/problems/remove-element/submissions/
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pioneer = 0;// 探路先锋
        int guard = 0;// [0,guard) 的元素都是没有val的
        while (pioneer < nums.size()){ // 当先锋没有越界
            // 当 pioneer 等于 val 就一直向后走
            while (pioneer < nums.size() && nums[pioneer] == val){
                ++pioneer;
            }
            // 此时pioneer 指向最后一个元素或者第一个非val的元素，如果是最后一个元素就返回
            if (pioneer == nums.size()){
                break;
            }
            // 交换pioneer 和 guard pioneer是第一个非Val元素，guard是非val的超尾
            swap(nums[guard],nums[pioneer]);
            // pioneer 和 guard向后移动
            guard++;
            pioneer++;
        }
        return guard ;
    }
};