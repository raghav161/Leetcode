class Solution {
public:
    
    int f(int idx, int cnt, vector<int>& rating, vector<vector<int>>& dp) {
        if(cnt == 3)
            return 1;
        if(dp[idx][cnt] != -1) 
            return dp[idx][cnt];
        int res = 0;
        for(int i=idx+1; i<rating.size(); ++i) {
            if(rating[i] < rating[idx]) 
                res += f(i, cnt+1, rating, dp);
        }
        return dp[idx][cnt] = res;
    }
    int numTeams(vector<int>& rating) {
        int res = 0;
        vector<vector<int>> dp(rating.size(), vector<int>(3, -1));
        for(int i=0; i<rating.size(); ++i) {
            res += f(i, 1, rating, dp);
        }
        reverse(rating.begin(), rating.end());
        vector<vector<int>> dp2(rating.size(), vector<int>(3, -1));
        for(int i=0; i<rating.size(); ++i) {
            res += f(i, 1, rating, dp2);
        }
        return res;
    }
};