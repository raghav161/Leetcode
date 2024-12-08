class Solution {
public:
    long long maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long long> pref;
        pref.push_back(arr[0]);
        for (int i = 1; i < n; i++)
            pref.push_back(pref[i - 1] + arr[i]);
        long long res = -1e18;
        map<int, long long> mp;
        mp[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (mp.count(i%k)) {
                res = (long long)max(res, (long long)(pref[i-1] - mp[i%k]));
                mp[i%k] = min(mp[i%k], pref[i-1]);
            }
            else
                mp[i%k] = pref[i-1];        
        }
        return res;
    }
};