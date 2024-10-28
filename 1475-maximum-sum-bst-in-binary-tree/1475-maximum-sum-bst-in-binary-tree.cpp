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
    vector<int> f(TreeNode* root, int& ans) {
        if(root==NULL) 
            return {INT_MAX, INT_MIN, 0};
        vector<int> left=f(root->left, ans);
        vector<int> right=f(root->right, ans);
        if(left.empty() or right.empty() or root->val <= left[1] or root->val >= right[0]) 
            return {};
        int curr_sum = left[2] + right[2] + root->val;
        ans = max(ans, curr_sum);
        return {min(left[0], root->val), max(right[1], root->val), curr_sum};
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        f(root, ans);
        return max(0, ans);
    }
};