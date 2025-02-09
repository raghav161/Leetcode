class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i]-i;
            if(mp.find(x)!=mp.end())
                ans-=mp[x];
            ans+=i;
            mp[x]++;
        }
        return ans;
    }
};