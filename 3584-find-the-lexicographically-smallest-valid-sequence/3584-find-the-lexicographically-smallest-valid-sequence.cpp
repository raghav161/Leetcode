class Solution {
    set<pair<int, pair<int, int>>> st;
public:
    bool f(int i, int j, int flag, string &word1, string &word2, vector<int> &ans) {
        if (j >= word2.size())
            return true;
        if (i >= word1.size())
            return false;
        if (st.count({i, {j, flag}}))
            return false;
        bool f1 = 0;
        if (word1[i] == word2[j])
        {
            f1 = f(i + 1, j + 1, flag, word1, word2, ans);
            if(f1)
                ans.push_back(i);
            return f1;
        }
        else
        {
            if(flag)
            {
                f1 = f(i + 1, j + 1, 0, word1, word2, ans);
                if(f1)
                {
                    ans.push_back(i);
                    return true;
                }
            }
            while (i < word1.size() && word1[i] != word2[j])
                i++;
            if (i < word1.size())
            {
                f1 = f(i + 1, j + 1, flag, word1, word2, ans);
                if(f1)
                {
                    ans.push_back(i);
                    return true;
                }
            }
        }
        st.insert({i, {j, flag}});
        return f1;
    }

    vector<int> validSequence(string word1, string word2) {
        vector<int> ans;
        if(f(0, 0, 1, word1, word2, ans))
        {
            reverse(ans.begin(), ans.end());
            if(ans.size()==word2.size())
                return ans;
        }
        return {};
    }
};