class Solution {
public:
    int f(int i, vector<int>& nums, int target, vector<int>& dp)
    {
        if(i==nums.size()-1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MIN;
        for(int j=i+1;j<nums.size();j++)
        {
            if(abs(nums[j]-nums[i])<=target)
                ans=max(ans, 1+f(j, nums, target, dp));
        }
        return dp[i]=ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(), -1);
        int ans=f(0, nums, target, dp);
        if(ans>0)
            return ans;
        return -1;
    }
};