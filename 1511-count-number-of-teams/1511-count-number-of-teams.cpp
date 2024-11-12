class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<vector<int>> dpi(n, vector<int>(4,0));
        vector<vector<int>> dpd(n, vector<int>(4,0));
        for(int i=0;i<n;++i) 
            dpi[i][3] = dpd[i][3] = 1;
        for(int cnt=2; cnt>0; --cnt) {
            for(int idx=0; idx<n; ++idx) {
                int res1 = 0, res2 = 0;
                for(int i=idx+1; i<n; ++i) {
                    if(rating[i] > rating[idx]) 
                        res1 += dpi[i][cnt+1];
                    if(rating[i] < rating[idx])
                        res2 += dpd[i][cnt+1];
                }
                dpi[idx][cnt] = res1;
                dpd[idx][cnt] = res2;
            }
        }
        int res = 0;
        for(int i=0; i<n; ++i) {
            res += dpi[i][1];
            res += dpd[i][1];
        }
        return res;
    }
};