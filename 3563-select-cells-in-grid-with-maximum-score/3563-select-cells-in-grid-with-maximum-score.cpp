class Solution {
public:
    int f(vector<vector<int>>& values, int idx, int mask_row, unordered_map<string, int>& dp)
    {
        if(idx==values.size())
            return 0;
        string key=to_string(idx)+"_"+to_string(mask_row);
        if(dp.count(key))
            return dp[key];
        int nottake = f(values, idx+1, mask_row, dp), take=0;
        int row = values[idx][1];
        if(((1<<row) & mask_row)==0)
        {
            int j = idx;
            while(j<values.size() and values[idx][0]==values[j][0])
                j++;
            take = values[idx][0] + f(values, j, mask_row | (1<<row), dp);
        }
        return dp[key] = max(nottake, take);
    }
    int maxScore(vector<vector<int>>& grid) {
        vector<vector<int>> values;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
                values.push_back({grid[i][j], i, j});
        }
        sort(values.begin(), values.end());
        unordered_map<string, int> dp;
        return f(values, 0, 0, dp);
    }
};