class Solution {
public:
    int maximumLength(string s) {
        unordered_map<char, vector<int>> mp;
        char prev_char = s[0];
        int length = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == prev_char)
                length++;
            else {
                length = 1;
                prev_char = s[i];
            }
            if(mp[s[i]].size() <= length)
                mp[s[i]].resize(length + 1, 0);
            mp[s[i]][length]++;
        }
        int ans = 0;
        for(auto& entry : mp) {
            int cumSum = 0;
            for (int len = entry.second.size() - 1; len >= 1; len--) {
                cumSum += entry.second[len];
                if (cumSum >= 3) {
                    ans = max(ans, len);
                    break;
                }
            }
        }
        return ans == 0 ? -1 : ans;
    }
};
