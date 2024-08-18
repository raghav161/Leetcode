class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length(), count = 0;
        for (int i = 0; i < n; i++)
        {
            int zeros = 0, ones = 0;
            for (int j = i; j < n; j++)
            {
                if (s[j] == '0')
                    zeros++;
                else
                    ones++;
                if (zeros <= k || ones <= k)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};