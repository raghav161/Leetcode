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
    unordered_map<int,int> l, r, ans;
    int height(TreeNode* root)
    {
        if(root==NULL) 
            return 0;
        int le = height(root->left);
        int re = height(root->right);
        l[root->val] = le;
        r[root->val] = re;
        return max(le, re)+1;      
    }
    void fun(TreeNode* root, int maxi, int depth){
        if(root==NULL)
            return;
        ans[root->val] = maxi;
        fun(root->left, max(maxi, depth+r[root->val]), depth+1);
        fun(root->right, max(maxi, depth+l[root->val]), depth+1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& q) {
        height(root);
        fun(root->left, r[root->val], 1);
        fun(root->right, l[root->val], 1);
        vector<int> res(q.size());
        for(int i=0;i<q.size();i++)
            res[i]=ans[q[i]];
        return res;
    }
};