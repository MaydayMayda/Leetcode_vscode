/*
 * @Title: 找到冠军 I
 * @Label: 数组、矩阵
 * @Author: zhou
 * @Date: 2024-04-12 00:29:19
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> 
#include <numeric>

using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0;; i++)
        {
            if (accumulate(grid[i].begin(),grid[i].end(),0) == n-1) return i;
        }
        
    }
};
int main()
{
    vector<vector<int>>grid{{0,0,1},{1,0,1},{0,0,0}};
    Solution s;
    cout<<s.findChampion(grid);
    return 0;
}
