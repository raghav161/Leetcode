class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n);
        for(auto it:bookings)
        {
            res[it[0]-1]+=it[2];
            if(it[1]<n)
                res[it[1]]-=it[2];
        }
        for(int i=1;i<n;i++)
            res[i]+=res[i-1];
        return res;
    }
};