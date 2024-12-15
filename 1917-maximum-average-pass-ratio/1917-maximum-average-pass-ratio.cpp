class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto cmp = [](pair<int,int> a, pair<int, int> b){
            double ad = (a.first+1)/(double)(a.second+1) - (a.first)/(double)a.second;
            double bd = (b.first+1)/(double)(b.second+1) - (b.first)/(double)b.second;
            return ad < bd;
        };
        double ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;
        for(auto i:classes)
            pq.push({i[0], i[1]});
        while(extraStudents--)
        {
            auto cur = pq.top(); 
            pq.pop();
            pq.push({cur.first+1, cur.second+1});
        }
        while(!pq.empty())
        {
            auto cur = pq.top(); 
            pq.pop();
            ans += cur.first/(double)cur.second;
        }
        return ans/(double)classes.size();
    }
};