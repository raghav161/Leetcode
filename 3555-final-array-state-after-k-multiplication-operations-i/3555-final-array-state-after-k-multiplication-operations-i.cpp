class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<nums.size();i++)
            pq.push({nums[i], i});
        while(k--)
        {
            auto x=pq.top();
            pq.pop();
            pq.push({x.first*multiplier, x.second});
        }
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            nums[x.second]=x.first;
        }
        return nums;
    }
};