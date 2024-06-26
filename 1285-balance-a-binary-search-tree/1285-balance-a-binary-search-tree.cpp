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
    void inorder(TreeNode* node, vector<int>& arr)
    {
        if(node!=NULL)
        {
            inorder(node->left, arr);
            arr.push_back(node->val);
            inorder(node->right, arr);
        }
    }
    TreeNode* constructBST(vector<int>& arr, int start, int end)
    {
        if(start <= end)
        {
            int mid = (end+start)/2;
            TreeNode* node = new TreeNode(arr[mid]);
            node->left = constructBST(arr, start, mid-1);
            node->right = constructBST(arr, mid+1, end);
            return node;
        }
        return NULL;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        return constructBST(arr, 0, arr.size()-1);
    }
};