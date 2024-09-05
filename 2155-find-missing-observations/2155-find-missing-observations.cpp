class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int givensum=accumulate(rolls.begin(), rolls.end(), 0);
        int totn=n+rolls.size();
        int rem=totn*mean-givensum;
        vector<int> ans;
        int avg=rem/n;
        if(avg>6 or avg<=0)
            return {};
        int extra=rem%n;
        for(int i=0;i<n;i++)
        {
            int xx=0;
            if(extra>0)
            {
                xx++;
                extra--;
            }
            xx+=avg;
            if(xx<=6 and xx>0)
                ans.push_back(xx);
            else
                return {};
        }
        return ans;
    }
};