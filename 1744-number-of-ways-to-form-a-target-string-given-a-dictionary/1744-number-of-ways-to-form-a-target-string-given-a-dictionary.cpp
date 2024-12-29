class Solution {
public:
    const int MOD = 1e9+7;
    int solve(int i, int j, vector<vector<long long>>& freq, string &target, vector<vector<int>>& dp) {
        if (i == target.size())
            return 1;
        if (j == freq[0].size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int not_taken = solve(i, j+1, freq, target, dp)%MOD;
        int taken = (freq[target[i]-'a'][j]*solve(i+1, j+1, freq, target, dp))%MOD;
        return dp[i][j] = (not_taken + taken)%MOD;
    }
    
    int numWays(vector<string>& words, string target) {
        vector<vector<long long>> freq(26, vector<long long>(words[0].size()));
        for(int col=0;col<words[0].size();col++)
        {
            for(auto& word:words)
                freq[word[col]-'a'][col]++;
        }
        vector<vector<int>> dp(target.length()+1, vector<int>(words[0].size()+1, -1));
        return solve(0, 0, freq, target, dp);
    }
};
