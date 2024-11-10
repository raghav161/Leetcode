class Solution {
public:
    void lpss(string& s, vector<int>& lps) {
        int len = 0, i = 1;
        while(i < s.size()) {
            if(s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if(len)
                    len = lps[len-1];
                else
                    i++;
            }
        }
    }

    void f(string& s, string& t, vector<int>& lps, vector<int>& matchesIdx, int len) {
        int i = 0, j = 0;
        while(i < s.size()) {
            if(s[i] == t[j]) {
                i++;
                j++;
            } 
            if(j == len) {
                matchesIdx.push_back(i - j);
                j = lps[j - 1];
            }
            else if(j<t.size() and s[i]!= t[j])
            {
                if(j)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size(), aLen = a.size(), bLen = b.size();
        vector<int> lpsA(aLen), lpsB(bLen);
        lpss(a, lpsA);
        lpss(b, lpsB);
        vector<int> aMatchesIdx, bMatchesIdx;
        f(s, a, lpsA, aMatchesIdx, aLen);
        f(s, b, lpsB, bMatchesIdx, bLen);
        sort(bMatchesIdx.begin(), bMatchesIdx.end());
        vector<int> ans;
        for(int i = 0; i < aMatchesIdx.size(); ++i) {
            int i_idx = aMatchesIdx[i];
            auto lb = lower_bound(bMatchesIdx.begin(), bMatchesIdx.end(), i_idx - k);
            auto ub = upper_bound(bMatchesIdx.begin(), bMatchesIdx.end(), i_idx + k);
            if(lb != ub)
                ans.push_back(i_idx);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};