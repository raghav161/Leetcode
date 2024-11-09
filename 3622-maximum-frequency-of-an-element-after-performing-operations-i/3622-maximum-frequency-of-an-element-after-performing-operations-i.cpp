class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int ops) {
        sort(begin(nums), end(nums));
        unordered_map<int, int> um;
        for (int i : nums)
            um[i]++;
        int ans = 0;
        for (int i = nums[0]; i <= nums.back(); i++) {
            int a = lower_bound(begin(nums), end(nums), i - k) - begin(nums);
            int b = upper_bound(begin(nums), end(nums), i + k) - begin(nums);
            ans = max(ans, um[i] + min(b - a - um[i], ops));
        }
        return ans;
    }
};