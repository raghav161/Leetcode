class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> st(bannedWords.begin(), bannedWords.end());
        int count=0;
        for(int i=0;i<message.size();i++)
        {
            if(st.count(message[i]))
                count++;
            if(count==2)
                return 1;
        }
        return 0;
    }
};