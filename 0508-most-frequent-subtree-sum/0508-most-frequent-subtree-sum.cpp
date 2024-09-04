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
    map<int, int> mp;
    int f(TreeNode* root)
    {
        if(!root->left and !root->right)
        {
            mp[root->val]++;
            return root->val;
        }
        int l=0, r=0;
        if(root->left)
            l=f(root->left);
        if(root->right)
            r=f(root->right);
        mp[root->val+l+r]++;
        return root->val+l+r;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root->left and !root->right)
            return {root->val};
        f(root);
        int maxi=0;
        vector<int> ans;
        for(auto i:mp)
            maxi=max(maxi, i.second);
        for(auto i:mp)
        {
            if(i.second==maxi)
                ans.push_back(i.first);
        }
        return ans;
    }
};