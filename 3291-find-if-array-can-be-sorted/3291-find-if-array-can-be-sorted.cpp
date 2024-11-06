class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int k=0;
        for(int j=0;j<nums.size();j++)
        {
            for(int i=1;i<nums.size();i++)
            {
                if(__builtin_popcount(nums[i])==__builtin_popcount(nums[i-1]) && nums[i-1]>nums[i])
                    swap(nums[i], nums[i-1]);
            }
            if(is_sorted(nums.begin(), nums.end()))
                return 1;
        }
        return 0;
    }
};