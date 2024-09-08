class Solution {
public:
    bool f(vector<int>& start, int d, long long mini) {
        long long ans = start[0];
        for(int i=1;i<start.size();i++)
        {
            long long nextMin = ans + mini;
            if (nextMin > (long long)start[i] + d)
                return 0;
            ans = max((long long)start[i], nextMin);
        }
        return 1;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        long long low = 0, high = (long long)start.back() + d - (long long)start[0];
        while(low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (f(start, d, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low-1;
    }
};