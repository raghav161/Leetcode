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
    long long maxi=0;
    long long f(TreeNode* root, long long total)
    {
        if(root==NULL)
            return 0;
        long long l=f(root->left, total);
        long long r=f(root->right, total);
        long long currtot=(long long)root->val+l+r;
        maxi=max(maxi, (long long)(total-currtot)*currtot);
        return currtot;
    }
    int maxProduct(TreeNode* root) {
        long long sum=0;
        sum=f(root, sum);
        f(root, sum);
        long long m=1e9+7;
        return maxi%m;
    }
};