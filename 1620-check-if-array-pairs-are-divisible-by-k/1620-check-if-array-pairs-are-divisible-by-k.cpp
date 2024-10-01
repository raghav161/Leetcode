class Solution {
public:
    bool canArrange(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[(nums[i]%k+k)%k]++;
        }
        if(mp[0]%2)
            return 0;
        for(int i=1;i<=k/2;i++)
        {
            if(mp[i]!=mp[k-i]) 
                return false;
        }
        return true;
    }
};