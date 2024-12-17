class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> mp(26);
        for(auto& ch:s)
            mp[ch-'a']++;
        string ans;
        int i=25;
        while(i>=0)
        { 
            if(mp[i]==0)
            {
                i--;
                continue;
            }
            char ch='a'+i;
            int freq=min(mp[i], repeatLimit);
            ans.append(freq, ch);
            mp[i]-=freq;
            if(mp[i]>0)
            {
                int j=i-1;
                while(j>=0 and mp[j]==0)
                    j--;
                if(j<0)
                    break;
                ans.push_back('a'+j);
                mp[j]--;
            }
        }
        return ans;
    }
};