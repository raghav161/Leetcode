class Solution {
public:
    int f(vector<int>& arr, vector<vector<int>>& dp, int i, int j, unordered_map<int, int>& mp)
    {
        if(mp.find(arr[i]+arr[j])==mp.end())
            return 0;
        if(dp[i][j])
            return dp[i][j];
        return dp[i][j]=1+f(arr, dp, j, mp[arr[i]+arr[j]], mp);
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]=i;
        int maxi=0;
        vector<vector<int>> dp(arr.size()+1, vector<int>(arr.size()+1));
        for(int i=0;i<arr.size()-2;i++)
        {
            for(int j=i+1;j<arr.size()-1;j++)
            {
                if(mp.find(arr[i]+arr[j])!=mp.end())
                    maxi=max(maxi, f(arr, dp, i, j, mp)+2);
            }
        }
        if(maxi==2)
            return 0;
        return maxi;
    }
};