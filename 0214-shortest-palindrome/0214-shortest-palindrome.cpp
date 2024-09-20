class Solution {
public:
    string shortestPalindrome(string str) {
        int originalLength=str.size();
        string rev=str;
        reverse(rev.begin(), rev.end());
        string temp=str+'$'+rev;
        int newLength=temp.size();
        vector<int> lps(newLength);
        int pre=0, suf=1;
        while(suf<newLength)
        {
            if(temp[pre]==temp[suf])
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
        return rev.substr(0, originalLength - lps[newLength-1]) + str;
    }
};