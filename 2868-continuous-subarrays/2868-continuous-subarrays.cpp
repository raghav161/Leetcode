class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size(), i=0, j=0;
        multiset<int> st; 
        long long ans=0;
        while(i<n)
        {
            while(j<n && (st.size()==0 or max(nums[j], *st.rbegin())-min(*st.begin(), nums[j])<=2))
            {
                st.insert(nums[j]);
                j++;
            }
            ans+=st.size();
            st.erase(st.find(nums[i]));
            i++;
        }
        return ans;
    }
};