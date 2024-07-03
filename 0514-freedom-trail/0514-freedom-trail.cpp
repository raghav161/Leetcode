class Solution {
public:
    unordered_map<char, vector<int>> mp;
    int f(int i, string& key, string& ring, int j, vector<vector<int>>& dp)
    {
        if(i>=key.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = INT_MAX;
        for(auto ind:mp[key[i]])
        {
            int left = abs(ind-j), right = ring.size()-left;
            ans = min(ans, min(left, right) + f(i+1, key, ring, ind, dp));
        }
        return dp[i][j] = ans+1;
    }
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> dp(key.size()+1, vector<int>(ring.size()+1, -1));
        for(int i=0;i<ring.size();i++)
            mp[ring[i]].push_back(i);
        return f(0, key, ring, 0, dp);
    }
};