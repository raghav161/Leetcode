class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int count=0;
        unordered_map<int, unordered_map<int, int>> mp;
        for(int i=0;i<pick.size();i++)
        {
            mp[pick[i][0]][pick[i][1]]++;
        }
        for(auto i:mp)
        {
            int player=i.first;
            for(auto j:i.second)
            {
                if(j.second>=player+1)
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};