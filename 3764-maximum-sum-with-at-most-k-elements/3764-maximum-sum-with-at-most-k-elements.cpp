class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<pair<int, int>> pq;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                pq.push({grid[i][j], i});
        }
        long long ans = 0;
        while (!pq.empty()) {
            if (k == 0)
                break;
            if (limits[pq.top().second] > 0) {
                ans += pq.top().first;
                limits[pq.top().second]--;
                k--;
            }
            pq.pop();
        }
        return ans;
    }
};