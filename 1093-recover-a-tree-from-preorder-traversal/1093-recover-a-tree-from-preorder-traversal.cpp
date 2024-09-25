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
    TreeNode* f(string& s, int depth, int& i)
    {
        if(i>=s.length())
            return NULL;
        int d=0;
        while(i<s.length() and s[i]=='-')
        {
            d++;
            i++;
        }
        if(d!=depth)
        {
            i-=d;
            return NULL;
        }
        string temp="";
        while(i<s.length() and s[i]!='-')
        {
            temp+=s[i];
            i++;
        }
        int value = stoi(temp);
        TreeNode* node = new TreeNode(value);
        node->left = f(s, d+1, i);
        node->right = f(s, d+1, i);
        return node;
    }   
    TreeNode* recoverFromPreorder(string s)
    {
        int i=0;
        TreeNode* root=f(s, 0, i);
        return root;
    }
};