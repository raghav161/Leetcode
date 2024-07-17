class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        priority_queue<int> pq;
        long long sum=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            pq.push(nums[i]);
            sum+=nums[i];
        }
        int ans=0;
        while(target)
        {
            int front = pq.top();
            sum-=front;
            pq.pop();
            if(front<=target)
                target-=front;
            else if(front>target && sum<target){
                ans++;
                sum+=front;
                pq.push(front/2);
                pq.push(front/2);
            }
            if(pq.empty() && target!=0)
                return -1;
        }
        return ans;
    }
};