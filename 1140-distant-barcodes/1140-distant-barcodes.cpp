class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 0)
            return nums;
        unordered_map<int, int> freq;
        for(auto& it:nums)
            freq[it]++;
        priority_queue<pair<int, int>> q;
        for(auto& it:freq)
            q.push({it.second, it.first});
        nums.clear();
        while(q.top().first>0)
        {
            auto p = q.top();
            q.pop();
            nums.push_back(p.second);
            p.first--;
            auto p2 = q.top();
            q.pop();
            if(p2.first>0)
            {
                nums.push_back(p2.second);
                p2.first--;
            }
            q.push(p);
            q.push(p2);
        }
        return nums;
    }
};