class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                bool isValid = false;
                for (int count : freq) {
                    if (count >= k) {
                        isValid = true;
                        break;
                    }
                }
                if (isValid)
                    result++;
            }
        }

        return result;
    }
};
