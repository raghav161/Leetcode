class Solution {
public:
    int f(int i, int j, string& source, string& pattern, vector<bool>& vec, vector<vector<int>>& dp) {
        if(j==pattern.length())
            return 0;
        if(i==source.length())
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int take=INT_MAX;
        if(source[i]==pattern[j])
        {
            int ans11=vec[i]>0, ans22=f(i+1, j+1, source, pattern, vec, dp);
            if(ans22!=INT_MAX)
                take=ans11+ans22;
        }
        int nottake=f(i+1, j, source, pattern, vec, dp);
        return dp[i][j]=min(nottake, take);
    }

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        vector<vector<int>> dp(source.length()+1, vector<int>(pattern.length()+1, -1));
        vector<bool> vec(source.length());
        for(auto i:targetIndices)
            vec[i]=1;
        int ans=f(0, 0, source, pattern, vec, dp);
        return ans==INT_MAX?0:targetIndices.size()-ans;
    }
};
