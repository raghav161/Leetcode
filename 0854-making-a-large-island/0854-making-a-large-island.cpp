class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int index) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid.size() || grid[i][j] != 1)
            return 0;
        grid[i][j] = index;
        return 1 + dfs(grid, i + 1, j, index) + dfs(grid, i - 1, j, index) + dfs(grid, i, j + 1, index) + dfs(grid, i, j - 1, index);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0, index = 2;
        map<int, int> area;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j]) {
                    area[index] = dfs(grid, i, j, index);
                    ans = max(ans, area[index++]);
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> s;
                    if (i > 0)
                        s.insert(grid[i - 1][j]);
                    if (j > 0)
                        s.insert(grid[i][j - 1]);
                    if (i < grid.size() - 1)
                        s.insert(grid[i + 1][j]);
                    if (j < grid.size() - 1)
                        s.insert(grid[i][j + 1]);
                    int count = 1;
                    for (auto i : s)
                        count += area[i];
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};