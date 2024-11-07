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
    int amountOfTime(TreeNode* root, int start) {
        map<int, vector<int>> adj;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left)
            {
                q.push(curr->left);
                adj[curr->val].push_back(curr->left->val);
                adj[curr->left->val].push_back(curr->val);
            }
            if(curr->right)
            {
                q.push(curr->right);
                adj[curr->val].push_back(curr->right->val);
                adj[curr->right->val].push_back(curr->val);
            }
        }
        queue<pair<int, int>> q2;
        unordered_set<int> st;
        q2.push({start, 0});
        st.insert(start);
        int maxi=0;
        while(!q2.empty())
        {
            int curr=q2.front().first;
            int level=q2.front().second;
            maxi=max(maxi, level);
            q2.pop();
            for(auto i:adj[curr])
            {
                if(st.count(i)==0)
                {
                    q2.push({i, level+1});
                    st.insert(i);
                }
            }
        }
        return maxi;
    }
};