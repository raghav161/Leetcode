class Solution {
public:
    long long f(long long T, int workerTime)
    {
        long long low = 0, high = 1e6;
        while(low < high)
        {
            long long mid = low + (high-low+1)/2;
            long long timeRequired = workerTime*mid*(mid + 1)/2;
            if(timeRequired <= T)
                low = mid;
            else
                high = mid-1;
        }
        return low;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0, high = 1e18;
        while (low < high)
        {
            long long mid = low + (high - low) / 2;
            long long totalHeightReduced = 0;
            for(auto workerTime:workerTimes)
            {
                totalHeightReduced += f(mid, workerTime);
                if(totalHeightReduced >= mountainHeight)
                    break;
            }
            if (totalHeightReduced >= mountainHeight)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};