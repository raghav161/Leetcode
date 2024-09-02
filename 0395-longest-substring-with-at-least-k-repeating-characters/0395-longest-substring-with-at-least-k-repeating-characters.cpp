class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size()==0 or s.size()<k)
            return 0;
        unordered_map<char, int> mp;
        for(auto c:s)
            mp[c]++;
        bool flag=1;
        for(auto c:s)
        {
            if(mp[c]<k)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            return s.size();
        int maxi=0, start=0;
        for(int end=0;end<s.size();end++)
        {
            if(mp[s[end]]<k)
            {
                maxi = max(maxi, longestSubstring(s.substr(start, end-start), k));
                start = end+1;
            }
        }
        maxi = max(maxi, longestSubstring(s.substr(start), k));
        return maxi;
    }
};
