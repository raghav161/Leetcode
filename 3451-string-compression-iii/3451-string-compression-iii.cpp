class Solution {
public:
    string compressedString(string word) {
        int n=word.length(), i=0, j=0;
        string ans="";
        while(j<n)
        {
            int count=0;
            while(word[i]==word[j] && count<9)
            {
                j++;
                count++;
            }
            ans += to_string(count) + word[i];
            i=j;
        }
        return ans;
    }
};