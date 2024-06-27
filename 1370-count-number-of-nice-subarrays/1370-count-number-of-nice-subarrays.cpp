class Solution {
public:
    int f(vector<int>& nums,int k)
    {
        int ans=0, count=0, i=0, j=0, n=nums.size();
        while(j<n)
        {
            if(nums[j]%2)
                count++;
            while(i<=j && count>k)
            {
                if(nums[i]%2)
                    count--;
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k)-f(nums, k-1);
    }
};