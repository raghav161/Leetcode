#define ll long long
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int ops) {
        sort(begin(nums), end(nums));
        
        unordered_map<ll, ll> um;
        for (int i : nums) um[i]++;
        
        ll ans = 0;
        
        for (int i = 0; i < size(nums); i++) {
            int a = lower_bound(begin(nums), end(nums), nums[i] - 2 * k) - begin(nums);
            int p = nums[i] - k;
            ans = max(ans, um[p] + min(i - a - um[p] + 1, (ll)ops));
        }
        
        for (int i : nums) {
            int a = lower_bound(begin(nums), end(nums), i - k) - begin(nums);
            int b = upper_bound(begin(nums), end(nums), i + k) - begin(nums) - 1;
            ans = max(ans, um[i] + min(b - a - um[i] + 1, (ll)ops));
        }
        
        return ans;
    }
};
