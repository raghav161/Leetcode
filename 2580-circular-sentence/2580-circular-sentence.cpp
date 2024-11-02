class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0]!=sentence[sentence.size()-1])
            return 0;
        for(int i=1;i<sentence.size()-1;i++)
        {
            if(sentence[i]==' ' and sentence[i-1]!=sentence[i+1])
                return 0;
        }
        return 1;
    }
};