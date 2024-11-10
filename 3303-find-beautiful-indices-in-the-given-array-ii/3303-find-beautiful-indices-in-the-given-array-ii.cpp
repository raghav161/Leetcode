class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size(), aLen = a.size(), bLen = b.size();
        vector<int> lpsA(aLen), lpsB(bLen);
        calculateLPSArray(a, lpsA, aLen);
        calculateLPSArray(b, lpsB, bLen);
        vector<int> aMatchesIdx, bMatchesIdx;
        findMatchingIdx(s, a, lpsA, aMatchesIdx, n, aLen);
        findMatchingIdx(s, b, lpsB, bMatchesIdx, n, bLen);
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
    void calculateLPSArray(string& s, vector<int>& lps, int n) {
        int len = 0, i = 1;
        while(i < n) {
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

    void findMatchingIdx(string& s, string& t, vector<int>& lps, vector<int>& matchesIdx, int n, int len) {
        int i = 0, idx = 0;
        while(i < n) {
            if(s[i] == t[idx]) {
                i++;
                idx++;
            } 
            if(idx == len) {
                matchesIdx.push_back(i - idx);
                idx = lps[idx - 1];
            }
            else if(idx<t.size() and s[i]!= t[idx])
            {
                if(idx)
                    idx = lps[idx - 1];
                else
                    i++;
            }
        }
    }
};