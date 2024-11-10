class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(heightMap.size(), vector<int>(heightMap[0].size()));
        vector<int> d={1, 0, -1, 0, 1};
        for(int i=0;i<heightMap.size();i++)
        {
            for(int j=0;j<heightMap[0].size();j++)
            {
                if(i==0 or i==heightMap.size()-1 or j==0 or j==heightMap[0].size()-1)
                {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j]=1;
                }
            }
        }
        int sum=0, maxi=INT_MIN;
        while(!pq.empty()) {
            int h=pq.top()[0], x=pq.top()[1], y=pq.top()[2];
            pq.pop();
            maxi=max(h, maxi);
            sum+=maxi-h;
            for(int k=0;k<4;k++)
            {
                int i=x+d[k], j=y+d[k+1];
                if(i>=0 and i<heightMap.size() and j>=0 and j<heightMap[0].size() and visited[i][j]==0)
                {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j]=1;
                }
            }
        }
        return sum;
    }
};