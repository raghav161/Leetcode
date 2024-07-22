class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> dir={1, 0, -1, 0, 1};
        set<pair<int, int>> visited;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {entrance[0], entrance[1]}});
        visited.insert({entrance[0], entrance[1]});
        while(!pq.empty())
        {
            auto steps=pq.top().first;
            auto x=pq.top().second.first;
            auto y=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int newx=x+dir[i], newy=y+dir[i+1];
                if(newx>=0 and newx<maze.size() and newy>=0 and newy<maze[0].size() and maze[newx][newy]=='.' and visited.count({newx, newy})==0)
                {
                    if(newx==0 or newy==0 or newx==maze.size()-1 or newy==maze[0].size()-1)
                        return steps+1;
                    pq.push({steps+1, {newx, newy}});
                    visited.insert({newx, newy});
                }
            }
        }
        return -1;
    }
};