class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> v(1);
        for(int i=1,j=0;i<nums.size();i++)
        {
            if((nums[i]%2)==(nums[i-1]%2))
                j++;
            v.push_back(j);
        }
        for(auto q:queries)
            ans.push_back(v[q[0]]==v[q[1]]);
        return ans;
    }
};