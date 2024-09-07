class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int j=0;j<grid[0].size();j++)
            pq.push({grid[0][j], 0, j});
        while(!pq.empty())
        {
            int ans=pq.top()[0], x=pq.top()[1], y=pq.top()[2];
            pq.pop();
            if(x==grid.size()-1)
                return ans;
            for(int dy=0;x+1<grid.size() and dy<grid[0].size();dy++)
            {
                if(ans+moveCost[grid[x][y]][dy]+grid[x+1][dy]<vis[x+1][dy])
                {
                    vis[x+1][dy]=ans+moveCost[grid[x][y]][dy]+grid[x+1][dy];
                    pq.push({vis[x+1][dy], x+1, dy});
                }
            }
        }
        return -1;
    }
};