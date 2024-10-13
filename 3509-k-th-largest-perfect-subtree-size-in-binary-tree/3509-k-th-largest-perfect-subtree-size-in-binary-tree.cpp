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
    vector<int> ans;
    vector<int> f(TreeNode* root)
    {
        if(root==NULL)
            return {1, 0, -1};
        vector<int> l = f(root->left);
        vector<int> r = f(root->right);
        if(l[0] and r[0] and l[2]==r[2])
        {
            int xx = l[1] + r[1] + 1;
            ans.push_back(xx);
            return {1, xx, l[2] + 1};
        }
        return {0, 0, 0};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        f(root);
        sort(ans.rbegin(), ans.rend());
        if(k>ans.size())
            return -1;
        return ans[k-1];
    }
};