class Solution {
public:
    bool carPooling(vector<vector<int>>& intervals, int capacity) {
        map<int, int> mp;
        for(int i=0;i<intervals.size();i++)
        {
            mp[intervals[i][1]]+=intervals[i][0];
            mp[intervals[i][2]]-=intervals[i][0];
        }
        int ans=0;
        for(auto i:mp)
        {
            ans+=i.second;
            if(ans>capacity)
                return 0;
        }
        return 1;
    }
};