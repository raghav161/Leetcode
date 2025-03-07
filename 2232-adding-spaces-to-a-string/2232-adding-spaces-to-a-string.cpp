class Solution {
public:
    string addSpaces(string s, vector<int>& A) {
        string ans;
        ans.reserve(s.size() + A.size());
        int N = s.size(), j = 0, M = A.size();
        for (int i = 0; i < N; ++i)
        {
            if (j < M && i == A[j])
            {
                ans += ' ';
                ++j;
            }
            ans += s[i];
        }
        return ans;
    }
};