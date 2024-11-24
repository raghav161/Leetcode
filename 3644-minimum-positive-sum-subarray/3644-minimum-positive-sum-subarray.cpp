class Solution {
public:
    int minimumSumSubarray(vector<int>& arr, int l, int r) {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + arr[i];
        int min_sum = INT_MAX;
        for (int length = l; length <= r; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int curr_sum =
                    prefix[i + length - 1] - (i > 0 ? prefix[i - 1] : 0);
                if (curr_sum > 0)
                    min_sum = min(min_sum, curr_sum);
            }
        }
        return min_sum == INT_MAX ? -1 : min_sum;
    }
};