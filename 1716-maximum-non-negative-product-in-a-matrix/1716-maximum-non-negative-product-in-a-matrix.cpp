class Solution {
public:
    int MOD = 1e9 + 7;
    void f(vector<vector<int>>& grid, long long& maxi, long long prod, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        if(grid[x][y] == 0)
        {
            maxi = max(maxi, 0LL);
            return;
        }
        prod *= grid[x][y];
        if(x==m - 1 && y==n - 1)
        {
            maxi = max(maxi, prod);        
            return;
        }
        if(x + 1 < m)
            f(grid, maxi, prod, x + 1, y);
        if(y + 1 < n)
            f(grid, maxi, prod, x, y + 1);
    }

    int maxProductPath(vector<vector<int>>& grid) {
        long long maxi = -1;
        f(grid, maxi, 1, 0, 0);
        return maxi%MOD;
    }
};