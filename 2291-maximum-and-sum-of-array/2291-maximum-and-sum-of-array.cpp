class Solution {
public:
    int f(vector<int>& ar, int cur, int n, int k, vector<int>& vis, map<vector<int>, int>& mp)
    {
        if(cur >= n) 
            return 0;
        if(mp.count(vis)) 
            return mp[vis];
        int mx = -1;
        for(int i = 1; i <= k; i++)
        {
            if(vis[i] < 2)
            {
                vis[i]++;
                int res = (i & ar[cur]) + f(ar, cur+1, n, k, vis, mp);
                mx = max(mx, res);
                vis[i]--;
            }
        }
        return mp[vis] = mx;
    }
    int maximumANDSum(vector<int>& ar, int k) {
        int n = ar.size();
        map<vector<int>, int> mp;
        vector<int> vis(k+1);
        return f(ar, 0, n, k, vis, mp);
    }
};
