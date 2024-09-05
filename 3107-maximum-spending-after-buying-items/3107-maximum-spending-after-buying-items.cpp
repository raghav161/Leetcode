class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long ans = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i=0;i<values.size();i++)
            pq.push({values[i][values[0].size()-1], {i, values[0].size()-1}});
        int d=1;
        while(!pq.empty()){
            int i = pq.top().second.first; 
            int j = pq.top().second.second; 
            ans += ((long long)d*pq.top().first);
            d++;
            pq.pop(); 
            if(j!=0)
                pq.push({values[i][j-1], {i, j-1}});
        }
        return ans; 
    }
};