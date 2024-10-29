class Solution {
    public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        int n=grid.size(), m=grid[0].size();
        if(dp[i][j]!=-1)
            return dp[i][j];    
        int a=0, b=0, c=0;
        if(i-1>=0 && j+1<m && grid[i][j] < grid[i-1][j+1])
            a = 1 + dfs(i-1, j+1, grid, dp);
        if(j+1<m && grid[i][j] < grid[i][j+1])
            b = 1 + dfs(i, j+1, grid, dp);
        if(i+1<n && j+1<m && grid[i][j] < grid[i+1][j+1])
            c = 1 + dfs(i+1, j+1, grid, dp);
        return dp[i][j] = max({a, b, c});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0;i<n;i++)
            ans = max(ans, dfs(i, 0, grid, dp));
        return ans;
    }
};