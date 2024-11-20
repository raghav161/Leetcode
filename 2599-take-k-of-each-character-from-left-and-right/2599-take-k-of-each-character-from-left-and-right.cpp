class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size(), left = 0, right = 0, m, ans = n, a = 0, b = 0, c = 0,
            countA = 0, countB = 0, countC = 0;
        for (char ch : s) {
            if (ch == 'a')
                countA++;
            else if (ch == 'b')
                countB++;
            else if (ch == 'c')
                countC++;
        }
        if (countA < k || countB < k || countC < k)
            return -1;
        while (right < n) {
            if (s[right] == 'a')
                a++;
            if (s[right] == 'b')
                b++;
            if (s[right] == 'c')
                c++;
            right++;
            while (a > countA - k || b > countB - k || c > countC - k) {
                if (s[left] == 'a')
                    a--;
                if (s[left] == 'b')
                    b--;
                if (s[left] == 'c')
                    c--;
                left++;
            }
            ans = min(ans, n - (right - left));
        }
        return ans;
    }
};