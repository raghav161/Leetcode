class Solution {
public:
    int closestToTarget(vector<int>& nums, int target) {
        int ans=INT_MAX;
        unordered_set<int> ors;
        for(int i=0;i<nums.size();i++)
        {
            unordered_set<int> ors_ending_here;
            ors_ending_here.insert(nums[i]);
            for(auto ele:ors)
                ors_ending_here.insert(nums[i] & ele);
            for(auto x:ors_ending_here)
                ans=min(ans, abs(target-x));
            ors=ors_ending_here;
        }
        return ans;
    }
};