class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(), n=isWater[0].size();
        vector<int> dirs={0, -1, 0, 1, 0};
        queue<vector<int>> q;
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isWater[i][j])
                    q.push({0, i, j});
            }
        }
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            ans[p[1]][p[2]]=p[0];
            for(int k=1;k<5;k++)
            {
                int i=p[1]+dirs[k-1], j=p[2]+dirs[k];
                if(i>=0 and j>=0 and i<m and j<n and isWater[i][j]==0)
                {
                    q.push({p[0]+1, i, j});
                    isWater[i][j]=1;
                }
            }
        }
        return ans;
    }
};