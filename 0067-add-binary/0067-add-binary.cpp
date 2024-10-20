class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        
        string ans = "";
        int carry = 0;

        while (i >= 0 && j >= 0) {
            if (a[i] =='1' && b[j] == '0' || a[i] == '0' && b[j] == '1') {
                if(carry)
                    ans.push_back('0');
                else
                    ans.push_back('1');
                i--;
                j--;
            } 
            else if (a[i] == '0' && b[j] == '0') {
                if (carry == 1) {
                    ans.push_back('1');
                    carry = 0;
                }
                else
                    ans.push_back('0');
                i--;
                j--;
            } else if (a[i] == '1' && b[j] == '1') {
                if (carry == 1)
                    ans.push_back('1');
                else {
                    carry = 1;
                    ans.push_back('0');
                }
                i--;
                j--;
            }
        }

        while (i >= 0) {
            if (carry == 1) {
                if (a[i] == '1') {
                    ans.push_back('0');
                    carry = 1;
                } else {
                    ans.push_back('1');
                    carry = 0;
                }
            } 
            else
                ans.push_back(a[i]);
            i--;
        }

        while (j >= 0) {
            if (carry == 1) {
                if (b[j] == '1') {
                    ans.push_back('0');
                    carry = 1;
                } else {
                    ans.push_back('1');
                    carry = 0;
                }
            }
            else
                ans.push_back(b[j]);
            j--;
        }
        if (carry == 1)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
