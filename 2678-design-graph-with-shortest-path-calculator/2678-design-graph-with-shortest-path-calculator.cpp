class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> adj;
    int N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            adj[u].push_back({v, cost});
        }
    }

    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];
        adj[u].push_back({v, cost});
    }

    int shortestPath(int node1, int node2) {
        vector<int> res(N, INT_MAX);
        res[node1] = 0;
        pq.push({0, node1});
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto& v : adj[node]) {
                int adjnode = v.first;
                int dis = v.second;
                if (dis + d < res[adjnode]) {
                    res[adjnode] = d + dis;
                    pq.push({d + dis, adjnode});
                }
            }
        }
        return res[node2] == INT_MAX ? -1 : res[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */