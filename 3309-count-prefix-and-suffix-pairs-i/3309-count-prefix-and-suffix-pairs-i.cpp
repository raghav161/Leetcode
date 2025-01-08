class Solution {
public:
    bool prefix(string a, string b){
        if(a.length()>b.length())
            return 0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])
                return 0;
        }
        return 1;
    }
    bool suffix(string a, string b){
        if(a.length()>b.length())
            return 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])
                return 0;
        }
        return 1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(prefix(words[i], words[j]) && suffix(words[i], words[j]))
                    count++;
            }
        }
        return count;
    }
};