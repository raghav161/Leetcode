class Solution {
public:
    int f(int ext, int ind, vector<int>& nums, vector<vector<int>> &dp){
        if(ind == nums.size()) 
            return nums[ext];
        if(ind == nums.size()-1) 
            return max(nums[ext], nums[ind]);
        if(dp[ind][ext] != -1) 
            return dp[ind][ext];
        int case1 = max(nums[ext], nums[ind]) + f(ind+1, ind+2, nums, dp);
        int case2 = max(nums[ind], nums[ind+1]) + f(ext, ind+2, nums, dp);
        int case3 = max(nums[ext], nums[ind+1]) + f(ind, ind+2, nums, dp);
        return dp[ind][ext] = min({case1, case2, case3});
    }

    int minCost(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return f(0, 1, nums, dp);
    }
};