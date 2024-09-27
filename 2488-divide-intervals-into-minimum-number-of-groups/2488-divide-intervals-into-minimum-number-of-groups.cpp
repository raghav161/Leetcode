class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for(int i=0;i<intervals.size();i++)
        {
            mp[intervals[i][0]]++;
            mp[intervals[i][1]+1]--;
        }
        int maxi=1, ans=0;
        for(auto i:mp)
        {
            ans+=i.second;
            maxi=max(maxi, ans);
        }
        return maxi;
    }
};