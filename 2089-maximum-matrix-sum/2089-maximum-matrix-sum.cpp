class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        long long neg_cnt = 0, ans = 0, minn = INT_MAX;
        for (int i = 0; i < a.size(); ++i)
            for (int j = 0; j < a.size(); ++j) {
                ans += abs(a[i][j]);
                if (a[i][j] < 0)
                    neg_cnt++;
                minn = min(minn, (long long)abs(a[i][j]));
            }
        if (neg_cnt % 2 == 0)
            return ans;
        return ans - 2*minn;
    }
};