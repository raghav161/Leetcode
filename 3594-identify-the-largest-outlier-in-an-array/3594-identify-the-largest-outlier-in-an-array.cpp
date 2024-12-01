class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int ans=INT_MIN, sum=0;
        unordered_map<int, int> mp;
        for(auto it:nums)
        {
            mp[it]++;
            sum+=it;
        }
        for(auto it:nums)
        {
            int currSum=sum-it;
            mp[it]--;
            if(mp[it]==0) 
                mp.erase(it);
            if(currSum%2==0 and mp.count(currSum/2) and it>ans)
                ans=it;
            mp[it]++;
        }
        return ans;
    }
};