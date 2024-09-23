class Solution {
public:
    unordered_map<int, int> mp;
    vector<vector<int>> dp;
    int f(int index, int inv)
    {
        if(index<=0)
            return inv==0;
        if(dp[index][inv]!=-1)
            return dp[index][inv];
        int ans=0;
        for(int i=0;i<=min(index, inv);i++)
        {
            if(mp.count(index) and mp[index]!=inv)
                continue;
            ans=(ans+f(index-1, inv-i))%1000000007;
        }
        return dp[index][inv]=ans;
    }

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        for(auto& r:requirements)
            mp[r[0]]=r[1];
        dp.assign(n, vector<int>(401, -1));
        if(mp[0]!=0)
            return 0;
        return f(n-1, mp[n-1]);
    }
};