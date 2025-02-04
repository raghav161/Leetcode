class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int j=1, sum=nums[0], maxi=0;
        while(j<nums.size())
        {
            if(nums[j-1]<nums[j])
                sum+=nums[j];
            else
            {
                maxi=max(maxi, sum);
                sum=nums[j];
            }
            j++;
        }
        maxi=max(maxi, sum);
        return maxi;
    }
};