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
    vector<TreeNode*> result;
    set<int> st;
    TreeNode* helper(TreeNode* node, bool is_root) {
        if(node==NULL)
            return NULL;
        bool deleted = st.find(node->val) != st.end();
        if(is_root && deleted==0) 
            result.push_back(node);
        node->left = helper(node->left, deleted);
        node->right =  helper(node->right, deleted);
        return deleted ? NULL : node;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        for(auto& i:to_delete)
            st.insert(i);
        helper(root, 1);
        return result;
    }
};