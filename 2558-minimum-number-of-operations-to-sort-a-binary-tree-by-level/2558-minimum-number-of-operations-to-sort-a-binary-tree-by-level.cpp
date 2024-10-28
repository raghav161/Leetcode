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
    int minSwaps(vector<int>& nums)
	{
	    int n=nums.size();
	    vector<pair<int, int>> v;
	    for(int i=0;i<n;i++)
	        v.push_back({nums[i], i});
	    sort(v.begin(), v.end());
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        if(v[i].second!=i)
	        {
	            ans++;
	            swap(v[i], v[v[i].second]);
	            i--;
	        }
	    }
	    return ans;
	}
    int minimumOperations(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int count=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int> temp;
            while(n--)
            {
                TreeNode* topVal=q.front();
                q.pop();
                temp.push_back(topVal->val);
                if(topVal->left)
                    q.push(topVal->left);
                if(topVal->right)
                    q.push(topVal->right);
            }
            count+=minSwaps(temp);
        }
        return count;
    }
};