class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        if(a.first!=b.first)
            return a.first>b.first;
        return a.second>b.second;
    }
    long long minimumCost(int rows, int cols, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<pair<int, int>> ans;
        for(int i=0;i<verticalCut.size();i++)
            ans.push_back({verticalCut[i], -1});
        for(int i=0;i<horizontalCut.size();i++)
            ans.push_back({horizontalCut[i], 1});
        sort(ans.begin(), ans.end(), cmp);
        long long sum=0, hori=1, vert=1;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i].second==1)
            {
                sum +=static_cast<long long>(ans[i].first)*hori;
                vert++;
            }
            else
            {
                sum += static_cast<long long>(ans[i].first)*vert;
                hori++;
            }
        }
        return sum;
    }
};
