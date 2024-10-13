class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i][0], {i, 0}});
            mini=min(mini, nums[i][0]);
            maxi=max(maxi, nums[i][0]);
        }
        int a=mini, b=maxi;
        while(!pq.empty())
        {
            auto curr=pq.top();
            pq.pop();
            if(curr.second.second+1<nums[curr.second.first].size())
            {
                int r=curr.second.first, c=curr.second.second+1;
                pq.push({nums[r][c], {r, c}});
                mini=pq.top().first;
                maxi=max(maxi, nums[r][c]);
                if(b-a>maxi-mini)
                {
                    a=mini;
                    b=maxi;
                }
            }
            else
                break;
        }
        return {a, b};
    }
};