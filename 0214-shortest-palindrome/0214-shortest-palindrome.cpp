class Solution {
public:
    string shortestPalindrome(string str) {
        int originalLength=str.size();
        string rev=str;
        reverse(rev.begin(), rev.end());
        str=str+'$'+rev;
        int newLength=str.size();
        vector<int> lps(newLength);
        int pre=0, suf=1;
        while(suf<newLength)
        {
            if(str[pre]==str[suf])
            {
                pre++;
                lps[suf]=pre;
                suf++;
            }
            else
            {
                if(pre==0)
                    suf++;
                else
                    pre=lps[pre-1];
            }
        }
        
        string ans = rev.substr(0, rev.size() - lps[newLength-1]);
        reverse(rev.begin(), rev.end());
        return ans+rev;
    }
};