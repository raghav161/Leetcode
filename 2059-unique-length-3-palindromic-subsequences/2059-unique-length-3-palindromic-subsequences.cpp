class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size(), ans=0;
        vector<int> first(26, INT_MAX), last(26);
        for(int i=0;i<n;i++)
        {
            first[s[i]-'a']=min(i, first[s[i]-'a']);
            last[s[i]-'a']=i;
        }
        for(int i=0;i<26;i++)
        {
            if(first[i]<last[i])
                ans += unordered_set(begin(s)+first[i]+1, begin(s)+last[i]).size();
        }
        return ans;
    }
};