class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k){
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        long long sum=0, ans=INT_MAX;
        for(long long i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>=k)
                ans=min(ans, i+1);
            while(!pq.empty() and (sum-pq.top().first)>=k)
            {
                ans=min(ans, i-pq.top().second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return ans==INT_MAX?-1:ans;
    }
};