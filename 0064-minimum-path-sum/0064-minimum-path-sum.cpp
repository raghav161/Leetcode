class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        vector<int> directions = {1, 0, 1};
        dp[0][0] = grid[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int x = curr.second.first;
            int y = curr.second.second;
            int cost = curr.first;
            for(int i=0;i<2;i++)
            {
                int newX = x + directions[i];
                int newY = y + directions[i+1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && dp[newX][newY] > cost + grid[newX][newY])
                {
                    dp[newX][newY] = cost + grid[newX][newY];
                    pq.push({dp[newX][newY], {newX, newY}});
                }
            }
        }
        return dp[n-1][m-1];
    }
};