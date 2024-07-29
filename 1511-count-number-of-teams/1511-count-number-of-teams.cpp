class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), res = 0;
        set<int> lset, rset(rating.begin(), rating.end());
        for(int i=1;i<n;i++)
        {
            lset.insert(rating[i-1]);
            rset.erase(rating[i-1]); 
            int d1 = distance(lset.cbegin(), lset.lower_bound(rating[i]));
            int d2 = distance(rset.upper_bound(rating[i]), rset.cend());
            if(d1 > 0 && d2 > 0)
                res += d1*d2;
            int d3 = distance(lset.upper_bound(rating[i]), lset.cend());
            int d4 = distance(rset.cbegin(), rset.lower_bound(rating[i]));
            if(d3 > 0 && d4 > 0)
                res += d3*d4;     
        }
        return res;
    }
};