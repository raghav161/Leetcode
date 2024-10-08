class Solution {
public:
    bool f(long long t, int h, vector<int>& wt){
        long long totalH = 0;
        for(auto w:wt)
        {
            long long left=0, right=1e6;
            while(left<=right)
            {
                long long mid = left + (right - left) / 2;
                if(w*mid*(mid+1)/2>t)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            totalH+=right;
            if(totalH>=h)
                return true;
        }
        return totalH >= h;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low=0, high=1e18;
        while(low<=high)
        {
            long long mid=low + (high-low)/2;
            if(f(mid, mountainHeight, workerTimes))
                high = mid-1;
            else
                low = mid+1;
        }
        return high+1;
    }
};