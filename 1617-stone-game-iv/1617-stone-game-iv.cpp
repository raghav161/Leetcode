class Solution {
public:
    int dp[100001];
    int f(int n)
    {
        if(n<=0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        for(int i=1;i*i<=n;i++)
        {
            if(f(n-i*i)==0)
                return dp[n]=1;
        }
        return dp[n]=0;
    }
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        return f(n);
    }
};