class Solution {
public:
    int f(string& str, string s, int k) {
        int plus = 0, minus = 0, maxi = -1, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == str[0] || s[i] == str[1])
                plus++;
            else if ((s[i] == str[2] || s[i] == str[3]) && k > 0) {
                plus++;
                k--;
            } else
                minus--;
            maxi = max(abs(plus + minus), maxi);
        }
        return maxi;
    }
    int maxDistance(string s, int k) {
        int K = k, n = s.size(), ans = 0, plus = 0, minus = 0, maxi = -1;
        int up = 0, down = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'N' || s[i] == 'W')
                up++;
            else
                down++;
        }
        vector<string> v = {"NWSE", "SENW", "NESW", "SWNE"};
        for (int i = 0; i < 4; i++)
            maxi = max(maxi, f(v[i], s, k));
        return maxi;
    }
};