class Solution {
public:
    int Zero=0, One=0;
    int mod = 1000000007;
    int solve(int n, vector<int>& dp){
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = (solve(n-Zero, dp)%mod + solve(n-One, dp)%mod)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        Zero = zero;
        One = one;
        int ans = 0;
        vector<int> dp(high+1, -1);
        for(int i=low;i<=high;i++)
            ans=(ans+solve(i, dp)%mod)%mod;
        return ans;
    }
};