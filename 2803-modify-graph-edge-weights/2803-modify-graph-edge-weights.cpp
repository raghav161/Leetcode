class Solution {
public:
    long long f(vector<vector<int>>& edges, int n, int src, int dest)
    {
        unordered_map<long long, vector<pair<long long, long long>>> adj;
        for(auto& edge:edges)
        {
            if(edge[2]!=-1)
            {
                int u = edge[0], v = edge[1], wt = edge[2];
                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
        vector<long long> result(n, INT_MAX);
        vector<bool> visited(n);
        result[src] = 0;
        pq.push({0, src});
        while(!pq.empty())
        {
            long long currDist = pq.top().first, currNode = pq.top().second;
            pq.pop();
            if(visited[currNode])
                continue;
            visited[currNode] = 1;
            for(auto& [nbr, wt]:adj[currNode])
            {
                if(result[nbr] > currDist + wt)
                {
                    result[nbr] = currDist + wt;
                    pq.push({result[nbr], nbr});
                }
            }
        }
        return result[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        long long currShortestDist = f(edges, n, source, destination);
        if(currShortestDist < target)
            return {};
        bool matchedTarget = (currShortestDist == target);
        for(vector<int>& edge : edges)
        {
            if(edge[2] == -1)
            {
                edge[2] = (matchedTarget) ? 2e9 : 1;
                if(!matchedTarget)
                {
                    long long newShortestDist = f(edges, n, source, destination);
                    if(newShortestDist <= target)
                    {
                        matchedTarget = 1;
                        edge[2] += (target - newShortestDist);
                    }
                }
            }
        }
        if(!matchedTarget)
            return {};
        return edges;
    }
};