class Solution {
public:
    vector<int> del={1, 0, -1, 0, 1};
    bool isValid(int x, int y, int n)
    {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    vector<vector<int>> f(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>> distanceGrid(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i, j});
                    distanceGrid[i][j] = 0;
                }
            }
        }
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newX = x + del[i], newY = y + del[i+1];
                if(isValid(newX, newY, n) && distanceGrid[newX][newY] == INT_MAX)
                {
                    distanceGrid[newX][newY] = distanceGrid[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
        return distanceGrid;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid)
    {
        int n=grid.size();
        if(grid[n-1][n-1]==1 || grid[0][0]==1)
            return 0;
        vector<vector<int>> dis=f(grid);
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> vis(n, vector<int>(n));
        pq.push({dis[0][0], {0, 0}});
        vis[0][0]=1;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int mini=it.first, i=it.second.first, j=it.second.second;
            if(i==n-1 && j==n-1)
                return pq.top().first;
            for(int l=0;l<4;l++)
            {
                int nrow=i+del[l], ncol=j+del[l+1];
                if(isValid(nrow, ncol, n) && grid[nrow][ncol]!=1 && vis[nrow][ncol]==0)
                {
                    vis[nrow][ncol]=1;
                    pq.push({min(mini, dis[nrow][ncol]),{nrow, ncol}});
                }
            }
        }
        return 0;
    }
};