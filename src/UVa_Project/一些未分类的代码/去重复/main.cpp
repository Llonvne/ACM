#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int newPoint = 0;
        for (int i = 0;i < nums.size(); i++) {
            if (newPoint == 0 || nums[i] != nums[newPoint]) {
                nums[newPoint] = nums[i];
                newPoint++;
            }
        }
        return newPoint - 1;
    }
};

int main() {
    vector<int> tests = {
            1,1,2
    }
    Solution::removeDuplicates(tests);
    for (int i = 0; i < tests.size(); i++){
        printf("%d",nums[i]);
    }
}
