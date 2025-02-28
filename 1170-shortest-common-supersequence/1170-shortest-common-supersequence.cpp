class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
        int m = X.length(), n = Y.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 or j==0)
                    dp[i][j] = i + j;
                else if(X[i-1] == Y[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        string str;
        int i = m, j = n;
        while(i > 0 && j > 0)
        {
            if(X[i - 1] == Y[j - 1])
            {
                str.push_back(X[i - 1]);
                i--;
                j--;
            }
            else if(dp[i - 1][j] > dp[i][j - 1])
            {
                str.push_back(Y[j - 1]);
                j--;
            }
            else
            {
                str.push_back(X[i - 1]);
                i--;
            }
        }
        while(i > 0)
        {
            str.push_back(X[i - 1]);
            i--;
        }
        while(j > 0)
        {
            str.push_back(Y[j - 1]);
            j--;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};