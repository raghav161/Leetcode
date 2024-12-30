class Solution {
public:
    vector<int> dir={1, 0, -1, 0, 1};
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty()) {
            int time = pq.top().first, row  = pq.top().second.first, col  = pq.top().second.second;
            pq.pop();
            if (row == grid.size() - 1 && col == grid[0].size() - 1)
                return time;
            if (visited[row][col]) 
                continue;
            visited[row][col] = 1;
            for(int i=0;i<4;i++)
            {
                int r = row + dir[i];
                int c = col + dir[i+1];
                if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || visited[r][c])
                    continue;
                if (grid[r][c] <= time+1)
                    pq.push({time+1, {r, c}});
                else
                    pq.push({grid[r][c]+((grid[r][c]-time)%2==0), {r, c}});
            }
        }
        return -1;
    }
};