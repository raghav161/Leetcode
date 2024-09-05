class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for(int i=0;i<bookings.size();i++)
        {
            int l=bookings[i][0]-1, r=bookings[i][1]-1;
            for(int j=l;j<=r;j++)
                ans[j]+=bookings[i][2];
        }
        return ans;
    }
};