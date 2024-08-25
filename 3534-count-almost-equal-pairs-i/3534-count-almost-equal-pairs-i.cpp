class Solution {
public:
    int countPairs(vector<int>& nums) {
        vector<string> snums;
        sort(nums.begin(), nums.end());
        for (auto ele : nums)
            snums.push_back(to_string(ele));
        int ans = 0;
        int n = snums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string curr = snums[i], check = snums[j];
                if (stoi(curr) == stoi(check)) {
                    ans++;
                    continue;
                }
                bool checked = 0;
                for (int k = 0; k < check.size(); k++) {
                    for (int l = k + 1; l < check.size(); l++) {
                        swap(check[k], check[l]);
                        if (stoi(curr) == stoi(check)) {
                            ans++;
                            checked = 1;
                            break;
                        }
                        swap(check[k], check[l]);
                    }
                    if(checked==1)
                        break;
                }
            }
        }
        return ans;
    }
};