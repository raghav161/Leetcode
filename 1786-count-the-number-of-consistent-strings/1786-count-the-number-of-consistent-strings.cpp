class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for(auto& ch:allowed)
            mask |= 1 << (ch-'a');
        int count=0;
        for(auto& word:words) {
            int allChar = 1;
            for(int i = 0; i < word.length(); i++)
            {
                if(((mask >> (word[i] - 'a')) & 1) == 0)
                {
                    allChar = 0;
                    break;
                }
            }
            count+=allChar;
        }
        return count;
    }
};