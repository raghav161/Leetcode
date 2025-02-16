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
    int rob(TreeNode* root, int &robMax, int &notRobMax) {
        if(!root) 
            return 0;
        int leftRobMax = 0, leftNotRobMax = 0, rightRobMax = 0, rightNotRobMax = 0;
        int leftMax = rob(root->left, leftRobMax, leftNotRobMax);
        int rightMax = rob(root->right, rightRobMax, rightNotRobMax);
        robMax = root->val + leftNotRobMax + rightNotRobMax;
        notRobMax = leftMax + rightMax;
        return max(robMax, notRobMax);
    }
    int rob(TreeNode* root) {
        int robMax = 0, notRobMax = 0;
        return rob(root, robMax, notRobMax);
    }
};