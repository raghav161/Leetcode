class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<plantTime.size();i++)
            pq.push({growTime[i], plantTime[i]});
        int totalplant=0, maxi=0;
        while(!pq.empty())
        {
            totalplant+=pq.top().second;
            maxi=max(maxi, totalplant+pq.top().first);
            pq.pop();
        }
        return maxi;
    }
};