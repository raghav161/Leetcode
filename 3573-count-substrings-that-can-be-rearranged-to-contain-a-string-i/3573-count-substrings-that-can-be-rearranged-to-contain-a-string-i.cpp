class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> mp1(26), mp2(26);
        int missing = 0;
        for (char c : word2)
            mp1[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (mp1[i] > 0)
                missing += mp1[i];
        }
        long long ans = 0;
        int left = 0;
        int n = word1.length();
        for (int right = 0; right < n; right++) {
            int c = word1[right] - 'a';
            mp2[c]++;
            if (mp1[c] > 0 && mp2[c] <= mp1[c])
                missing--;
            while (missing == 0) {
                ans += n - right;
                int left_char = word1[left] - 'a';
                if (mp1[left_char] > 0 && mp2[left_char] <= mp1[left_char])
                    missing++;
                mp2[left_char]--;
                left++;
            }
        }
        return ans;
    }
};