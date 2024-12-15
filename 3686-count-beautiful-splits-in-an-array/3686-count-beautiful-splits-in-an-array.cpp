class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        vector<long long> prefixHash(n + 1, 0);
        long long base = 31, mod = 1e9 + 7;
        vector<long long> power(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            prefixHash[i] = (prefixHash[i - 1] * base + nums[i - 1]) % mod;
            power[i] = (power[i - 1] * base) % mod;
        }
        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (checkPrefix(prefixHash, power, mod, 0, i, i, j) || checkPrefix(prefixHash, power, mod, i, j, j, n))
                    ++count;
            }
        }

        return count;
    }

private:
    bool checkPrefix(const vector<long long>& prefixHash, const vector<long long>& power, long long mod, int start1, int end1, int start2, int end2) {
        int len1 = end1 - start1;
        int len2 = end2 - start2;
        if (len1 > len2) 
            return false;
        long long hash1 = (prefixHash[end1] - prefixHash[start1] * power[len1] % mod + mod) % mod;
        long long hash2 = (prefixHash[start2 + len1] - prefixHash[start2] * power[len1] % mod + mod) % mod;
        return hash1 == hash2;
    }
};
