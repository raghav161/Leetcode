class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            int count=0;
            long long curr=(long long)nums[i];
            while(st.find(curr)!=st.end())
            {
                count++;
                curr=(long long)curr*curr;
                if(curr>INT_MAX)
                    break;
            }
            maxi=max(maxi, count);
        }
        if(maxi<2)
            return -1;
        return maxi;
    }
};