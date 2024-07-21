class Solution {
public:
    bool possible(vector<int>& nums, int divisor, int threshold) {
        int sum=0;
        for(auto num:nums)
            sum += ceil((double)num/divisor);
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if(possible(nums, mid, threshold))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return high+1;
    }
};