class Solution {
public:
    bool bfs(map<int, vector<int>>& mp, int start, int end, int n) {
        vector<bool> visited(n+1);
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            visited[curr] = 1;
            if(curr == end)
                return 1;
            for(auto x:mp[curr])
            {
                if(visited[x]==0)
                    q.push(x);
            }
        }
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int, vector<int>> mp;
        int n = edges.size();
        for(int i=0;i<n;i++) 
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if(mp.find(u) != mp.end() && mp.find(v) != mp.end() && bfs(mp, u, v, n))
                return edges[i];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        return {};
    }
};