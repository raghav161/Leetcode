class Solution {
public:
    string largestPalindrome(int n, int k) {
        string res(n, '9');
        if (k == 1 || k == 9 || k == 3)
            return res;
        else if (k == 5) {
            res[0] = res.back() = '5';
        }
        else if (k == 4 || k == 8) {
            res[0] = res.back() = '8';
            if (n > 1) {
                res[1] = res[n - 2] = '8';
            }
            if (k == 8 && n >= 3) {
                res[2] = res[n - 3] = '8';
            }
        }
        else if (k == 2) {
            res[0] = res.back() = '8';
        }
        else if (k == 6) {
            if (n < 3) {
                res[0] = res.back() = '6';
            } else {
                res[0] = res.back() = '8';
                int mid = n / 2;
                if (n % 2 == 0) {
                    res[mid - 1] = res[mid] = '7';
                } else {
                    res[mid] = '8';
                }
            }
        }
        else if (k == 7) {
            int mid = n / 2;      
            for (int j = 9; j >= 0; j--) {
                res[mid] = '0' + j;
                if (!(n & 1)) {
                    res[mid - 1] = '0' + j;
                }
                int lst = 0;
                for (int i = 0; i < n; i++) {
                    int cur = (lst * 10 + (res[i] - '0')) % 7;
                    lst = cur;
                }
                if (!lst) return res;
            }
        }
        return res;
    }
};