class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans=0;
        int start=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>nums[start])
            {
                ans+=(i-start)*1LL*nums[start];
                start=i;
            }
        }
        return ans+(nums.size()-1-start)*1LL*nums[start];
    }
};