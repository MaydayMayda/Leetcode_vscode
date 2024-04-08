/*
 * @Title: 二叉树的最大深度
 * @Label: 树、深度优先搜索、广度优先搜索、二叉树
 * @Author: zhou
 * @Date: 2024-04-08 22:01:00
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
                if(root == nullptr)
        {
            return 0;
        }
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        return leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main()
{
    TreeNode root;
    Solution s;
    s.maxDepth(&root);
    return 0;
}
