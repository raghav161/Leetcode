class Solution {
public:
    bool isBipartite(unordered_map<int, vector<int>>& adj, int curr, vector<int>& colors, int currColor) {
        colors[curr] = currColor;
        for(int &ngbr : adj[curr]) {
            if(colors[ngbr] == colors[curr])
                return 0;
            if(colors[ngbr] == -1) {
                if(!isBipartite(adj, ngbr, colors, 1 - currColor))
                    return 0;
            }
        }
        return 1;
    }

    int bfs(unordered_map<int, vector<int>> &adj, int currNode, int n) {
        queue<pair<int, int>> que;
        vector<bool> visited(n);
        que.push({currNode, 1});
        visited[currNode] = 1;
        int ans=0;
        while(!que.empty()) {
            auto curr = que.front();
            ans=curr.second;
            que.pop();
            for(int &ngbr : adj[curr.first]) {
                if(visited[ngbr])
                    continue;
                que.push({ngbr, curr.second+1});
                visited[ngbr] = 1;
            }
        }
        return ans;
    }

    int getMaxFromEachComp(unordered_map<int, vector<int>>& adj, int curr, vector<bool>& visited, vector<int>& levels) {
        int maxGrp = levels[curr];
        visited[curr] = 1;
        for(int &ngbr : adj[curr]) {
            if(!visited[ngbr])
                maxGrp = max(maxGrp, getMaxFromEachComp(adj, ngbr, visited, levels));
        }
        return maxGrp;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> colors(n, -1);
        for(int node = 0; node < n; node++) {
            if(colors[node] == -1) {
                if(!isBipartite(adj, node, colors, 1))
                    return -1;
            }
        }
        vector<int> levels(n);
        for(int node = 0; node < n; node++)
            levels[node] = bfs(adj, node, n);
        int maxGroupEachComp = 0;
        vector<bool> visited(n);
        for(int node = 0; node < n; node++) {
            if(!visited[node])
                maxGroupEachComp += getMaxFromEachComp(adj, node, visited, levels);
        }
        return maxGroupEachComp;
    }
};