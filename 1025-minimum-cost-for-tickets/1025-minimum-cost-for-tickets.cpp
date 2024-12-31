class Solution {
public:
    int solve(vector<int>& days, vector<int>& cost, int index, vector<int>& dp)
    {
        int n=days.size();
        if(index>=n)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int cost_1 = cost[0] + solve(days, cost, index+1, dp);
        int i = index;
        while(i < n && days[i] < days[index]+7)
            i++;
        int cost_7 = cost[1] + solve(days, cost, i, dp);
        int j = index;
        while(j < n && days[j] < days[index]+30)
            j++;
        int cost_30 = cost[2] + solve(days, cost, j, dp);
        return dp[index]=min({cost_1, cost_7, cost_30});
    }
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        vector<int> dp(days.size()+1, -1);
        return solve(days, cost, 0, dp);
    }
};