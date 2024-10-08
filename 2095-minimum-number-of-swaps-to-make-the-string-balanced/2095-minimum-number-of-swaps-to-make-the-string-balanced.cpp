class Solution {
public:
    int minSwaps(string s) {
        int balance=0, ans=0, j=s.size()-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[')
                balance++;
            else
                balance--;
            if(balance < 0)
            {
                while(i<j and s[j]!='[')
                    j--;
                swap(s[i], s[j]);
                ans++;
                balance=1;
            }
        }
        return ans;
    }
};