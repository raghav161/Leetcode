class Solution {
public:
    string minWindow(string s, string t) {
        int l=0, mini=1e9, start=-1;
        vector<int> hash(256);
        int count=0;
        for(int i=0;i<t.size();i++)
            hash[t[i]]--;
        for(int r=0;r<s.size();r++)
        {
            if(hash[s[r]]<0)
                count++;
            hash[s[r]]++;
            while(count==t.size())
            {
                if(r-l+1<mini)
                {
                    mini=r-l+1;
                    start=l;
                }
                hash[s[l]]--;
                if(hash[s[l]]<0) 
                    count--;
                l++;
            }
        }
        return start==-1 ? "" : s.substr(start, mini);
    }
};