// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/

// A binary tree Node

#include <bits\stdc++.h>
// #include<vector.h>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 
void lt(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        ans.push_back(root->data);
        lt(root->left, ans);
    }
    else if (root->right != NULL)
    {
        ans.push_back(root->data);
        lt(root->right, ans);
    }
}
void leaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    leaf(root->left, ans);
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    leaf(root->right, ans);
}
void rt(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->right != NULL)
    {
        rt(root->right, ans);
        ans.push_back(root->data);
    }
    else if (root->left != NULL)
    {
        rt(root->left, ans);
        ans.push_back(root->data);
    }
}

class Solution {
public:
    vector<int>boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        ans.push_back(root->data);
        lt(root->left, ans);
        leaf(root, ans);
        rt(root->right, ans);
        return ans;
    }
};