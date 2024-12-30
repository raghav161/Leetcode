class Solution {
public:
    int getMaxSum(vector<int>& pre, int i, int k, vector<vector<int>>& memo, int c) {
        if (c == 3 || i > pre.size() - 1 - k)
            return 0;
        if (memo[i][c])
            return memo[i][c];
        int sum = pre[i + k - 1] - (i > 0 ? pre[i - 1] : 0);
        int keep = sum + getMaxSum(pre, i + k, k, memo, c + 1);
        int skip = getMaxSum(pre, i + 1, k, memo, c);
        return memo[i][c] = max(keep, skip);
    }

    vector<int> getIndexList(vector<int>& pre, int i, int k, vector<int> indexList, vector<vector<int>>& memo, int c, int maxSum) {
        if (c == 3 && maxSum==0)
            return indexList;
        if (c == 3 || i > pre.size() - 1 - k || memo[i][c] != maxSum)
        {
            int m = 1e9;
            return {m, m, m};
        }
        int sum = pre[i + k - 1] - (i > 0 ? pre[i - 1] : 0);
        indexList.push_back(i);
        auto keep = getIndexList(pre, i + k, k, indexList, memo, c + 1, maxSum - sum);
        indexList.pop_back();
        auto skip = getIndexList(pre, i + 1, k, indexList, memo, c, maxSum);
        return min(keep, skip);
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n+1);
        vector<vector<int>> memo(n+1, vector<int>(3));
        pre[0] = nums[0];
        for(int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];
        int maxSum = getMaxSum(pre, 0, k, memo, 0);
        return getIndexList(pre, 0, k, {}, memo, 0, maxSum);
    }
};