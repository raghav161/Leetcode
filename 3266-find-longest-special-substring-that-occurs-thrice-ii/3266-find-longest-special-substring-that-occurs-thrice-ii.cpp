class Solution {
public:
    int maximumLength(string s) {
        unordered_map<char, map<int, int>> freqMap;
        char prev_char = s[0];
        int length = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == prev_char) {
                length++;
            } else {
                length = 1;
                prev_char = s[i];
            }
            freqMap[s[i]][length]++;
        }
        int ans = 0;
        for (auto& charEntry : freqMap) {
            int cumSum = 0;
            for (auto it = charEntry.second.rbegin(); it != charEntry.second.rend(); ++it) {
                cumSum += it->second;
                if (cumSum >= 3) {
                    ans = max(ans, it->first);
                    break;
                }
            }
        }
        return ans == 0 ? -1 : ans;
    }
};
