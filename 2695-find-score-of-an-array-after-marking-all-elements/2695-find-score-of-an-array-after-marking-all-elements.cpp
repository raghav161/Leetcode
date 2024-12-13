class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        map<int,int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<n;i++)
            pq.push({nums[i], i});
        while(pq.size())
        {
            int p=pq.top().second;
            if(mp.find(p)!=mp.end())
                pq.pop();
            else
            {
                sum+=pq.top().first;
                mp[p]++;
                if(p!=0)
                    mp[p-1]++;
                if(p!=n-1)
                    mp[p+1]++;
            }
        } 
        return sum;
    }
};