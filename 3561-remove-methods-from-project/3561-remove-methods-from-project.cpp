class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n), rev(n);
        for(auto inv:invocations)
        {
            int u=inv[0], v=inv[1];
            adj[u].push_back(v);
            rev[v].push_back(u);
        }
        vector<bool> sus(n);
        stack<int> st;
        sus[k]=1;
        st.push(k);
        while(!st.empty()) {
            int u = st.top(); st.pop();
            for(int v : adj[u]) {
                if(!sus[v]) {
                    sus[v]=1;
                    st.push(v);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(sus[i])
            {
                for(auto u:rev[i])
                {
                    if(!sus[u])
                    {
                        vector<int> ans(n);
                        iota(ans.begin(), ans.end(), 0);
                        return ans;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(!sus[i])
                ans.push_back(i);
        }
        return ans;
    }
};
