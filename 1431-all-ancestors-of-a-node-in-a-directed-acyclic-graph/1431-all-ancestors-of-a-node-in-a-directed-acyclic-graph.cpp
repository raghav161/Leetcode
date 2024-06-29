class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& gr, vector<int>& vis, int src)
    {
        vis[src]=1;
        for(auto v:gr[src])
        {
            if(vis[v]==0)
                dfs(gr, vis, v);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges)
    {
        unordered_map<int, vector<int>> mp;
        for(auto i:edges)
            mp[i[1]].push_back(i[0]);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {    
            vector<int> vis(n), tmp;
            dfs(mp, vis, i);
            vis[i]=0;
            for(int j=0;j<n;j++)
            {
                if(vis[j])
                    tmp.push_back(j);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};