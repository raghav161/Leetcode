class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.rbegin(), maximumHeight.rend());
        long long sum=maximumHeight[0];
        int curr=maximumHeight[0];
        for(int i=1;i<maximumHeight.size();i++)
        {
            curr--;
            sum+=min(maximumHeight[i], curr);
            
            curr=min(maximumHeight[i], curr);
            if(curr<=0)
                return -1;
        }
        return sum;
    }
};