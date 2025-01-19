class Solution {
public:
    vector<vector<vector<long long>>> dp;
    long long solve(int i, int p1, int p2, int &n, vector<vector<int>>& cost){
        if(i >= n/2)
            return 0ll;
        if(dp[i][p1+1][p2+1] != -1)
            return dp[i][p1+1][p2+1];
        long long ans = LONG_MAX;
        for(int c1 = 0; c1 < 3; c1++){
            for(int c2 = 0; c2 < 3; c2++){
                if(c1 == c2)
                    continue;
                if(c1 == p1 || c2 == p2)
                    continue;
                long long temp = (long long)cost[i][c1] + (long long)cost[n-1-i][c2] + solve(i+1, c1, c2, n, cost);
                ans = min(ans, temp);
            }
        }
        return dp[i][p1+1][p2+1] = ans;
    }
    long long minCost(int n, vector<vector<int>>& cost) {
        dp.resize(n, vector<vector<long long>>(4,vector<long long>(4,-1)));
        return solve(0, -1, -1, n, cost);
    }
};