class Solution {
public:
    int minSwaps(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[')
                ans++;
            else if(ans>0)
                ans--;
        }
        return (ans+1)/2;
    }
};