class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        vector<double> ans;
        double start=customers[0][0]+customers[0][1];
        ans.push_back(customers[0][1]);
        for(int i=1;i<customers.size();i++)
        {
            double a=(double)customers[i][0], b=(double)customers[i][1];
            if(a<start)
            {
                start+=b;
                ans.push_back(start-a);
            }
            else{
                ans.push_back(b);
                start=a+b;
            }
        }
        double total=0;
        for(int i=0;i<ans.size();i++)
            total+=(double)ans[i];
        return total/(ans.size());
    }
};