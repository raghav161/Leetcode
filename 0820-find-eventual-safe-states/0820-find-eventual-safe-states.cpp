class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj1) {
        int V = adj1.size();
        vector<int> ans, adj[V], outdeg(V);
        for(int i=0;i<V;i++)
        {
            for(auto val:adj1[i])
            {
                adj[val].push_back(i);
                outdeg[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(outdeg[i] == 0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto val:adj[node])
            {
                outdeg[val]--;
                if(outdeg[val]==0)
                    q.push(val);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};