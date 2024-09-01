class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> ans;
        priority_queue<int> pq;
        for (auto& query : queries) {
            int x = abs(query[0]), y = abs(query[1]);
            pq.push(x+y);
            if (pq.size() > k)
                pq.pop();
            if (pq.size() < k)
                ans.push_back(-1);
            else
                ans.push_back(pq.top());
        }
        return ans;
    }
};
