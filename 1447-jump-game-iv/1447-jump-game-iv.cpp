class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]].push_back(i);
        queue<pair<int, int>> q;
        vector<bool> vis(arr.size());
        q.push({0, 0});
        while(!q.empty())
        {
            int index=q.front().first, steps=q.front().second;
            q.pop();
            if(index==arr.size()-1)
                return steps;
            if(index+1 < arr.size() and vis[index+1]==0)
            {
                vis[index+1] = 1;
                q.push({index+1, steps+1});
            }
            if(index-1 >= 0 && vis[index-1]==0)
            {
                vis[index-1] = 1;
                q.push({index-1, steps+1});
            }
            for(auto newIdx:mp[arr[index]])
            {
                if(vis[newIdx]==0) 
                {
                    vis[newIdx]=1;
                    q.push({newIdx, steps+1});
                }
            }
            mp.erase(arr[index]);
        }
        return -1;
    }
};