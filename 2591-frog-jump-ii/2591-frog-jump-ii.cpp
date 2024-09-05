class Solution {
public:
    int f(int i, vector<int>& stones, vector<int>& dp)
    {
        if(i==0)
            return 0;
        if(i==1)
            return abs(stones[i] - stones[i-1]);
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=max(abs(stones[i]-stones[i-2]), f(i-1, stones, dp));
    }

    int maxJump(vector<int>& stones) {
        vector<int> dp(stones.size(), -1);
        return f(stones.size()-1, stones, dp);
    }
};