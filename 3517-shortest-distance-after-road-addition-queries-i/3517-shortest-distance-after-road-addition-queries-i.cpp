class Solution {
public:
    int f(unordered_map<int, vector<int>>& graph, int start, int end, int n) {
        vector<int> dist(n, INT_MAX);
        dist[start] = 0;   
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        while(!pq.empty())
        {
            auto [current_dist, current_node] = pq.top();
            pq.pop();
            if(current_node == end)
                return current_dist;
            if(current_dist > dist[current_node])
                continue;            
            for(auto neighbor:graph.at(current_node))
            {
                if(current_dist + 1 < dist[neighbor])
                {
                    dist[neighbor] = current_dist + 1;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }
        return INT_MAX;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < n - 1; ++i)
            graph[i].push_back(i+1);
        vector<int> answer;
        for(auto& query : queries)
        {
            int u = query[0], v = query[1];
            graph[u].push_back(v);
            answer.push_back(f(graph, 0, n - 1, n));
        }
        return answer;
    }
};