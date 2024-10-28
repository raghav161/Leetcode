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
    vector<int> f(TreeNode* root)
    {
        if(root==NULL)
            return {};
        vector<int> left=f(root->left);
        vector<int> right=f(root->right);
        vector<int> ans(left.begin(), left.end());
        ans.push_back(root->val);
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root==NULL)
            return NULL;
        vector<int> temp=f(root);
        temp.push_back(val);
        return constructMaximumBinaryTree(temp);
    }
};