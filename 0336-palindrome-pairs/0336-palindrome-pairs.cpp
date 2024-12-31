class Solution {
public:
    bool isPalindrome(string& word, int l, int r) {
        while (l < r) {
            if (word[l] != word[r]) 
                return false;
            l++, r--;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) 
            mp[string(words[i].rbegin(), words[i].rend())] = i;
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            string& word = words[i];
            int len = word.size();
            for (int j = 0; j <= len; j++) {
                if (isPalindrome(word, 0, j - 1)) {
                    string suffix = word.substr(j);
                    if (mp.find(suffix) != mp.end() && mp[suffix] != i)
                        res.push_back({mp[suffix], i});
                }
                if (j != word.length() && isPalindrome(word, j, len - 1)) {
                    string prefix = word.substr(0, j);
                    if (mp.find(prefix) != mp.end() && mp[prefix] != i)
                        res.push_back({i, mp[prefix]});
                }
            }
        }
        return res;
    }
};