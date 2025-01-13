class Solution {
public:
    int f(int i, int j, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp, int nutralize)
    {
        if(i==0 and j==0)
        {
            if(coins[i][j]>=0) 
                return coins[i][j];
            return (nutralize>0 ? 0 : coins[i][j]);
        }
        if(i<0 or j<0)
            return INT_MIN;
        if(dp[i][j][nutralize]!=INT_MIN)
            return dp[i][j][nutralize];
        int take = coins[i][j] + max(f(i-1, j, coins, dp, nutralize), f(i, j-1, coins, dp, nutralize));
        int nottake = INT_MIN;
        if(nutralize>0 and coins[i][j]<0)
            nottake = max(f(i-1, j, coins, dp, nutralize-1), f(i, j-1, coins, dp, nutralize-1));
        return dp[i][j][nutralize] = max(take, nottake);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        vector<vector<vector<int>>> dp(coins.size(), vector<vector<int>>(coins[0].size(), vector<int>(3, INT_MIN)));
        return f(coins.size()-1, coins[0].size()-1, coins, dp, 2);
    }
};
