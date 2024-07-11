class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int count = 0, start = 0, end = 0;
        int n = s.size();
        while(end<n)
        {
            mp[s[end]]++;
            while( mp['a'] && mp['b'] && mp['c'] )
            {
                count+=n-end;
                mp[s[start]]--;
                start++;
            }
            end++;
        }
        return count;
    }
};