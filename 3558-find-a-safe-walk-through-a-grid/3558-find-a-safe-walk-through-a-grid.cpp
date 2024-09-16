class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));
        visited[0][0] = health - grid[0][0];
        q.push({{0, 0}, health - grid[0][0]});
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            int x = current.first.first;
            int y = current.first.second;
            int currentHealth = current.second;
            if (x == grid.size() - 1 && y == grid[0].size() - 1 && currentHealth >= 1)
                return true;
            for (int i = 0; i < 4; i++) {
                int newX = x + dir[i];
                int newY = y + dir[i+1];
                if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size()) {
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