class Solution {
public:
    vector<vector<int>> ans;
    void subsets(vector<int>& nums, int i, vector<int>& temp)
    {
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++) 
        {
            temp.push_back(nums[j]);
            subsets(nums, j+1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int> temp;
        subsets(nums, 0, temp);
        return ans;
    }
};