class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> matrix(26, vector<int>(s.length()+1));
        char prev_char = s[0];
        int length = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == prev_char)
                length++;
            else {
                length = 1;
                prev_char = s[i];
            }
            matrix[s[i]-'a'][length]++;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            int cumSum = 0;
            for(int j = s.length(); j >= 1; j--) {
                cumSum += matrix[i][j];
                if(cumSum >= 3) {
                    ans = max(ans, j);
                    break;
                }
            }
        }
        return ans == 0 ? -1 : ans;
    }
};