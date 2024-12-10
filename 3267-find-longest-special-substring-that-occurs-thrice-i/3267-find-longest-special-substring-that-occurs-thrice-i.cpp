class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> mp;
        for(int i=0;i<s.length();i++)
        {
            string temp = "";
            temp += s[i];
            mp[temp]++;
            for(int j=i+1;j<s.length();j++)
            {
                if(s[i]==s[j])
                {
                    temp += s[j];
                    mp[temp]++;
                } 
                else
                    break;
            }
        }
        int ans=INT_MIN;
        for(auto it:mp)
        {
            if(it.second>=3)
                ans = max((int)it.first.size(), ans);
        }
        return ans == INT_MIN ? -1 : ans;
    }
};