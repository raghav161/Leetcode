class Solution {
public:
    void dfs(vector<vector<int>>& stones, int index, vector<bool>& visited)
    {
        visited[index]=1;
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==0 && (stones[i][0]==stones[index][0] || stones[i][1]==stones[index][1]))
                dfs(stones, i, visited);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<bool> visited(stones.size());
        int count=0;
        for(int i=0;i<stones.size();i++)
        {
            if(visited[i]==0)
            {
                count++;
                dfs(stones, i, visited);
            }
        }
        return stones.size()-count;
    }
};