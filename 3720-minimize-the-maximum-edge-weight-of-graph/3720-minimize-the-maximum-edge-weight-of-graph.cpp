class Solution {
public:
    int dfs(int i, int m, vector<vector<pair<int, int>>>& vec, vector<int>& vis) {
        int ans = vis[i] = 1;
        for(auto [j, w]:vec[i])
            if(w<=m and vis[j]==0)
                ans += dfs(j, m, vec, vis);
        return ans;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold ) {
        vector<vector<pair<int, int>>> vec(n);
        for(auto& e:edges)
            vec[e[1]].push_back({e[0], e[2]});
        int l = 1, r = 1000001;
        while (l < r) {
            int m = (l + r) / 2;
            if (vector<int> vis(n); dfs(0, m, vec, vis) == n)
                r = m;
            else
                l = m + 1;
        }
        return l == 1000001 ? -1 : l;
    }
};