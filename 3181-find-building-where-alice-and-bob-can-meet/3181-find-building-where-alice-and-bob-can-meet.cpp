class Solution {
public:
    vector<int> a, st;
    void build(int id, int l, int r)
    {
        if (l==r)
        {
            st[id] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(id*2+1, l, mid);
        build(id*2+2, mid+1, r);
        st[id] = max(st[id*2+1], st[id*2+2]);
    }

    int get(int id, int l, int r, int u, int v)
    {
        if (r < u || l > v) 
            return INT_MIN;
        if (l >= u && r <= v) 
            return st[id];
        int mid = (l+r)/2;
        return max(get(id*2+1, l, mid, u, v), get(id*2+2, mid+1, r, u, v));
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) 
    {
        int n = heights.size();
        a = vector<int>(heights.begin(), heights.end());
        st = vector<int>(4*(n+1), 0);
        build(0, 0, n-1);
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int ai = queries[i][0], bi = queries[i][1];
            if (ai == bi || heights[max(ai, bi)] > heights[min(ai, bi)])
            {
                res[i] = max(ai, bi);
                continue;
            }
            int l = max(ai, bi) + 1, r = n;
            while (l < r)
            {
                int mid = (l+r)/2;
                int tmp = get(0, 0, n-1, l, mid);
                if(tmp <= max(heights[ai], heights[bi]))
                    l = mid+1;
                else 
                    r = mid;
            }
            res[i] = (r!=n)?r:-1;
        }
        return res;
    }
};