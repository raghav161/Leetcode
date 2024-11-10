class Solution {
public:
    void LPS(string& word, vector<int>& lps) {
        int len = 0, i = 1;
        while(i < word.length()) {
            if(word[i] == word[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len)
                    len = lps[len-1];
                else
                    i++;
            }
        }
    }

    int minimumTimeToInitialState(string word, int k) {
        int n = word.length();
        vector<int> lps(n);
        LPS(word, lps);
        int maxLps = lps[n-1];
        while(maxLps > 0 && (n-maxLps)%k)
            maxLps = lps[maxLps-1];
        if((n-maxLps)%k == 0)
            return (n-maxLps)/k;
        return ceil(n/(double)k);
    }
};