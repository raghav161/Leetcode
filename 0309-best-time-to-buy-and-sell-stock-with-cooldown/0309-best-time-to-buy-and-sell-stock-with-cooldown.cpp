class Solution {
public:
    int find(int ind, vector<int>& v, bool buy, vector<vector<int>>& dp){    
        if(ind>=v.size())
            return 0;
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        if(buy)
            return dp[ind][buy]=max(find(ind+1, v, 0, dp)-v[ind], find(ind+1, v, 1, dp));
        return dp[ind][buy]=max(v[ind]+find(ind+2, v, 1, dp), find(ind+1, v, 0, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2)
            return 0;
        vector<vector<int>> v(n+1, vector<int>(2, -1));
        return find(0, prices, 1, v);
    }
};