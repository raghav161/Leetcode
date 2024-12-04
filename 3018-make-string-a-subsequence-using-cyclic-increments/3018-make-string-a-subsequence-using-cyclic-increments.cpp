class Solution {
public:
    bool canMakeSubsequence(string s, string p) {
        int n=s.length(), m=p.length(); 
        if(m>n) 
            return false;
        int j=0;
        for(int i=0;i<n && j<m;i++)
        {
            if(s[i]==p[j])
                j++; 
            else
            {
                int idx = (s[i]-'a');
                int new_idx = (idx+1)%26;
                char ch = (char)(new_idx+'a');
                if(ch==p[j])
                    j++;
            }
        }
        return (j==m); 
    }
};