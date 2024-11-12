class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans=INT_MAX;
        unordered_set<int> ors;
        for(int i=0;i<nums.size();i++)
        {
            unordered_set<int> ors_ending_here;
            ors_ending_here.insert(nums[i]);
            for(auto ele:ors)
                ors_ending_here.insert(nums[i] | ele);
            for(auto x:ors_ending_here)
                ans=min(ans, abs(k-x));
            ors=ors_ending_here;
        }
        return ans;
    }
};