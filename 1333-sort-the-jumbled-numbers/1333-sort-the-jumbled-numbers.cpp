class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b)
    {
        if(a.second==b.second)
            return a.first<b.first;
        return a.second<b.second;
    }
    int f(int val, vector<int>& mapping)
    {
        if(val==0)
            return mapping[val];
        int ans=0;
        int count=0;
        while(val)
        {
            int x=mapping[val%10];
            ans=ans+x*pow(10, count);
            count++;
            val/=10;
        }
        return ans;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            int newval=f(nums[i], mapping);
            ans.push_back({i, newval});
        }
        sort(ans.begin(), ans.end(), cmp);
        vector<int> ans2;
        for(int i=0;i<ans.size();i++)
            ans2.push_back(nums[ans[i].first]);
        return ans2;
    }
};