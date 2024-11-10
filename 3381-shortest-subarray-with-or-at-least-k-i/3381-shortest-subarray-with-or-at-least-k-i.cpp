class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), mini = INT_MAX, left = 0, subarrayOR = nums[0];
        for (int right = 1; right < n; ++right) {
            subarrayOR |= nums[right];
            while (subarrayOR >= k && left<=right) {
                mini = min(mini, right - left + 1);
                subarrayOR ^= nums[left];
                ++left;
            }
        }

        return (mini == INT_MAX) ? -1 : mini;
    }
};
