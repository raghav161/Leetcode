class Solution {
public:
    vector<long long> mini(vector<int>& arr) {
        int n = arr.size();
        vector<long long> sum(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            int j = -1;
            if (!st.empty())
                j = st.top();
            sum[i] = (long long)(i - j) * arr[i];
            if (j >= 0)
                sum[i] += sum[j];
            st.push(i);
        }
        return sum;
    }
    vector<long long> maxi(vector<int>& arr) {
        int n = arr.size();
        vector<long long> sum(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            int j = -1;
            if (!st.empty())
                j = st.top();
            sum[i] = (long long)(i - j) * arr[i];
            if (j >= 0)
                sum[i] += sum[j];
            st.push(i);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<long long> minii=mini(nums), maxii=maxi(nums);
        long long sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=(maxii[i]-minii[i]);
        return sum;
    }
};