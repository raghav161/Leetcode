class NeighborSum {
public:
    vector<vector<int>> grid;
    int n;
    bool isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    unordered_map<int, pair<int, int>> mp;
    NeighborSum(vector<vector<int>>& g) {
        grid=g;
        n=grid.size();
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[0].size();j++)
                mp[g[i][j]] = {i, j};
        }
    }
    
    int adjacentSum(int value) {
        auto cord=mp[value];
        int x=cord.first, y=cord.second, sum=0;
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(auto& dir : directions)
        {
            int nx = x + dir[0], ny = y + dir[1];
            if(isValid(nx, ny))
                sum += grid[nx][ny];
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        auto cord=mp[value];
        int x=cord.first, y=cord.second, sum=0;
        int diagonals[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        for(auto& dir : diagonals)
        {
            int nx = x + dir[0], ny = y + dir[1];
            if(isValid(nx, ny))
                sum += grid[nx][ny];
        }
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */