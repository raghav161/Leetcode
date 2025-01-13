class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> result;
        bool even = true;
        int temp = grid[0].size()%2;
        for (int i = 0; i < grid.size(); ++i) {
            if (even) {
                for (int j = 0; j < grid[i].size(); j += 2)
                    result.push_back(grid[i][j]);
            } else {
                for (int j = grid[i].size() - temp - 1; j >= 0; j -= 2)
                    result.push_back(grid[i][j]);
            }
            even = !even;
        }
        return result;
    }
};