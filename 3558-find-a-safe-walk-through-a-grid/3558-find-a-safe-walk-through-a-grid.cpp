class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = health - grid[0][0];
        q.push({{0, 0}, health - grid[0][0]});
        
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            
            int x = current.first.first;
            int y = current.first.second;
            int currentHealth = current.second;
            if (x == m - 1 && y == n - 1 && currentHealth >= 1)
                return true;
            for (int i = 0; i < 4; i++) {
                int newX = x + directions[i][0];
                int newY = y + directions[i][1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                    int newHealth = currentHealth - grid[newX][newY];
                    if (newHealth >= 1 and newHealth > visited[newX][newY]) {
                        q.push({{newX, newY}, newHealth});
                        visited[newX][newY] = newHealth;
                    }
                }
            }
        }
        return false;
    }
};