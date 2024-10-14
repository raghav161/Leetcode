class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> pq(begin(nums), end(nums));
        while(k-- and !pq.empty())
        {
            int n=pq.top();
            pq.pop();
            ans+=n;
            if((n+2)/3)
                pq.push((n+2)/3);
        }
        return ans;
    }
};