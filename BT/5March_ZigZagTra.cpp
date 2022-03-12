//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
//https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1/


#include <bits\stdc++.h>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        queue<TreeNode *> q;
        if (!root)
            return ans;
        q.push(root);
        int flag = 1;
        while (!q.empty())
        {
            int n = q.size();
            vector<int>v;
            for (int i = 0; i < n; i++)
            {
                auto it = q.front();
                q.pop();
                v.push_back(it->val);
                if (it->left)
                {
                    q.push(it->left);
                }
                if (it->right)
                {
                    q.push(it->right);
                }
            }
            if (flag)
            {
                ans.push_back(v);
                flag = 0;
            }
            else
            {
                reverse(v.begin(), v.end());
                ans.push_back(v);
                flag = 1;
            }
        }
        return ans;
    }
};

/*
[3,9,20,null,null,15,7]
[1]
[]
//
[[3],[20,9],[15,7]]
[[1]]
[]
*/