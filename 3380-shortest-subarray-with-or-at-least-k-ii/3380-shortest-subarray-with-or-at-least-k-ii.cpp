class Solution {
public:
    void fillBits(vector<int>& bits, int x) {
        for (int i = 31; i >= 0; i--) {
            if ((x & (1 << i)) != 0) {
                bits[i]++;
            }
        }
    }
    int solve(vector<int>& bits) {
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if (bits[i] > 0) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
    void updateBits(vector<int>& bits, int x) {
        for (int i = 31; i >= 0; i--) {
            if ((x & (1 << i)) != 0) {
                bits[i]--;
            }
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MAX;
        for (auto i : nums) {
            if (i >= k)
                return 1;
        }
        int i = 0, j = 0;
        int curor = 0;
        vector<int> bits(32, 0);
        while (j < n) {
            curor |= nums[j];
            fillBits(bits, nums[j]);
            while (i <= j && curor >= k) {
                ans = min(ans, j - i + 1);
                updateBits(bits, nums[i]);
                curor = solve(bits);
                i++;
            }
            j++;
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};