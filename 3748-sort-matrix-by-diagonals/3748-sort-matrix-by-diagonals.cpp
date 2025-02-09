class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& num) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < num.size(); i++) {
            for (int j = 0; j < num[i].size(); j++)
                mp[i - j].push_back(num[i][j]);
        }
        for (auto& it : mp) {
            if (it.first >= 0)
                sort(it.second.begin(), it.second.end());
            else
                sort(it.second.rbegin(), it.second.rend());
        }
        for (int i = 0; i < num.size(); i++) {
            for (int j = 0; j < num[0].size(); j++) {
                num[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }
        return num;
    }
};