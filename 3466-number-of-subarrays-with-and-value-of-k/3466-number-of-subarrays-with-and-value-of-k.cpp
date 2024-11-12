class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        using ll = long long;
        unordered_map<int, int> mp;
        ll res = 0;
        for(auto& num:nums)
        {
            unordered_map<int, int> temp;
            temp[num]++;
            for(auto& it:mp)
                temp[it.first & num] += it.second;
            res += temp[k];
            mp = temp;
        }
        return res;
    }
};