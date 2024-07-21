class Solution {
public:
    vector<int> f(vector<vector<int>> &A, int k) {
        vector<int> deg(k), order;
        unordered_map<int, vector<int>> graph;
        queue<int> q;
        for (auto &c: A) {
            graph[c[0] - 1].push_back(c[1] - 1);
            deg[c[1] - 1]++;
        }
        for(int i = 0; i < k; i++) 
            if (!deg[i]) q.push(i);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            order.push_back(x + 1);
            for (int& y: graph[x]) 
                if (--deg[y] == 0) 
                    q.push(y);
        }
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> order1 = f(rowConditions, k);
        vector<int> order2 = f(colConditions, k);
        if (order1.size() < k || order2.size() < k)
            return {};
        
        vector<vector<int>> ans(k, vector<int>(k));
        for (int i = 0; i < k; i++)
        {
            for(int j=0;j<k;j++)
            {
                if(order1[i]==order2[j])
                    ans[i][j]=order1[i];
            }
        }
        return ans;
    }
};