/*
 * @Title: 正整数和负整数的最大计数
 * @Label: 数组、二分查找、计数
 * @Author: zhou
 * @Date: 2024-04-09 22:09:44
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& nums, int val) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] >= val) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    int maximumCount(vector<int>& nums) {
        int pos1 = lowerBound(nums, 0);
        int pos2 = lowerBound(nums, 1);
        return max(pos1, (int) nums.size() - pos2);
    }
};
int main()
{
    vector<int>nums{-2,-1,-1,1,2,3};
    Solution s;
    s.maximumCount(nums);
    return 0;
}
