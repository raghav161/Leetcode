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
class Solution {
public:
    int f(TreeNode* root)
    {
        if (root==NULL)
            return 0;
        return max(f(root->right), f(root->left)) + 1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root==NULL)
            return NULL;
        int right_depth = f(root->right);
        int left_depth = f(root->left);
        if (right_depth == left_depth)
            return root;
        if (right_depth < left_depth) 
            return lcaDeepestLeaves(root->left);
        return lcaDeepestLeaves(root->right);
    }
};