class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(), nums.end()), ans=0, count=0;
        for(auto num:nums)
        {
            if(num==maxi)
                count++;
            else
                count=0;
            ans = max(ans, count);
        }
        return ans;
    }
};