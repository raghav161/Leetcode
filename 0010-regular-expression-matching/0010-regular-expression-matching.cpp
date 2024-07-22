class Solution {
public:
    bool f(int i, string& s, int j, string &p, vector<vector<int>> &dp) 
    {
        int m = p.size(), n = s.size();
        if(j==m) 
        {
            dp[i][j]=0;
            if(i==n) 
                dp[i][j]=1;			
            return dp[i][j];
        }
        if(dp[i][j] != -1) 
            return dp[i][j];
        if(p[j+1]=='*') 
        {
            if(f(i, s, j+2, p, dp) || i<n && (p[j]=='.' || s[i]==p[j]) && f(i+1, s, j, p, dp))
                return dp[i][j] = 1;
        }
        else if(i<n && (p[j]=='.' || s[i] == p[j]) && f(i+1, s, j+1, p, dp)) 
            return dp[i][j] = 1;
        return dp[i][j]=0;
    }
    bool isMatch(string s, string p) 
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return f(0, s, 0, p, dp);
    }
};