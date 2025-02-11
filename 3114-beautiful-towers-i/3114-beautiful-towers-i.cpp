class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans = 0;
        for (int i = 0; i < maxHeights.size(); ++i) {
            long long sum = maxHeights[i], last = maxHeights[i];
            for (int j = i - 1; j >= 0; --j) {
                last = min((long long)maxHeights[j], last);
                sum += last;
            }
            last = maxHeights[i];
            for (int j = i + 1; j < maxHeights.size(); ++j) {
                last = min((long long)maxHeights[j], last);
                sum += last;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};