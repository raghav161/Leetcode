class Solution {
public:
    long long f(int i, int j, int fl, vector<vector<int>>& grid, vector<vector<vector<long long>>>& dp)
    {
        int m=grid[0].size();
        if(m==1 or j>=m)
            return 0;
        if(dp[i+1][j][fl] != -1)
            return dp[i+1][j][fl];
        long long ans = f(grid.size()-1, j+1, 0, grid, dp);
        long long sum = 0;
        if(j==0)
        {
            for(int ind=0;ind<grid.size();ind++)
            {
                sum += grid[ind][j];
                ans = max(ans, sum + f(ind, j+1, 1, grid, dp));
            }
        } 
        else if(j<m-1)
        {
            if(fl==0)
            {
                for(int ind=i;ind>=0;ind--)
                {
                    sum += grid[ind][j];
                    ans = max(ans, sum + f(ind-1, j+1, 0, grid, dp));
                }
            } 
            for(int ind=i+1;ind<grid.size();ind++)
            {
                sum += grid[ind][j];
                ans = max(ans, sum + f(ind, j+1, 1, grid, dp));
            }
        } 
        else if(j==m-1)
        {
            if(fl==0)
            {
                for(int ind=0;ind<=i;ind++)
                    ans += grid[ind][m-1];
            }
        }
        return dp[i+1][j][fl] = ans;
    }
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(m, vector<long long>(2, -1)));
        return f(-1, 0, 0, grid, dp);
    }
};