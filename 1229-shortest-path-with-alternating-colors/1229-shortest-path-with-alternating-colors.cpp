class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<int>> redGraph, blueGraph;
        for(int i=0;i<redEdges.size();i++)
            redGraph[redEdges[i][0]].push_back(redEdges[i][1]);
        for(int i=0;i<blueEdges.size();i++)
            blueGraph[blueEdges[i][0]].push_back(blueEdges[i][1]);
        vector<int> redDist(n, 2*n), blueDist(n, 2*n);
        redDist[0]=blueDist[0]=0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});
        while(!q.empty())
        {
            int x = q.front().first;
            int c = q.front().second;
            q.pop();
            if(c==0)
            {
                for(auto next:blueGraph[x])
                {
                    if(blueDist[next]>redDist[x]+1)
                    {
                        blueDist[next]=redDist[x]+1;
                        q.push({next, 1});
                    }
                }
            }
            else
            {
                for(auto next:redGraph[x])
                {
                    if(redDist[next]>blueDist[x]+1)
                    {
                        redDist[next]=blueDist[x]+1;
                        q.push({next, 0});
                    }
                }
            }
        }
        vector<int> ans(n, -1);
        for(int i=0;i<n;i++)
        {
            int mini=min(redDist[i], blueDist[i]);
            if(mini!=2*n)
                ans[i]=mini;
        }
        return ans;
    }
};