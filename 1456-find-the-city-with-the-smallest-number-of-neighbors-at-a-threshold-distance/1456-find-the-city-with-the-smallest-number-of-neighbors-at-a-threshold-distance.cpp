class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n, vector<int>(n, 1e9));
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]][edges[i][1]] = edges[i][2];
            graph[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int i=0;i<n;i++)
            graph[i][i] = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                    graph[j][k] = min(graph[j][k], graph[j][i]+graph[i][k]);
            }
        }
        int maxi = n + 1, city = -1;
        for(int i=0;i<n;i++)
        {
            int count = 0;
            for(int j=0;j<n;j++)
            {
                if(graph[i][j]<=distanceThreshold)
                    count++;
            }
            if(count<=maxi)
            {
                maxi = count;
                city = i;
            }
        }
        return city;
    }
};