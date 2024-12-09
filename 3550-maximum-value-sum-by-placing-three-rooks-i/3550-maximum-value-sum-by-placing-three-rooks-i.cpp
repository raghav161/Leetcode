class Solution {
public:
    long long inf = -1e18;
    long long dp[101][102][102];
    long long solve(int idx, int col1, int col2, vector<vector<pair<int, int>>>& mat){
        if(idx==mat.size())
            return inf;
        if(dp[idx][col1+1][col2+1]!=-1)
            return dp[idx][col1+1][col2+1];
        long long ans = solve(idx+1, col1, col2, mat);
        for(int i=0;i<3;i++)
        {
            int curr_col = mat[idx][i].second;
            long long tmp;
            if(col1==-1)
                tmp = solve(idx+1, curr_col, col2, mat) + mat[idx][i].first;
            else if(col2==-1)
            {
                if(col1==curr_col)
                    continue;
                tmp = solve(idx+1, col1, curr_col, mat) + mat[idx][i].first;
            }
            else
            {
                if(col1==curr_col || col2==curr_col)
                    continue;
                tmp = mat[idx][i].first;
            }
            ans = max(ans, tmp);
        } 
        return dp[idx][col1+1][col2+1] = ans;
    }
    long long maximumValueSum(vector<vector<int>>& board){
        int n = board.size(), m = board[0].size();
        vector<vector<pair<int, int>>> mat(n);
        for(int i=0; i<n; i++)
        {
            vector<pair<int, int>> vp;
            for(int j=0; j<m; j++)
                vp.push_back({board[i][j], j});
            sort(vp.rbegin(), vp.rend());
            for(int j=0; j<3; j++)
                mat[i].push_back(vp[j]);
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, -1, mat);
    }
};