//https://leetcode.com/problems/sum-root-to-leaf-numbers/

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Qus ANd Solution
class Solution {
    long long ans=0, val=0;
    void dfsFun(TreeNode* root, long long val){
        // base condition
        if(!root) return;
        
        val = val*10;
        val = val+root->val;
        // leaf condition
        if(!root->left && !root->right){
            ans = ans+val;
            return;
        }
        dfsFun(root->left, val);
        dfsFun(root->right, val);
        
    }
public:
    int sumNumbers(TreeNode* root) {
        //base condition
        if(!root) return 0;
        dfsFun(root, 0);
        return ans;
    }
};