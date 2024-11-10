class Solution {
public:
    void f(string pat, vector<int>& lps) {
        int len = 0, i = 1;
        while(i < pat.size()) {
            if(pat[len] == pat[i])
            {
                len++;
                lps[i] = len;
                i++;
            } 
            else
            {
                if(len)
                    len = lps[len-1];
                else
                    i++;
            }
        }
    }
    long long sumScores(string s) {
        vector<int> lps(s.size()), ans;
        f(s, lps);
        for(int i=0;i<lps.size();i++)
        {
            if(lps[i])
                ans.push_back(ans[lps[i]-1]+1);
            else
                ans.push_back(0);
        }
        return accumulate(begin(ans), end(ans), 0LL) + s.size(); 
    }
};