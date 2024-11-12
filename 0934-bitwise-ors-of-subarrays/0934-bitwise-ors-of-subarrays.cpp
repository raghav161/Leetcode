class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        unordered_set<int> ors, ans;
        for(int i=0;i<nums.size();i++)
        {
            unordered_set<int> ors_ending_here;
            ors_ending_here.insert(nums[i]);
            for(auto ele:ors)
                ors_ending_here.insert(nums[i] | ele);
            for(auto x:ors_ending_here)
                ans.insert(x);
            ors=ors_ending_here;
        }
        return ans.size();
    }
};