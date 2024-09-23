class Solution {
public:
    int solve(string s, unordered_set<string>& st, vector<int>& dp, int index)
    {
        if(index >= s.size()) 
            return 0;
        if(dp[index] != -1) 
            return dp[index];
        string temp = "";
        int mini = s.size();
        for(int i=index;i<s.size();i++)
        {
            temp.push_back(s[i]);
            int currDeleted=0;
            if(st.find(temp)==st.end())
                currDeleted = temp.size();
            mini = min(mini, currDeleted + solve(s, st, dp, i+1));
        }
        return dp[index] = mini;
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        vector<int> dp(s.size(), -1);
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        return solve(s, st, dp, 0);
    }
};