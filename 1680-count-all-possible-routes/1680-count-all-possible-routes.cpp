class Solution {
public:
    const int MOD = 1000000007;
    int helper(vector<int>& locations, int city, int finish, int remainFuel, vector<vector<int>>& dp) {
        if (remainFuel < 0)
            return 0;
        if (dp[city][remainFuel] != -1)
            return dp[city][remainFuel];
        int total = 0;
        if (city == finish)
            total = 1;
        for (int i = 0; i < locations.size(); i++)
        {
            if (i != city)
            {
                int diff = remainFuel - abs(locations[i] - locations[city]);
                total = (total + helper(locations, i, finish, diff, dp)) % MOD;
            }
        }
        return dp[city][remainFuel] = total;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel+1, -1));
        return helper(locations, start, finish, fuel, dp);
    }
};