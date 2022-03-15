// #include<bits\stdc++.h>
#include<bits\stdc++.h>
struct Node {
    int key;
    Node *left, *right;
};
using namespace std;
int findLargestSubtreeSumUtil(Node* root, int& ans)
{
    // If current node is null then
    // return 0 to parent node.
    if (root == NULL)    
        return 0;
    // Subtree sum rooted at current node.
    int currSum = root->key +
      findLargestSubtreeSumUtil(root->left, ans)
      + findLargestSubtreeSumUtil(root->right, ans);
    // Update answer if current subtree
    // sum is greater than answer so far.
    ans = max(ans, currSum);
    // Return current subtree sum to
    // its parent node.
    return currSum;
}
// Function to find largest subtree sum.
int findLargestSubtreeSum(Node* root)
{
    // If tree does not exist,
    if (root == NULL)    
        return 0;
    int ans = INT_MIN;
    // find maximum subtree sum.
    findLargestSubtreeSumUtil(root, ans);
    return ans;
}