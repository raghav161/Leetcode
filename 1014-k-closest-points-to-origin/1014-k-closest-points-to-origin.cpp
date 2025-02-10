class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto euclidean = [](auto& p) { 
            return p[0] * p[0] + p[1] * p[1]; 
        };
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < size(points); i++) {
            pq.push({euclidean(points[i]), i});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans(k);
        for (int i = 0; i < k; i++){
            ans[i] = points[pq.top().second];
            pq.pop();
        }
        return ans;
    }
};