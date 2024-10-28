/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    class info{
    public:
        int maxi;
        int mini;
        bool isBst;
        int sum;
    };
    
    info solve(TreeNode*root,int& ans){
        if(root==NULL)
            return {INT_MIN, INT_MAX, true, 0};
        info left = solve(root->left,ans);
        info right = solve(root->right,ans);
        info currNode;
        currNode.maxi = max(root->val, right.maxi);
        currNode.mini = min(root->val, left.mini);
        if(left.isBst && right.isBst && root->val> left.maxi && root->val < right.mini){
            currNode.isBst = 1;
            currNode.sum = left.sum + right.sum + root->val;
            ans=max(ans, currNode.sum);
        }
        else
            currNode.isBst = 0;
        return currNode;
    }
    int maxSumBST(TreeNode* root) {
        int sum=0;
        info t=solve(root, sum);
        return sum;
    }
};