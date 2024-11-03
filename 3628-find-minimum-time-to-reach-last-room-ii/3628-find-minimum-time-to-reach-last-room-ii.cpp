class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(moveTime.size(), vector<int>(moveTime[0].size(), INT_MAX));
        dist[0][0]=0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            int t=pq.top().first, row=pq.top().second.first, col=pq.top().second.second;
            pq.pop();
            if(row==moveTime.size()-1 && col==moveTime[0].size()-1) 
                return t;
            vector<int> dr={1, 0, -1, 0, 1};
            for(int i=0;i<4;i++)
            {
                int n_row=row+dr[i], n_col=col+dr[i+1];
                if(n_row>=0 && n_row<moveTime.size() && n_col>=0 && n_col<moveTime[0].size())
                {
                    int diff=max(t, moveTime[n_row][n_col])+2-(n_row+n_col)%2;    
                    if(diff<dist[n_row][n_col])
                    {
                        dist[n_row][n_col]=diff;
                        pq.push({diff, {n_row, n_col}});
                    }
                }
            }
        }
        return -1;
    }
};