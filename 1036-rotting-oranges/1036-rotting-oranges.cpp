class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({{i, j}, 0});
                else if(grid[i][j]==1)
                    count++;
            }
        }
        int time=0;
        vector<int> delcol={1, 0, -1, 0, 1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(time, t);
            for(int i=0;i<4;i++)
            {
                int drow=row+delcol[i], dcol=col+delcol[i+1];
                if(drow>=0 && drow<m && dcol>=0 && dcol<n && grid[drow][dcol]==1)
                {
                    q.push({{drow, dcol}, t+1});
                    grid[drow][dcol]=2;
                    count--;
                }
            }
        }
        if(count==0)
            return time;
        return -1;
    }
};