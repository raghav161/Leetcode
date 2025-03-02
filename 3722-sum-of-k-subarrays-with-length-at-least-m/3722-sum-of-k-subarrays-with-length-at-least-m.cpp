class Solution {
public:
    int solve(int i, int k, int m, int started, vector<int>& arr, vector<vector<vector<int>>>& dp) {
        if (k == 0)
            return 0;
        if (i >= arr.size()) {
            if (k == 1 && started == 1)
                return 0;
            return -1000000000;
        }
        if (dp[started][k][i] != -1)
            return dp[started][k][i];
        
        int a = -1000000000, b = -1000000000, c = -1000000000, d = -1000000000, e = -1000000000;
        if (started == 1) {
            a = arr[i] + solve(i + 1, k, m, 1, arr, dp);
            b = solve(i + 1, k - 1, m, 0, arr, dp);
            if (i + m - 1 < arr.size()) {
                int sum = 0;
                for (int j = i; j < i + m; j++)
                    sum += arr[j];
                c = sum + solve(i + m, k - 1, m, 1, arr, dp);
            }
        } else {
            if (i + m - 1 < arr.size()) {
                int sum = 0;
                for (int j = i; j < i + m; j++)
                    sum += arr[j];
                d = sum + solve(i + m, k, m, 1, arr, dp);
            }
            e = solve(i + 1, k, m, started, arr, dp);
        }
        return dp[started][k][i] = max({a, b, c, d, e});
    }
    int maxSum(vector<int>& nums, int k, int m) {
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(k + 1, vector<int>(nums.size(), -1)));
        return solve(0, k, m, 0, nums, dp);
    }
};
