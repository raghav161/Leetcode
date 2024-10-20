class Solution {
public:
    string addBinary(string a, string b) 
    {
        string res ="";
        for(int carry=0,i=a.length()-1,j=b.length()-1;i>=0 or j>=0 or carry>0;carry/=2)
        {
            if(i>=0) 
            {
                carry+=a[i]-'0';
                i--;
            }
            if(j>=0) 
            {
                carry+=b[j]-'0';
                j--;
            }
            res = to_string(carry%2) + res;
        }
        return res;
    }
};