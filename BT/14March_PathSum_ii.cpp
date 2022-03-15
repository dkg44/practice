//https://leetcode.com/problems/path-sum-ii/

#include <bits\stdc++.h>
#include<vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ;qus ans and solution
class Solution {
     public:
    vector<vector<int>> res;
    void dfsFun(TreeNode* root, long long val, int targetSum, vector<int> list){
        // base condition
        if(!root) return;
        // val = val*10;
        val = val+root->val;
        list.push_back(root->val);
        // leaf condition
        if(!root->left && !root->right && val==targetSum){ 
            res.push_back(list);
            return;
        }
        dfsFun(root->left, val, targetSum, list);
        dfsFun(root->right, val, targetSum, list);
        list.erase(list.end()-1);
       // the above line can reduce the TC 
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> list;
        long long val=0;
        dfsFun(root,val,targetSum, list);
        return res;
    }
};