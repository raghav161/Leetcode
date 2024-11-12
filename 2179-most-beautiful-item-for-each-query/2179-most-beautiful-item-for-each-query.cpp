class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans(queries.size());
        vector<pair<int, int>> q;
        for (int i = 0; i < queries.size(); i++)
            q.push_back({queries[i], i});
        sort(q.begin(), q.end());
        sort(items.begin(), items.end());
        int itemIndex = 0, maxBeauty = 0;
        for (int i = 0; i < q.size(); i++) {
            int maxPriceAllowed = q[i].first;
            int queryOriginalIndex = q[i].second;
            while (itemIndex < items.size() && items[itemIndex][0] <= maxPriceAllowed) {
                maxBeauty = max(maxBeauty, items[itemIndex][1]);
                itemIndex++;
            }
            ans[queryOriginalIndex] = maxBeauty;
        }
        return ans;
    }
};