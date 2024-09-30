class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        map<int, int> mp = {{0, 0}, {INT_MAX, INT_MAX}};
        vector<bool> ans;
        for (auto& q : queries) {
            if (q[0] == 1)
            {
                auto c = mp.insert({q[1], -1}).first;
                auto p = prev(c);
                do {
                    c->second = max(c->first - p->first, p->second);
                    p = c;
                    c++;
                } while (c != mp.end() && c->second != p->second);
            } else {
                auto it = prev(mp.upper_bound(q[1]));
                ans.push_back(it->second >= q[2] || q[1] - it->first >= q[2]);
            }
        }
        return ans;
    }
};