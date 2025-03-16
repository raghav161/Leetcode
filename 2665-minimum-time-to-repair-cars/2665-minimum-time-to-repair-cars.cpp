class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low=0, high=1e14;
        while(low<high)
        {
            long long mid=(low+high)/2, count=0;
            for(int i=0;i<ranks.size();i++)
                count+=sqrt(mid/ranks[i]);
            if(cars<=count) 
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};