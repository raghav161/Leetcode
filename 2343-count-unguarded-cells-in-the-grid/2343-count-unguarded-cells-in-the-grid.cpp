class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> grid(m, vector<int>(n));
        for (auto i : g)
            grid[i[0]][i[1]] = 3;
        for (auto i : w)
            grid[i[0]][i[1]] = 2;
        for (auto val : g) {
            int row = val[0], col = val[1];
            for (int i = row + 1; i < m; i++) {
                if (grid[i][col] == 2 || grid[i][col] == 3)
                    break;
                grid[i][col] = 1;
            }
            for (int i = row - 1; i >= 0; i--) {
                if (grid[i][col] == 2 || grid[i][col] == 3)
                    break;
                grid[i][col] = 1;
            }
            for (int i = col + 1; i < n; i++) {
                if (grid[row][i] == 2 || grid[row][i] == 3)
                    break;
                grid[row][i] = 1;
            }
            for (int i = col - 1; i >= 0; i--) {
                if (grid[row][i] == 2 || grid[row][i] == 3)
                    break;
                grid[row][i] = 1;
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    count++;
            }
        }
        return count;
    }
};