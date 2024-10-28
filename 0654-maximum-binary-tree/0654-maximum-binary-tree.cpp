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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())
            return NULL;
        auto i=max_element(nums.begin(), nums.end());
        TreeNode* root = new TreeNode(*i);
        if(i!=nums.begin())
        {
            vector<int> left(nums.begin(), i);
            root->left=constructMaximumBinaryTree(left);
        }
        if(i!=nums.end()-1)
        {
            vector<int> right(i+1, nums.end());
            root->right=constructMaximumBinaryTree(right);
        }
        return root;
    }
};