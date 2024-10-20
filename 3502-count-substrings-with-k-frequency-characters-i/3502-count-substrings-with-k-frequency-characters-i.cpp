class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0, left = 0;
        unordered_map<char, int> mp;
        for (char c : s)
        {
            mp[c]++;
            while (mp[c] == k) {
                mp[s[left]]--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};