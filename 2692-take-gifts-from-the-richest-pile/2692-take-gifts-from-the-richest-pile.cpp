class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum=0;
        priority_queue<int> pq;
        for(auto it:gifts) 
            pq.push(it);
        while(k--)
        {
            pq.push(sqrt(pq.top()));
            pq.pop();
        }
        while(pq.size())
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};