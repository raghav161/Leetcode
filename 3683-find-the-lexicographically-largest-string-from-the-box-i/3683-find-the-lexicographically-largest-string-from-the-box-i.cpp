class Solution {
public:
    string answerString(string word, int numFriends) {
        int last = 0, len = word.size() - (numFriends - 1);
        if (numFriends == 1)
            return word;
        vector<string> ans;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] < last)
                continue;
            last = word[i];
            string t =
                word.substr(i, (word.size() - i) < len ? word.size() - i : len);
            ans.push_back(t);
        }
        sort(ans.begin(), ans.end());
        return ans.back();
    }
};