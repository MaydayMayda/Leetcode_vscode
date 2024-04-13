/*
 * @Title: 找到冠军 II
 * @Label: 图
 * @Link: https://leetcode.cn/problems/find-champion-ii/
 * @Author: zhou
 * @Date: 2024-04-13 14:17:15
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
    vector<vector<int>> adjacent;
    vector<int> winner;
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        adjacent.resize(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adjacent[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = 0; i < n; i++)
        {
            if (adjacent[i].size() == 0)
                winner.push_back(i);
        }
        if (winner.size() == 0) return 0;
        else if (winner.size() == 1) return winner[0];
        else return -1;
        
    }
};
int main()
{
    int n = 3;
    vector<vector<int>>edges{{0,1},{1,2}};
    Solution s;
    cout<<s.findChampion(n, edges);
    return 0;
}
