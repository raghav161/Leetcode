class Solution {
public:
    vector<int> build(string p) {
        int n = p.size();
        vector<int> pi(n, 0);
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && p[i] != p[j]) {
                j = pi[j - 1];
            }
            if (p[i] == p[j]) {
                j++;
            }
            pi[i] = j;
        }
        return pi;
    }
    vector<int> find(string s, string p) {
        if (p.empty()) {
            vector<int> res;
            for (int i = 0; i <= s.size(); i++) {
                res.push_back(i);
            }
            return res;
        }
        vector<int> pi = build(p), res;
        for (int i = 0, j = 0; i < s.size(); i++) {
            while (j > 0 && s[i] != p[j]) {
                j = pi[j - 1];
            }
            if (s[i] == p[j]) {
                j++;
            }
            if (j == (int)p.size()) {
                res.push_back(i - j + 1);
                j = pi[j - 1];
            }
        }
        return res;
    }
    int shortestMatchingSubstring(string s, string p) {
        int star1 = p.find('*');
        int star2 = p.find('*', star1 + 1);

        string p1 = p.substr(0, star1);
        string p2 = p.substr(star1 + 1, star2 - (star1 + 1));
        string p3 = p.substr(star2 + 1);

        vector<int> v1 = find(s, p1);
        if (!p1.empty() && v1.empty()) {
            return -1;
        }
        vector<int> v2 = find(s, p2);
        if (!p2.empty() && v2.empty()) {
            return -1;
        }
        vector<int> v3 = find(s, p3);
        if (!p3.empty() && v3.empty()) {
            return -1;
        }
        int minLen = INT_MAX;
        for (int i : v1) {
            int afterP1 = i + p1.size();
            auto it2 = lower_bound(v2.begin(), v2.end(), afterP1);
            if (it2 == v2.end()) {
                continue;
            }
            int j = *it2;
            int afterP2 = j + p2.size();
            auto it3 = lower_bound(v3.begin(), v3.end(), afterP2);
            if (it3 == v3.end()) {
                continue;
            }
            int k = *it3;
            minLen = min(minLen, (k + (int)p3.size()) - i);
        }
        return (minLen == INT_MAX) ? -1 : minLen;
    }
};