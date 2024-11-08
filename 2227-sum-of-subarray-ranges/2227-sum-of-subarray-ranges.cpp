typedef unsigned long long ll;
class Solution {
public:
    vector<int> prevSmallers(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }
    
    vector<int> nextSmallers(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }
    
    vector<int> nextGreater(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) 
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> prevGreater(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> pge(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) 
                st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }
    
    ll sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevSmaller = prevSmallers(arr);
        vector<int> nextSmaller = nextSmallers(arr);
        vector<int> prevlarg = nextGreater(arr);
        vector<int> nextlarg = prevGreater(arr);
        ll summini = 0, summaxi = 0;
        for (int i = 0; i < n; i++) {
            ll d1 = i - prevSmaller[i];
            ll d2 = nextSmaller[i] - i;
            ll total_ways_for_i_min = d1 * d2;
            ll sum_i_in_total_ways = static_cast<ll>(arr[i]) * total_ways_for_i_min;
            summini = (summini + sum_i_in_total_ways);
        }
        for (int i = 0; i < n; i++) {
            ll d3 = i - prevlarg[i];
            ll d4 = nextlarg[i] - i;
            ll total_ways_for_i_max = d3 * d4;
            ll sum_i_in_total_ways = static_cast<ll>(arr[i]) * total_ways_for_i_max;
            summaxi = (summaxi + sum_i_in_total_ways);
        }
        ll result = (summaxi - summini);
        return result;
    }
    
    ll subArrayRanges(vector<int>& nums) {
        return sumSubarrayMins(nums);
    }
};
