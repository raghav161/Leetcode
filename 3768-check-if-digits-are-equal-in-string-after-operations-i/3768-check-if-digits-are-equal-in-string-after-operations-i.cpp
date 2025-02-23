class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            string s1 = "";
            for (size_t i = 0; i < s.length() - 1; i++) {
                int a = (s[i] + s[i + 1]) % 10;
                s1 += a;
            }
            s = s1;
        }
        return s[0] == s[1];
    }
};