class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int result=0, sum=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++) 
        {
            sum=(sum+nums[i])%k;
            int rem=sum%k;
            if(rem<0)
                rem+=k;
            if(mp.find(rem) != mp.end())
                result += mp[rem];
            mp[rem]++;
        }
        return result;
    }
};