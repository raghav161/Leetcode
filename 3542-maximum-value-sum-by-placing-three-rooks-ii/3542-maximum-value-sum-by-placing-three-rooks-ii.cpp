class Solution {
public:
    long long inf = -1e18;
    long long dp[502][502];
    long long solve(int idx, int col1, int col2, vector<vector<pair<long long, int>>>& mat){
        if(idx>=mat.size())
            return inf;
        if(dp[idx][col2+1]!=-1)
            return dp[idx][col2+1];
        long long ans=solve(idx+1, col1, col2, mat);
        for(int i=0;i<3;i++)
        {
            if(mat[idx][i].second!=col1 and mat[idx][i].second!=col2)
            {
                if(col2==-1)
                    ans=max(ans, mat[idx][i].first+solve(idx+1, col1, mat[idx][i].second, mat));
                else
                    ans=max(ans, mat[idx][i].first);
            }
        } 
        return dp[idx][col2+1]=ans;
    }
    long long maximumValueSum(vector<vector<int>>& board){
        int n = board.size(), m = board[0].size();
        vector<vector<pair<long long, int>>> mat(n);
        for(int i=0; i<n; i++)
        {
            vector<pair<int, int>> vp;
            for(int j=0; j<m; j++)
                vp.push_back({board[i][j], j});
            sort(vp.rbegin(), vp.rend());
            for(int j=0; j<3; j++)
                mat[i].push_back(vp[j]);
        }
        sort(mat.rbegin(), mat.rend());
        long long ans=-1e18;
        for(int i=0;i<3;i++)
        {
            memset(dp, -1, sizeof(dp));
            ans=max(ans, mat[0][i].first + solve(1, mat[0][i].second, -1, mat));
        }
        return ans;
    }
};