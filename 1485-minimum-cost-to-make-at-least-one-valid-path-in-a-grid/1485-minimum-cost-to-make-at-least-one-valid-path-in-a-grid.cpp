class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        dist[0][0]=0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()) {
            int x1 = q.front().first, y1 = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int wX = x1 + dx[i], wY = y1 + dy[i];
                if (wX >= 0 && wX < grid.size() && wY >= 0 && wY < grid[0].size())
                {
                    if (i + 1 == grid[x1][y1] && dist[x1][y1] < dist[wX][wY]) {
                        dist[wX][wY] = dist[x1][y1];
                        q.push({wX, wY});
                    }
                    else if (dist[x1][y1] + 1 < dist[wX][wY]) {
                        dist[wX][wY] = dist[x1][y1] + 1;
                        q.push({wX, wY});
                    }
                }
            }
        }
        return dist[grid.size()-1][grid[0].size()-1];
    }
};