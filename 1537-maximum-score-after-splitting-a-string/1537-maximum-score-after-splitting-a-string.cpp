class Solution {
public:
    int maxScore(string s) {
        int ones=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
                ones++;
        }
        int zeroes=0, score=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]=='0')
                zeroes++;
            else
                ones--;
            score = max(score, zeroes+ones);
        }
        return score;
    }
};