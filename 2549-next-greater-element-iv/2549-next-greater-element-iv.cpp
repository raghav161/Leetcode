class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        stack<int> s;
        multiset<pair<int, int>> m;
        vector<int> ans(nums.size(), -1);
        s.push(0);
        for(int i=1;i<nums.size();i++)
        {
            while(!m.empty() && nums[i] > (*m.begin()).first)
            {
                ans[(*m.begin()).second] = nums[i];
                m.erase(m.begin());
            }
            while(!s.empty() && nums[i]>nums[s.top()])
            {
                m.insert({nums[s.top()], s.top()});
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};