class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(), i = k, j = k, curMin = nums[k], result = nums[k];
        while (i > 0 || j < n - 1) {
            int leftValue=0, rightValue=0;
            if (i > 0)
                leftValue = nums[i - 1];
            if (j < n - 1)
                rightValue = nums[j + 1];
            if (leftValue < rightValue){
                j++;
                curMin = min(curMin, nums[j]);
            } else {
                i--;
                curMin = min(curMin, nums[i]);
            }
            result = max(result, curMin*(j-i+1));
        }
        return result;
    }
};