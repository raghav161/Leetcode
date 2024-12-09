class Solution {
public:
    vector<int> calculateZArray(string s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r)
                z[i] = min(r - i, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }

    int minStartingIndex(string s, string p) {
        string combined = p + s;
        vector<int> forwardZ = calculateZArray(combined);
        reverse(p.begin(), p.end());
        reverse(s.begin(), s.end());
        combined = p + s;
        vector<int> backwardZ = calculateZArray(combined);
        int n = forwardZ.size();
        int j = n - p.size();
        for (int i = p.size(); i < n; i++) {
            if (j < p.size())
                break;
            int forwardMatch = forwardZ[i];
            int backwardMatch = backwardZ[j];
            if (forwardMatch + backwardMatch >= p.size() - 1)
                return i - p.size();
            j--;
        }
        return -1;
    }
};