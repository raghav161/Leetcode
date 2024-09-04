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
    unordered_map<int, int> mp;
    int f(TreeNode* root, int& maxi)
    {
        if(root->left==NULL and root->right==NULL)
        {
            mp[root->val]++;
            maxi=max(maxi, mp[root->val]);
            return root->val;
        }
        int l=0, r=0;
        if(root->left)
            l=f(root->left, maxi);
        if(root->right)
            r=f(root->right, maxi);
        mp[root->val+l+r]++;
        maxi=max(maxi, mp[root->val+l+r]);
        return root->val+l+r;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root->left and !root->right)
            return {root->val};
        int maxi=0;
        f(root, maxi);
        vector<int> ans;
        for(auto i:mp)
        {
            if(i.second==maxi)
                ans.push_back(i.first);
        }
        return ans;
    }
};