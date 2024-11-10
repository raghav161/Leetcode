class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        vector<long long> freq(100001), subseq_sum(100001);
        for (int i=0;i<nums.size();i++) {
            long long count_adjacent = 1, sum_adjacent = nums[i];
            if (nums[i] > 0) {
                count_adjacent = (count_adjacent + freq[nums[i] - 1]) % MOD;
                sum_adjacent = (sum_adjacent + subseq_sum[nums[i] - 1] + (freq[nums[i] - 1] * nums[i]) % MOD) % MOD;
            }
            if (nums[i] < 100000) {
                count_adjacent = (count_adjacent + freq[nums[i] + 1]) % MOD;
                sum_adjacent = (sum_adjacent + subseq_sum[nums[i] + 1] + (freq[nums[i] + 1] * nums[i]) % MOD) % MOD;
            }
            result = (result + sum_adjacent) % MOD;
            freq[nums[i]] = (freq[nums[i]] + count_adjacent) % MOD;
            subseq_sum[nums[i]] = (subseq_sum[nums[i]] + sum_adjacent) % MOD;
        }
        return result;
    }
};
