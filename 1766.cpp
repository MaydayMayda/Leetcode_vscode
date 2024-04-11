/*
 * @Title: 互质树
 * @Label: 树、深度优先搜索、广度优先搜索、数组、数学、数论
 * @Author: zhou
 * @Date: 2024-04-11 00:21:39
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> 
#include <stack>
#include <utility>

using namespace std;

class Solution {
    vector<vector<int>> adjacent;
    vector<int> res;
    stack<pair<int,int>> stk[55];
    
    void dfs(int node,int pre,int depth, vector<int>& nums){
        int level = -1;
        int i = -1;
        for (int x = 1; x <= 50; x++) {
            if (stk[x].size() > 0 && stk[x].top().first > level && __gcd(x, nums[node]) == 1) {
                level = stk[x].top().first;
                i = stk[x].top().second;
            }
        }
        res[node] = i;
        for (auto next : adjacent[node]) {
            if (next != pre) {
                stk[nums[node]].push({depth, node});
                dfs(next, node, depth+1, nums);
                stk[nums[node]].pop();
            }
        }
    }
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        adjacent.resize(n);

        for (int i = 0; i < edges.size(); i++)
        {
            adjacent[edges[i][0]].push_back(edges[i][1]);
            adjacent[edges[i][1]].push_back(edges[i][0]);
        }
        res.resize(n);
        dfs(0, -1, 0, nums);
        return res;
    }
};
int main()
{
    vector<int>nums{5,6,10,2,3,6,15};
    vector<vector<int>>edges{{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    Solution s;
    s.getCoprimes(nums,edges);
    return 0;
}
