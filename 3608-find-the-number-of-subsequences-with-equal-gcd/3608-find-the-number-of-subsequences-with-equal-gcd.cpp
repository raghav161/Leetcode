class Solution {
public:
    int dp[200][201][201];
    const int mod = 1e9 + 7;
    int f(int i, vector<int>& nums, int first, int second){
        if(i==nums.size())
            return (first and second) and (first == second);
        if(dp[i][first][second] != -1)
            return dp[i][first][second];
        int skip = f(i+1, nums, first, second);
        int takefirst = f(i+1, nums, __gcd(first, nums[i]), second);
        int takesecond = f(i+1, nums, first, __gcd(second, nums[i]));
        return dp[i][first][second] = (0LL + skip + takefirst + takesecond)%mod;
    }
    
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return f(0, nums, 0, 0);
    }
};