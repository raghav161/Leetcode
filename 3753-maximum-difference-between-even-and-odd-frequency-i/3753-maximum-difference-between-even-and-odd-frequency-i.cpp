class Solution {
public:
    int maxDifference(string s) {
        unordered_map<int, int> mpp;        
        for (auto it : s)
            mpp[it - 'a']++;
        int odd = -1, even = INT_MAX;
        for (auto it : mpp) {
            if (it.second % 2)
                odd = max(odd, it.second);
            else
                even = min(even, it.second);
        }
        return odd - even;
    }
};