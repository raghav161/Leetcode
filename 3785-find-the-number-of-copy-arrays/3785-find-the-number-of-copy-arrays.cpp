class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int l = bounds[0][0], r = bounds[0][1];
        for (int i = 1; i < original.size(); ++i) {
            int diff = original[i] - original[i - 1];
            l = max(l + diff, bounds[i][0]);
            r = min(r + diff, bounds[i][1]);
            if (l > r)
                return 0;
        }
        return r - l + 1;
    }
};