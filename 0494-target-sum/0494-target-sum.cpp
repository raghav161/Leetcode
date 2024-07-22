class Solution {
public:
    int helper(vector<int>& nums, int k, int i, vector<vector<int>>& dp, int currSum, int totalsum)
    {   
        if(k==currSum && i==nums.size()) 
            return 1;
        if(i==nums.size()) 
            return 0;
        if(dp[i][currSum+totalsum] != -1)
            return dp[i][currSum+totalsum];
        int sub = helper(nums, k, i+1, dp, currSum-nums[i], totalsum);
        int add = helper(nums, k, i+1, dp, currSum+nums[i], totalsum);
        return dp[i][currSum+totalsum] = sub + add;
    }
    int findTargetSumWays(vector<int>& nums, int k) 
    {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size()+1, vector<int>(2*totalsum+1, -1));
        return helper(nums, k, 0, dp, 0, totalsum);
    }
};