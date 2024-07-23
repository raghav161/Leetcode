class Solution {
public:
    int f(vector<vector<int>>& piles, vector<vector<int>>& dp, int i, int k)
    {
        if(k==0 || i==piles.size())
            return 0;
        if(dp[i][k])
            return dp[i][k];
        int maxi=f(piles, dp, i+1, k), ans=0;
        for(int j=0;j<piles[i].size() && j<k;j++)
        {
            ans+=piles[i][j];
            maxi=max(maxi, ans+f(piles, dp, i+1, k-j-1));
        }
        return dp[i][k]=maxi;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size()+1, vector<int> (k+1));
        return f(piles, dp, 0, k);
    }
};