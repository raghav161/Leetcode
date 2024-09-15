class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<long long> dp(5, LLONG_MIN);
        dp[0]=0;
        for(int j=0;j<b.size();j++)
        {
            for(int i=3;i>=0;i--)
            {
                if(dp[i]!=LLONG_MIN)
                    dp[i+1]=max(dp[i+1], dp[i]+(long long)a[i]*b[j]);
            }
        }
        return dp[4];
    }
};