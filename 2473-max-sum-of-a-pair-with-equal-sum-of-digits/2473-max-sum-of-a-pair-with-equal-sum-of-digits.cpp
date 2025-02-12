class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, priority_queue<int>> mp;
        for(int i=0;i<nums.size();i++)
        {
            int digitSum = 0, num=nums[i];
            while(num > 0)
            {
                digitSum += num % 10;
                num /= 10;
            }
            mp[digitSum].push(nums[i]);
        }
        int maxi=0;
        for(auto i:mp)
        {
            auto pq=i.second;
            if(pq.size()>=2)
            {
                int a=pq.top();
                pq.pop();
                int b=pq.top();
                maxi=max(maxi, a+b);
            }
        }
        if(maxi==0)
            return -1;
        return maxi;
    }
};