class Solution {
public:
    int f(vector<vector<int>>& matrix, int currRow, int currCol, vector<vector<int>>& dp){
        int m = matrix.size(), n = matrix[0].size();
        if(currRow < 0 || currRow >= m || currCol<0 || currCol>=n || matrix[currRow][currCol]==0)
            return 0;
        if(dp[currRow][currCol] != -1)
            return dp[currRow][currCol];
        int right = f(matrix, currRow, currCol+1, dp);
        int down = f(matrix, currRow+1, currCol, dp);
        int rightdown = f(matrix, currRow+1, currCol+1, dp);
        return dp[currRow][currCol] = 1 + min({right, down, rightdown}); 
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m+1 , vector<int>(n+1, -1));
        for(int row=0; row<m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(matrix[row][col])
                    ans += f(matrix, row, col, dp);
            }
        } 
        return ans;
    }
};