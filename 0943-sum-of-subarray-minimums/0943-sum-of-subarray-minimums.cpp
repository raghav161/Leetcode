class Solution {
public:
    const int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), res = 0;
        vector<int> sum(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            int j = -1;
            if (!st.empty())
                j = st.top();
            sum[i] = (i - j) * arr[i];
            if (j >= 0)
                sum[i] += sum[j];
            sum[i] %= mod;
            st.push(i);
        }
        for (auto it : sum)
            res = (res + it) % mod;
        return res;
    }
};