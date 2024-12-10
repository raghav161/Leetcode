class Solution {
public:
    int maximumLength(string s) {
        unordered_map<char, vector<int>> mp; // Stores counts of segment lengths for each character
        char prev_char = s[0];
        int length = 0;

        // Traverse the string and update the map
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == prev_char) {
                length++;
            } else {
                length = 1;
                prev_char = s[i];
            }

            // Ensure the vector is large enough to handle 'length'
            if (mp[s[i]].size() <= length) {
                mp[s[i]].resize(length + 1, 0);
            }
            mp[s[i]][length]++;
        }

        int ans = 0;

        // Process each character's length vector
        for (auto& entry : mp) {
            vector<int>& counts = entry.second;
            int cumSum = 0;

            // Traverse counts from the back to calculate cumulative sum
            for (int len = counts.size() - 1; len >= 1; len--) {
                cumSum += counts[len];
                if (cumSum >= 3) {
                    ans = max(ans, len);
                    break;
                }
            }
        }

        return ans == 0 ? -1 : ans;
    }
};
