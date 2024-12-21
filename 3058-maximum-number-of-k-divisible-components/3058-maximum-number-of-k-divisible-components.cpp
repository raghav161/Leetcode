class Solution {
public:
    int count=0;
    long long dfs(int i, vector<int>& vis, unordered_map<int, vector<int>>& adj, vector<int>& values, int k) {
        vis[i]=1;
        long long sum=0;
        for(auto& j:adj[i])
        {
            if(vis[j])
                continue;
            sum+=dfs(j, vis, adj, values, k);
        }
        sum+=(long long)values[i];
        if(sum%k==0)
        {
            count++;
            sum=0;
        }
        return sum;
    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int, vector<int>> adj;
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n);
        dfs(0, vis, adj, values, k);
        return count;
    }
};