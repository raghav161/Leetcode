class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size(), mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int ans=0;
            for(int j=i;j<n;j++)
            {
                ans=ans|nums[j];
                if(ans>=k)
                    mini=min(mini, j-i+1);
            }
        }
        return (mini==INT_MAX)?-1:mini;
    }
};