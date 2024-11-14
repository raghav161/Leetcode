class Solution {
public:
    bool possible(vector<int>& nums, int n, int mid)
    {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=mid)
                count++;
            else
                count+=ceil((double)nums[i]/mid);
        }
        return count<=n;
    }
    int minimizedMaximum(int n, vector<int>& nums) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while(left<=right) 
        {
            int mid = left + (right - left) / 2;
            if(possible(nums, n, mid))
                right = mid - 1;
            else 
                left = mid + 1;
        }  
        return right+1;
    }
};