class Solution {
public:
    static bool cmp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
    {
        if(a.second.second==b.second.second)
            return a.first<b.first;
        return a.second.second<b.second.second;
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
        vector<pair<int, pair<int, int>>> ans;
        for(int i=0;i<nums.size();i++)
        {
            int newval=f(nums[i], mapping);
            ans.push_back({i, {nums[i], newval}});
        }
        sort(ans.begin(), ans.end(), cmp);
        for(int i=0;i<ans.size();i++)
            nums[i]=ans[i].second.first;
        return nums;
    }
};